add_subdirectory(cgraph)

add_executable(mylib mylib-main.c)
target_link_libraries(mylib cgraph)