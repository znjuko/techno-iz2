set(MAIN_SRCS main.c)

add_executable(main ${MAIN_SRCS})

target_link_libraries(main PRIVATE menu)

install(TARGETS main DESTINATION bin)