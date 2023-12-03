cmake_minimum_required(VERSION 3.27)
project(aoc2023 CXX)


Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

include(CTest)
include(Catch)

add_executable(aoc23 main.cc)

add_executable(tests test.cc)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(tests)

#add_subdirectory(d1)
#add_subdirectory(d2)
#add_subdirectory(d3)
