file(GLOB SRCS *.cpp)

project(length_calculator_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        length_calculator models
        ${GTEST_LIBRARIES}
        Threads::Threads
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})