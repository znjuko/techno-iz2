//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../collector.h"

const long msg_type = 69420;

typedef struct {
    long mtype;
    double value;
} message;

int send_message(int qid, message* msg)
{
    return msgsnd(qid, (struct msgbuf*)msg, sizeof(msg->value), 0) != -1;
}

ssize_t receive_message(int qid, message* msg, long type)
{
    return msgrcv(qid, (struct msgbuf*)msg, sizeof(msg->value), type, 0);
}

double collect_size(FILE* file, size_t size)
{
    if (!file) {
        return EXECUTION_FAILED ;
    }

    size_t process_count = sysconf(_SC_NPROCESSORS_ONLN);
    size_t parts_count = size / process_count;
    int msg_q = msgget(IPC_PRIVATE, IPC_CREAT | 0660);
    if (msg_q == -1) {
        return EXECUTION_FAILED;
    }

    int* pids = (int*)calloc(process_count, sizeof(int));
    if (!pids) {
        return EXECUTION_FAILED;
    }

    storage str = create_storage(size);
    if (!str.points) {
        free(pids);

        return EXECUTION_FAILED;
    }
    fill_storage(&str, read_number, file);

    for (size_t i = 0; i < process_count; ++i) {
        pids[i] = fork();

        if (pids[i] == -1) {
            return EXECUTION_FAILED;
        }

        if (pids[i] != 0) {
            continue;
        }

        size_t storage_size = i < process_count - 1
            ? parts_count + 1
            : parts_count + size % process_count;

        storage pid_storage = { storage_size, str.points + i * parts_count };

        double value = calculate_storage(&pid_storage, calculate_length);
        message msg = {msg_type, value };

        if (send_message(msg_q, &msg) == -1)
            exit(EXIT_FAILURE);

        exit(EXIT_SUCCESS);
    }

    for (size_t i = 0; i < process_count; ++i) {
        int status;
        if (waitpid(pids[i], &status, 0) != pids[i] || WEXITSTATUS(status) != 0) {
            delete_storage(&str);
            free(pids);

            return EXECUTION_FAILED;
        }
    }

    double value = 0;
    for (size_t i = 0; i < process_count; ++i) {
        message msg = {msg_type, 0 };
        if (receive_message(msg_q, &msg, msg_type) == -1) {
            delete_storage(&str);
            free(pids);

            return EXECUTION_FAILED;
        }

        value += msg.value;
    }

    if (msgctl(msg_q, IPC_RMID, NULL) < 0) {
        printf("failed to remove query!");
    }

    free(pids);
    delete_storage(&str);

    return value;
};
