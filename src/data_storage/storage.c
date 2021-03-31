//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "storage.h"

Storage* create_storage(size_t size)
{
    Storage* storage = (Storage*)calloc(1, sizeof(Storage));
    if (!storage) {
        return NULL;
    }
    storage->size = size;
    storage->points = (Point*)calloc(size, sizeof(Point));
    if (!storage->points) {
        return NULL;
    }

    return storage;
}

void fill_storage(Storage* storage, int32_t (*read_number)(File*),
    File* file_reader)
{
    if (!storage || !file_reader) {
        return;
    }

    for (size_t i = 0; i < storage->size; ++i) {
        storage->points[i].x = (*read_number)(file_reader);
        storage->points[i].y = (*read_number)(file_reader);
    }
}

double calculate_storage(Storage* storage,
    double (*cal)(const Point* a, const Point* b))
{
    if (!storage) {
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < storage->size - 1; ++i)
        total += (*cal)(&storage->points[i], &storage->points[i + 1]);

    return total;
}

void delete_storage(Storage** storage)
{
    if (!(*storage)) {
        return;
    }

    free((*storage)->points);
    free(*storage);
    (*storage) = NULL;
}