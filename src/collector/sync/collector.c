//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "../collector.h"

total* collect_size(FILE* file, size_t size)
{
    if (!file) {
        return NULL;
    }

    total* counted = (total*)calloc(1, sizeof(total));
    if (!counted) {
        return NULL;
    }

    storage str = create_storage(size);
    if (!str.points) {
        free(counted);

        return NULL;
    }

    fill_storage(&str, read_number, file);

    counted->value = calculate_storage(&str, calculate_length);

    delete_storage(&str);

    return counted;
};