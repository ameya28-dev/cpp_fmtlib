cmake_minimum_required(VERSION 3.24)
project(cpp_fmtlib)

set(CMAKE_CXX_STANDARD 17)

add_library(cpp_fmtlib STATIC
        logger.cpp
        logger.hpp
        core.hpp)

include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG e69e5f977d458f2650bb346dadf2ad30c5320281
)
FetchContent_MakeAvailable(fmt)
target_link_libraries(cpp_fmtlib PRIVATE fmt::fmt)