cmake_minimum_required(VERSION 3.10)

project(how_to_test_package_size)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(src)

if(ANDROID)

endif()

add_executable(main main.cpp)
target_link_libraries(main PRIVATE simple_decoder)