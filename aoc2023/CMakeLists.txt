cmake_minimum_required(VERSION 3.27)
project(aoc2023 CXX)


Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 
)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.12.0
)

FetchContent_MakeAvailable(Catch2 spdlog)

include(CTest)
include(Catch)

find_package(TBB REQUIRED COMPONENTS tbb)


add_executable(aoc23 main.cc)
target_compile_features(aoc23 PRIVATE cxx_std_23)
target_link_libraries(aoc23 PRIVATE spdlog tbb)


add_executable(tests test.cc)
target_compile_features(tests PRIVATE cxx_std_23)
target_link_libraries(tests PRIVATE spdlog Catch2::Catch2WithMain tbb)

catch_discover_tests(tests)
