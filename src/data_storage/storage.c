//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "storage.h"

storage create_storage(size_t size) {
    storage str = {size};
    str.points = (point *) calloc(size, sizeof(point));
    if (!str.points) {
        return str;
    }

    return str;
}

void fill_storage(storage *str, int32_t (*read_number)(FILE *),
                  FILE *file_reader) {
    if (!str || !file_reader) {
        return;
    }

    for (size_t i = 0; i < str->size; ++i) {
        str->points[i].x = (*read_number)(file_reader);
        str->points[i].y = (*read_number)(file_reader);
    }
}

double calculate_storage(storage *str,
                         double (*cal)(const point *a, const point *b)) {
    if (!str) {
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < str->size - 1; ++i)
        total += (*cal)(&str->points[i], &str->points[i + 1]);

    return total;
}

void delete_storage(storage *str) {
    if (!(str)) {
        return;
    }

    free(str->points);
    str->points = NULL;
}