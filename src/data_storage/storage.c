//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "storage.h"

const int first_byte = 0;
const int second_byte = 1;
const int third_byte = 2;
const int fourth_byte = 3;

storage create_storage(size_t size) {
    storage str = {size};
    str.points = (point *) calloc(size, sizeof(point));
    if (!str.points) {
        return str;
    }

    return str;
}

int32_t get_number(int32_t value, const int pos) {
    return (value >> (8 * pos)) & 0xff;
}

void fill_storage(storage *str, int32_t (*read_number)(FILE *),
                  FILE *file_reader) {
    if (!str || !file_reader) {
        return;
    }

    for (size_t i = 0; i < str->size; i += 2) {
        int32_t value = (*read_number)(file_reader);

        str->points[i].x = get_number(value, first_byte);
        str->points[i].y = get_number(value, second_byte);

        str->points[i + 1].x = get_number(value, third_byte);
        str->points[i + 1].y = get_number(value, fourth_byte);
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