set(LIBRARY_NAME collector_parallel)

file(GLOB SRC *.h *.c)

add_library(${LIBRARY_NAME} SHARED ${SRC})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${LIBRARY_NAME} LINK_PUBLIC file models data_storage length_calculator)

