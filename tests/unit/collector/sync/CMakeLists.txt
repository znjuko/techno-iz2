file(GLOB SRCS *.cpp)

project(collector_sync_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file models data_storage length_calculator collector input_processing
        ${GTEST_LIBRARIES}
        Threads::Threads
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

configure_file(data/file.txt data/file.txt COPYONLY)


