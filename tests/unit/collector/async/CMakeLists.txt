file(GLOB SRCS *.cpp)

project(collector_async_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file models data_storage length_calculator collector_parallel input_processing
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

configure_file(data/file.txt data/file.txt COPYONLY)
