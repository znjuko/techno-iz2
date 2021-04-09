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

const point fp = { 210, 4 };
const point sp = { 0, 0 };
const point tp = { 46, 22 };
const point frp = { 0, 0};

const point cal_first = { 10, 10 };
const point cal_second = { 10, 0 };
const double length = 10;
const size_t storage_size = 2;

const double empty_length = 0;

bool cmp(const point a, const point b) { return a.x == b.x && a.y == b.y; }

TEST(CREATE_STORAGE, CREATE_EMPTY_STORAGE)
{
    storage str = create_storage(empty_size);
    EXPECT_TRUE(str.points);
    ASSERT_EQ(empty_size, str.size);

    free(str.points);
}

TEST(CREATE_STORAGE, DESTROY_EXISTING_STORAGE)
{
    storage str = create_storage(empty_size);
    EXPECT_TRUE(str.points);
    ASSERT_EQ(empty_size, str.size);

    delete_storage(&str);
    EXPECT_TRUE(!str.points);
}

TEST(CREATE_STORAGE, DESTROY_EMPTY_STORAGE)
{
    storage* str = nullptr;

    delete_storage(str);
    EXPECT_TRUE(!str);
}

TEST(CREATE_STORAGE, FILL_STORAGE_FROM_FILE)
{
    FILE* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);

    storage str = create_storage(file_size);
    EXPECT_TRUE(str.points);
    ASSERT_EQ(file_size, str.size);

    fill_storage(&str, read_number, reader);
    EXPECT_TRUE(cmp(fp, str.points[0]));
    EXPECT_TRUE(cmp(sp, str.points[1]));
    EXPECT_TRUE(cmp(tp, str.points[2]));
    EXPECT_TRUE(cmp(frp, str.points[3]));

    fclose(reader);
    delete_storage(&str);
    EXPECT_TRUE(!str.points);
}

TEST(CREATE_STORAGE, FILL_EMPTY_STORAGE_FROM_FILE)
{
    FILE* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);

    storage* str = nullptr;

    fill_storage(str, read_number, reader);

    fclose(reader);
}

TEST(CALCULATE_STORAGE, CALCULATE_STORAGE)
{
    storage str = create_storage(storage_size);
    EXPECT_TRUE(str.points);
    ASSERT_EQ(storage_size, str.size);

    str.points[0] = cal_first;
    str.points[1] = cal_second;

    ASSERT_EQ(length, calculate_storage(&str, calculate_length));

    delete_storage(&str);
    EXPECT_TRUE(!str.points);
}

TEST(CALCULATE_STORAGE, CALCULATE_EMPTY_STORAGE)
{
    storage* str = nullptr;

    ASSERT_EQ(empty_length, calculate_storage(str, calculate_length));
}