set(LIBRARY_NAME collector_parallel)

file(GLOB SRC *.c ../collector.h)

add_library(${LIBRARY_NAME} STATIC ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../.)

target_link_libraries(${LIBRARY_NAME} PUBLIC file models data_storage length_calculator)

