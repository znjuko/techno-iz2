//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "file.h"

File* create_file_reader(const char* filename, const char* open_params)
{
    FILE* file_iterator = fopen(filename, open_params);
    if (!file_iterator) {
        return NULL;
    }

    File* file_reader = (File*)calloc(1, sizeof(File));
    if (!file_reader) {
        return NULL;
    }

    file_reader->file_iterator = file_iterator;
    return file_reader;
};

void destroy_file_reader(File** file)
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

double read_number(File* file_reader)
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
