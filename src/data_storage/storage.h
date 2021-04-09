//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#ifndef TECHNO_IZ2_DSTORAGE_H
#define TECHNO_IZ2_DSTORAGE_H

#include <stdint.h>
#include <stdlib.h>

#include "file.h"
#include "models.h"
#include "storage.h"

typedef struct {
    size_t size;
    point* points;
} storage;

storage create_storage(size_t size);

void fill_storage(storage* storage, int32_t (*read_number)(FILE* file_reader),
    FILE* file_reader);

double calculate_storage(storage* storage,
    double (*cal)(const point* a, const point* b));

void delete_storage(storage* storage);

#endif // TECHNO_IZ2_DSTORAGE_H
