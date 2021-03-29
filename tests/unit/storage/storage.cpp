//
// Created by paccbet on 28.03.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include "file.h"
#include "length_calculator.h"
#include "models.h"
#include "storage.h"
}

const char* open_params = "r";
const char* correct_filename = "data/file.txt";

const double first_file_number = 1;

const size_t empty_size = 0;
const size_t file_size = 4;

const Point fp = { 1, 2 };
const Point sp = { 3, 4 };
const Point tp = { 5, 6 };
const Point frp = { 7, 8 };

const Point cal_first = { 10, 10 };
const Point cal_second = { 10, 0 };
const double length = 10;
const size_t storage_size = 2;

const double empty_length = 0;

bool cmp(const Point a, const Point b) { return a.x == b.x && a.y == b.y; }

TEST(CREATE_STORAGE, CREATE_EMPTY_STORAGE)
{
    Storage* str = create_storage(empty_size);
    EXPECT_TRUE(str);
    EXPECT_TRUE(str->points);
    ASSERT_EQ(empty_size, str->size);

    free(str->points);
    free(str);
}

TEST(CREATE_STORAGE, DESTROY_EXISTING_STORAGE)
{
    Storage* str = create_storage(empty_size);
    EXPECT_TRUE(str);
    EXPECT_TRUE(str->points);
    ASSERT_EQ(empty_size, str->size);

    delete_storage(&str);
    EXPECT_TRUE(!str);
}

TEST(CREATE_STORAGE, DESTROY_EMPTY_STORAGE)
{
    Storage* str = nullptr;

    delete_storage(&str);
    EXPECT_TRUE(!str);
}

TEST(CREATE_STORAGE, FILL_STORAGE_FROM_FILE)
{
    File* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);

    Storage* str = create_storage(file_size);
    EXPECT_TRUE(str);
    EXPECT_TRUE(str->points);
    ASSERT_EQ(file_size, str->size);

    fill_storage(str, read_number, reader);
    EXPECT_TRUE(cmp(fp, str->points[0]));
    EXPECT_TRUE(cmp(sp, str->points[1]));
    EXPECT_TRUE(cmp(tp, str->points[2]));
    EXPECT_TRUE(cmp(frp, str->points[3]));

    destroy_file_reader(&reader);
    EXPECT_TRUE(!reader);
    delete_storage(&str);
    EXPECT_TRUE(!str);
}

TEST(CREATE_STORAGE, FILL_EMPTY_STORAGE_FROM_FILE)
{
    File* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);

    Storage* str = nullptr;

    fill_storage(str, read_number, reader);

    destroy_file_reader(&reader);
    EXPECT_TRUE(!reader);
}

TEST(CALCULATE_STORAGE, CALCULATE_STORAGE)
{
    Storage* str = create_storage(storage_size);
    EXPECT_TRUE(str);
    EXPECT_TRUE(str->points);
    ASSERT_EQ(storage_size, str->size);

    str->points[0] = cal_first;
    str->points[1] = cal_second;

    ASSERT_EQ(length, calculate_storage(str, calculate_length));

    delete_storage(&str);
    EXPECT_TRUE(!str);
}

TEST(CALCULATE_STORAGE, CALCULATE_EMPTY_STORAGE)
{
    Storage* str = nullptr;

    ASSERT_EQ(empty_length, calculate_storage(str, calculate_length));
}