//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "menu.h"

int start_program(const char* open_params)
{
    if (!open_params) {
        printf("empty open params");
        return 0;
    }

    printf("input name of source file: ");
    char* filename = get_string();
    if (filename == NULL) {
        return 0;
    }

    size_t* count = 0;
    do {
        printf("input count of points (must be greater then 1): ");
        count = get_size();

        if (count == NULL) {
            printf("failed to get count of points; stopping execution...\n");
            free(filename);

            return 0;
        }
    } while (*count < 2);

    FILE* f_reader = create_file_reader(filename, open_params);
    if (f_reader == NULL) {
        printf("failed to open file; stopping execution...\n");
        free(filename);
        free(count);

        return 0;
    }

    total* counted = collect_size(f_reader, *count);
    if (counted == NULL) {
        printf("failed to collect total; stopping execution...\n");
        fclose(f_reader);
        free(filename);
        free(count);

        return 0;
    }

    printf("collected total length %f\n", counted->value);

    free(counted);
    fclose(f_reader);
    free(filename);
    free(count);

    return 1;
};