//
// Created by paccbet on 28.03.2021.
//

#include <chrono>
#include <gtest/gtest.h>

using namespace std::chrono;

extern "C" {
#include "collector.h"
}

const char* open_params = "r";
const char* test_filename = "data/file.txt";
const size_t point_size = 50000;
const size_t test_count = 40;

TEST(COLLECTOR, COUNT_TIME_SYNC)
{
    clock_t begin = clock();

    for (size_t i = 0; i < test_count; ++i) {
        File* reader = create_file_reader(test_filename, open_params);
        EXPECT_TRUE(reader);
        Total* res = collect_size(reader, point_size);
        free(res);
        destroy_file_reader(&reader);
    }

    std::cout << "time elapsed: " << (double)(clock() - begin) / (CLOCKS_PER_SEC * test_count) << std::endl;
}