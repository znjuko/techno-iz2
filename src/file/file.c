//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "file.h"

file* create_file_reader(const char* filename, const char* open_params)
{
    FILE* file_iterator = fopen(filename, open_params);
    if (!file_iterator) {
        return NULL;
    }

    file* file_reader = (file*)calloc(1, sizeof(file));
    if (!file_reader) {
        return NULL;
    }

    file_reader->file_iterator = file_iterator;
    return file_reader;
};

void destroy_file_reader(file** file)
{
    if (!*file) {
        return;
    }

    if ((*file)->file_iterator != NULL) {
        fclose((*file)->file_iterator);
    }

    free(*file);
    *file = NULL;
}

int32_t read_number(file* file_reader)
{
    if (!file_reader) {
        return 0;
    }

    double value = 0;
    int res = 0;
    do {
        res = fscanf(file_reader->file_iterator, "%lf", &value);

    } while (res != 1);

    return value;
};
