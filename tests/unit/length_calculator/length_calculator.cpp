//
// Created by paccbet on 28.03.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "length_calculator.h"
#include "models.h"
#include <stdint.h>
}

const int32_t first_x = 10;
const int32_t first_y = 10;
const int32_t second_x = 0;
const int32_t second_y = 10;
const int32_t expect_correct_length = 10;
const int32_t expect_zero_length = 0;

TEST(CALCULATE_LENGTH, CORRECT_VALUES)
{
    point first = { first_x, first_y };
    point second = { second_x, second_y };
    EXPECT_EQ(expect_correct_length, calculate_length(&first, &second));
}

TEST(CALCULATE_LENGTH, ONE_EMPTY_VALUE)
{
    point first = { first_x, first_y };
    point* second = nullptr;
    EXPECT_EQ(expect_zero_length, calculate_length(&first, second));
}