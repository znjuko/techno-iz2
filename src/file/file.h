//
// Created by paccbet on 28.03.2021.
//

#ifndef TECHNO_IZ2_FILE_H
#define TECHNO_IZ2_FILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    FILE* file_iterator;
} File;

void destroy_file_reader(File** file_reader);

double read_number(File* file_reader);

File* create_file_reader(const char* filename, const char* open_params);

#endif // TECHNO_IZ2_FILE_H
