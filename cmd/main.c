//
// Created by Черных Никита Алекандрович on 3/25/21.
//
#include <stdio.h>

#include "menu.h"

const char *open_params = "r";

int main() {
    int result = start_program(open_params);
    if (!result) {
        printf("error occurred!");
    } else {
        printf("correct execution");
    }
    return 0;
};