cmake_minimum_required(VERSION 3.19)

project(Beetchops VERSION 0.0.1)

add_compile_options(-W -Wall -Werror)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/archive")

add_executable(beetchops src/beetchops.cpp)

set_target_properties(
    beetchops PROPERTIES

    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
