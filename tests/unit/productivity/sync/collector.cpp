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
const size_t point_size = 4000;
const size_t test_count = 5;

TEST(COLLECTOR, COUNT_TIME_SYNC)
{
    auto start = steady_clock::now();

    for (size_t i = 0; i < test_count; ++i) {
        File* reader = create_file_reader(test_filename, open_params);
        EXPECT_TRUE(reader);
        Total* res = collect_size(reader, point_size);
        free(res);
        destroy_file_reader(&reader);
    }

    auto end = steady_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - start);

    std::cout << "time elapsed: " << elapsed.count() / test_count << std::endl;
}