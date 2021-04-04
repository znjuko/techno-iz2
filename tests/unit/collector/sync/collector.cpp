//
// Created by paccbet on 28.03.2021.
//

#include <gtest/gtest.h>

extern "C" {
    #include "collector.h"
}

const char* open_params = "r";
const char* test_filename = "data/file.txt";

const double answer = 32;
const size_t point_counter = 7;

TEST(COLLECTOR, CALCULATE_CORRECT_RESULT)
{
    FILE* reader = create_file_reader(test_filename, open_params);
    EXPECT_TRUE(reader);

    total* res = collect_size(reader, point_counter);
    EXPECT_EQ(answer, res->value);

    fclose(reader);
    free(res);
}

TEST(COLLECTOR, CALCULATE_EMPTY_FILE_SYNC)
{
    total* res = collect_size(nullptr, point_counter);
    EXPECT_TRUE(!res);
}