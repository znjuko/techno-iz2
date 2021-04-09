file(GLOB SRCS *.c)

project(productivity_async_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
        file models data_storage length_calculator collector_parallel input_processing
        )

file(COPY data/file.txt DESTINATION data)

