file(GLOB SRCS *.cpp)

project(productivity_async_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file models data_storage length_calculator collector_parallel input_processing
        ${GTEST_LIBRARIES}
        Threads::Threads
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

file(COPY data/file.txt DESTINATION data)

