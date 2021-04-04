set(MAIN_SRCS main.c)

add_executable(main ${MAIN_SRCS})

target_link_libraries(main PUBLIC file data_storage length_calculator input_processing)

if(parallel)
    target_link_libraries(main PUBLIC collector_parallel)
else()
    target_link_libraries(main PUBLIC collector)
endif(parallel)

install(TARGETS main DESTINATION bin)