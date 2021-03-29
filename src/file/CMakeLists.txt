set(LIBRARY_NAME file)

file(GLOB SRC *.h *.c)

add_library(${LIBRARY_NAME} STATIC ${SRC} file.h)

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


