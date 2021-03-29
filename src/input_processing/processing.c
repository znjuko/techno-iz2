//
// Created by Черных Никита Алекандрович on 3/5/21.
//
#include "processing.h"

// я не воровал этот код !!!!
// взял из своего ИЗ1
// не снимайте баллы, пожалуйста :c
// chernyh.na

char get_char()
{
    char c = '\0';
    int result = 0;

    do {
        result = scanf("%c", &c);
    } while (result != 1);

    return c;
};

// Returns NUL on error
char* get_string()
{
    struct buffer {
        char* string;
        size_t size;
        size_t cap;
    } buf = { NULL, 0, 1 };
    char c = '\0';

    while (c = get_char(), c != EOF && c != '\n') {
        if (buf.size + 1 >= buf.cap) {
            buf.cap *= 2;
            char* tmp = (char*)malloc((buf.cap + 1) * sizeof(char));

            if (!tmp) {
                free(buf.string);
                return NULL;
            }

            if (buf.string) {
                tmp = strcpy(tmp, buf.string);
                free(buf.string);
            }

            buf.string = tmp;
        }

        buf.string[buf.size] = c;
        buf.string[buf.size + 1] = '\0';
        ++buf.size;
    }

    return buf.string;
};

size_t* get_size()
{
    char c = '\0';
    size_t* number = (size_t*)calloc(1, sizeof(size_t));
    while (c = get_char(), c != EOF && c != '\n') {
        if (c < '0' || c > '9') {
            char* trash = get_string();
            if (trash != NULL) {
                free(trash);
            }
            return NULL;
        }

        (*number) *= 10;
        (*number) += c - '0';
    }
    return number;
}
