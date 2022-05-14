set(FETCHCONTENT_QUIET OFF CACHE BOOL "Disabilita o quiet mode do Fetch Content " FORCE)


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY      https://github.com/google/googletest.git
    GIT_TAG             release-1.10.0
)

FetchContent_MakeAvailable(googletest)

include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>

add_executable(TestArgumentParser 
    "TestArgumentParser.cpp"
    "${CMAKE_SOURCE_DIR}/ArgumentParser.cpp"
    "${CMAKE_SOURCE_DIR}/Utils.cpp"
)

target_include_directories(TestArgumentParser PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(TestArgumentParser PRIVATE gtest_main)


