cmake_minimum_required(VERSION 3.20)
project(cpp_cli_benchmark LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_cli_benchmark bench_x64.cpp)

if(MSVC)
  target_compile_options(cpp_cli_benchmark PRIVATE /W4 /utf-8)
else()
  target_compile_options(cpp_cli_benchmark PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(WIN32)
  target_link_libraries(cpp_cli_benchmark PRIVATE urlmon)
endif()
