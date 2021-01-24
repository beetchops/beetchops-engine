include(FetchContent)

FetchContent_Declare(
    Catch2

    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v2.13.4
)

FetchContent_MakeAvailable(Catch2)

add_executable(
    app-tests

    app_tests.cpp
    engine_tests.cpp
)

target_link_libraries(app-tests PRIVATE non-executables)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(app-tests)
