//
// Created by paccbet on 01.04.2021.
//

#include <stdio.h>
#include <time.h>

#include "collector.h"

const char* open_params = "r";
const char* test_filename = "data/file.txt";
const size_t point_size = 2000000;
const size_t test_count = 1000;

int main()
{
    clock_t begin = clock();

    for (size_t i = 0; i < test_count; ++i) {
        FILE* reader = create_file_reader(test_filename, open_params);
        if (!reader) {
            printf("failed to open file reader\n");
            return 1;
        }

        collect_size(reader, point_size);
        fclose(reader);
    }

    printf("time elapsed: %f\n", (double)(clock() - begin) / (CLOCKS_PER_SEC * test_count));

    return 0;
}