//
// Created by paccbet on 28.03.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "collector.h"
}

const char *open_params = "r";
const char *test_filename = "data/file.txt";

const double answer = 948.97;
const size_t point_counter = 8;

TEST(COLLECTOR, CALCULATE_CORRECT_RESULT) {
    FILE *reader = create_file_reader(test_filename, open_params);
    EXPECT_TRUE(reader);

    double res = collect_size(reader, point_counter);
    EXPECT_EQ(answer, int(res*100)/100.0);

    fclose(reader);
}

TEST(COLLECTOR, CALCULATE_EMPTY_FILE_SYNC) {
    double res = collect_size(nullptr, point_counter);
    EXPECT_EQ(EXECUTION_FAILED, res);
}