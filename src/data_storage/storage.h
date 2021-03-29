//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#ifndef TECHNO_IZ2_DSTORAGE_H
#define TECHNO_IZ2_DSTORAGE_H

#include <stdlib.h>

#include "file.h"
#include "models.h"
#include "storage.h"

typedef struct {
    size_t size;
    Point* points;
} Storage;

Storage* create_storage(size_t size);

void fill_storage(Storage* storage, double (*read_number)(File* file_reader),
    File* file_reader);

double calculate_storage(Storage* storage,
    double (*cal)(const Point* a, const Point* b));

void delete_storage(Storage** storage);

#endif // TECHNO_IZ2_DSTORAGE_H
