file(GLOB SRCS *.cpp)

project(file_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        file
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

configure_file(data/file.txt data/file.txt COPYONLY)

