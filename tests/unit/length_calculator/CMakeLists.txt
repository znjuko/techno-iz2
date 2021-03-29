file(GLOB SRCS *.cpp)

project(length_calculator_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        length_calculator
        models
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})