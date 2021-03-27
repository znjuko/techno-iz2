//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "menu.h"

int start_program(const char * open_params) {
    printf("input name of source file: ");
    char* filename = get_string();

    printf("input count of points: ");
    size_t* count = get_size();
    if(count == NULL) {
        printf("failed to get count of points; stopping execution...\n");
        return 0;
    }

    File* file = create_file_reader(filename,open_params);
    if(file == NULL) {
        printf("failed to open file; stopping execution...\n");
        return 0;
    }

    Total* total = collect_size(file, *count);
    if(total == NULL) {
        printf("failed to collect total; stopping execution...\n");
        return 0;
    }

    printf("collected total length %f", total->value);

    free(total);
    destroy_file_reader(file);

    return 1;
};