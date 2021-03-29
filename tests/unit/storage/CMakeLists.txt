file(GLOB SRCS *.cpp)

project(storage_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file
        data_storage
        gtest
        models
        length_calculator
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

configure_file(data/file.txt data/file.txt COPYONLY)
