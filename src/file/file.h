//
// Created by paccbet on 28.03.2021.
//

#ifndef TECHNO_IZ2_FILE_H
#define TECHNO_IZ2_FILE_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file_iterator;
} file;

void destroy_file_reader(file** file_reader);

int32_t read_number(file* file_reader);

file* create_file_reader(const char* filename, const char* open_params);

#endif // TECHNO_IZ2_FILE_H
