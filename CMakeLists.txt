cmake_minimum_required(VERSION 3.0.0)
project(Photobatch VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Photobatch "Photobatch.cpp" "ArgumentParser.cpp" "ArgumentParser.h" "Utils.cpp" "Utils.h")

set_target_properties(Photobatch PROPERTIES CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_subdirectory(Unittests)

include(CPack)