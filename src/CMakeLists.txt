add_library(non-executables OBJECT engine.cpp)

target_include_directories(non-executables PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(non-executables PRIVATE spdlog)

add_executable(beetchops-engine main.cpp)

target_link_libraries(beetchops-engine PRIVATE non-executables)
target_link_libraries(beetchops-engine PRIVATE spdlog)
