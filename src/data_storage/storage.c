//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "storage.h"

storage* create_storage(size_t size)
{
    storage* storage = (storage*)calloc(1, sizeof(storage));
    if (!storage) {
        return NULL;
    }
    storage->size = size;
    storage->points = (point*)calloc(size, sizeof(point));
    if (!storage->points) {
        return NULL;
    }

    return storage;
}

void fill_storage(storage* storage, int32_t (*read_number)(file*),
    file* file_reader)
{
    if (!storage || !file_reader) {
        return;
    }

    for (size_t i = 0; i < storage->size; ++i) {
        storage->points[i].x = (*read_number)(file_reader);
        storage->points[i].y = (*read_number)(file_reader);
    }
}

double calculate_storage(storage* storage,
    double (*cal)(const point* a, const point* b))
{
    if (!storage) {
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < storage->size - 1; ++i)
        total += (*cal)(&storage->points[i], &storage->points[i + 1]);

    return total;
}

void delete_storage(storage** storage)
{
    if (!(*storage)) {
        return;
    }

    free((*storage)->points);
    free(*storage);
    (*storage) = NULL;
}