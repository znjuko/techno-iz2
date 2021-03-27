//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "file.h"

File *create_file_reader(const char *filename, const char *open_params) {
    FILE *file_iterator = fopen(filename, open_params);
    if (!file_iterator) {
        return NULL;
    }

    File *file_reader = (File *) calloc(1, sizeof(File));
    file_reader->file_iterator = file_iterator;

    return file_reader;
};

void destroy_file_reader(File *file_reader) {
    fclose(file_reader->file_iterator);
}

int read_number(File *file_reader) {
    int value = 0;
    int res = 0;
    do {
        res = fscanf(file_reader->file_iterator, "%1d", &value);

    } while (res != 1);
    return value;
};

void delete_file(File** file) {
    fclose((*file)->file_iterator);
    free(*file);
    file = NULL;
}
