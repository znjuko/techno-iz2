file(GLOB SRCS *.c)

project(productivity_sync_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file models data_storage length_calculator collector input_processing
        )


file(COPY data/file.txt DESTINATION data)
