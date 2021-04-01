//
// Created by Черных Никита Алекандрович on 3/25/21.
//
#include "collector.h"

const long msg_type = 69420;

typedef struct {
    long mtype;
    double value;
} Message;

bool send_message(int qid, Message* msg)
{
    return msgsnd(qid, (struct msgbuf*)msg, sizeof(msg->value), 0) != -1;
}

bool rcv_message(int qid, Message* msg, long type)
{
    return msgrcv(qid, (struct msgbuf*)msg, sizeof(msg->value), type, 0) != -1;
}

total* collect_size(file* file, size_t size)
{
    if (!file) {
        return NULL;
    }

    size_t process_count = sysconf(_SC_NPROCESSORS_ONLN);
    size_t parts_count = size / process_count;
    int msg_q = msgget(IPC_PRIVATE, IPC_CREAT | 0660);
    if (msg_q == -1) {
        return NULL;
    }

    total* counted = (total*)calloc(1, sizeof(total));
    if (!counted) {
        return NULL;
    }

    int* pids = (int*)calloc(process_count, sizeof(int));
    if (!pids) {
        free(counted);

        return NULL;
    }

    storage* str = create_storage(size);
    if (str == NULL) {
        free(counted);
        free(pids);

        return NULL;
    }
    fill_storage(str, read_number, file);

    for (size_t i = 0; i < process_count; ++i) {
        pids[i] = fork();

        if (pids[i] != 0) {
            continue;
        }

        size_t storage_size = i < process_count - 1
            ? parts_count + 1
            : parts_count + size % process_count;

        storage pid_storage = { storage_size, str->points + i * parts_count };

        counted->value = calculate_storage(&pid_storage, calculate_length);
        Message msg = { msg_type, counted->value };

        if (!send_message(msg_q, &msg))
            exit(EXIT_FAILURE);

        exit(EXIT_SUCCESS);
    }

    for (size_t i = 0; i < process_count; ++i) {
        int status;
        if (waitpid(pids[i], &status, 0) != pids[i] || WEXITSTATUS(status) != 0) {
            delete_storage(&str);
            free(pids);
            free(counted);

            return NULL;
        }
    }

    for (size_t i = 0; i < process_count; ++i) {
        Message msg = { msg_type, 0 };
        if (!rcv_message(msg_q, &msg, msg_type)) {
            delete_storage(&str);
            free(pids);
            free(counted);

            return NULL;
        }

        counted->value += msg.value;
    }

    if (msgctl(msg_q, IPC_RMID, NULL) < 0) {
        printf("failed to remove query!");
        free(counted);
        counted = NULL;
    }

    free(pids);
    delete_storage(&str);

    return counted;
};
