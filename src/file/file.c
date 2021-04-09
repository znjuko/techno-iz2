//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "file.h"

FILE* create_file_reader(const char* filename, const char* open_params)
{
    FILE* file_iterator = fopen(filename, open_params);
    if (!file_iterator) {
        return NULL;
    }

    return file_iterator;
};

int32_t read_number(FILE* file_reader)
{
    if (!file_reader) {
        return 0;
    }

    double value = 0;
    int res = 0;
    do {
        res = fscanf(file_reader, "%lf", &value);

    } while (res != 1);

    return value;
};
