//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "collector.h"

total* collect_size(file* file, size_t size)
{
    if (!file) {
        return NULL;
    }

    total* counted = (total*)calloc(1, sizeof(total));
    if (!counted) {
        return NULL;
    }

    storage* storage = create_storage(size);
    if (storage == NULL) {
        free(counted;

        return NULL;
    }

    fill_storage(storage, read_number, file);

    counted->value = calculate_storage(storage, calculate_length);

    delete_storage(&storage);

    return counted;
};