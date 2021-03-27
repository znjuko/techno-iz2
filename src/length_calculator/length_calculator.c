//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "length_calculator.h"

double calculate_length(const Point *a, const Point *b) {
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
};