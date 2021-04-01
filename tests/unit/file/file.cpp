//
// Created by paccbet on 28.03.2021.
//

#include <gtest/gtest.h>

extern "C" {
#include <stdint.h>

#include "file.h"
}

const char* open_params = "r";
const char* correct_filename = "data/file.txt";
const char* incorrect_filename = "filename.txt";

const int32_t first_file_number = 1;
const int32_t empty_number = 0;

TEST(CREATE_FILE_READER, OPEN_EXISTING_FILE)
{
    file* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);
    fclose(reader->file_iterator);
    free(reader);
}

TEST(CREATE_FILE_READER, OPEN_NOT_EXISTING_FILE)
{
    file* reader = create_file_reader(incorrect_filename, open_params);
    EXPECT_TRUE(!reader);
}

TEST(CREATE_FILE_READER, CLOSE_EXISTING_FILE)
{
    file* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);
    destroy_file_reader(&reader);
    EXPECT_TRUE(!reader);
}

TEST(CREATE_FILE_READER, CLOSE_NOT_EXISTING_FILE)
{
    file* reader = create_file_reader(incorrect_filename, open_params);
    EXPECT_TRUE(!reader);
    destroy_file_reader(&reader);
    EXPECT_TRUE(!reader);
}

TEST(READ_FILE, READ_FIRST_NUMBER_IN_EXISTING_FILE)
{
    file* reader = create_file_reader(correct_filename, open_params);
    EXPECT_TRUE(reader);

    EXPECT_EQ(first_file_number, read_number(reader));

    destroy_file_reader(&reader);
    EXPECT_TRUE(!reader);
}

TEST(READ_FILE, READ_FIRST_NUMBER_IN_NOT_EXISTING_FILE)
{
    file* reader = create_file_reader(incorrect_filename, open_params);
    EXPECT_TRUE(!reader);

    EXPECT_EQ(empty_number, read_number(reader));

    destroy_file_reader(&reader);
    EXPECT_TRUE(!reader);
}
