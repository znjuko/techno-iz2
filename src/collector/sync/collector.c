//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "../collector.h"

double collect_size(FILE* file, size_t size)
{
    if (!file) {
        return EXECUTION_FAILED;
    }

    storage str = create_storage(size);
    if (!str.points) {
        return EXECUTION_FAILED;
    }

    fill_storage(&str, read_number, file);

    double value = calculate_storage(&str, calculate_length);

    delete_storage(&str);

    return value;
};