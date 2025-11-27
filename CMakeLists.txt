cmake_minimum_required(VERSION 3.24)
project(cpp_fmtlib)

set(CMAKE_CXX_STANDARD 17)

add_library(cpp_fmtlib STATIC
        fmtlib/logger.cpp
        fmtlib/logger.hpp
        fmtlib/ansi.hpp)

add_library(cpp_fmtlib::fmtlib ALIAS cpp_fmtlib)

set(FMT_MIN_VERSION 12.1.0)

function(FetchFMTLibrary)
    include(FetchContent)
    FetchContent_Declare(
            fmt
            GIT_REPOSITORY https://github.com/fmtlib/fmt
            GIT_TAG ${FMT_MIN_VERSION}
    )
    FetchContent_MakeAvailable(fmt)
endfunction()

find_package(fmt ${FMT_MIN_VERSION} CONFIG QUIET)

if (NOT fmt_FOUND)
    message(STATUS "fmt ${fmt_VERSION} >= ${FMT_MIN_VERSION} not found; fetching v${FMT_MIN_VERSION} with FetchContent")
    FetchFMTLibrary()
else ()
    message(STATUS "found fmt ${fmt_VERSION}; using system version")
endif ()

target_include_directories(cpp_fmtlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cpp_fmtlib PUBLIC fmt::fmt)