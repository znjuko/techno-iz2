set(INPUT_SRC processing.h processing.c)

add_library(input_processing STATIC ${INPUT_SRC})

target_include_directories(input_processing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})