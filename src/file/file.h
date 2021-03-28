//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#ifndef TECHNO_IZ2_FILE_H
#define TECHNO_IZ2_FILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE *file_iterator;
} File;

void destroy_file_reader(File *file_reader);

int read_number(File *file_reader);

int move_reader(File *file_reader, size_t offset);

File *create_file_reader(const char *filename, const char *open_params);

#endif //TECHNO_IZ2_FILE_H
