cmake_minimum_required(VERSION 3.10)
project(leetcode_solutions)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
    add_compile_options(/fsanitize=address)
endif()

# ------------------------------------------------------------
# GoogleTest
# ------------------------------------------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ------------------------------------------------------------
# Find all problem directories
# ------------------------------------------------------------
file(GLOB PROBLEM_DIRS "problems/*")

set(PROBLEM "" CACHE STRING "Path to a single problem directory")

set(MAIN_FILE "${CMAKE_SOURCE_DIR}/main.cc")

# ------------------------------------------------------------
# Helper: build a test target for one problem
# ------------------------------------------------------------
function(add_problem_test problem_dir)
    get_filename_component(problem_name ${problem_dir} NAME)

    # Find all .cc files in the folder
    file(GLOB all_sources "${problem_dir}/*.cc")

    add_executable(test_${problem_name}
        ${all_sources}
    )

    target_link_libraries(test_${problem_name}
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
    )

    # Include the project-wide include directory and the problem directory
    target_include_directories(test_${problem_name} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${problem_dir}
    )

    include(GoogleTest)
    gtest_discover_tests(test_${problem_name})
endfunction()

# ------------------------------------------------------------
# Build one problem or all problems
# ------------------------------------------------------------
if(PROBLEM)
    message(STATUS "Building ONLY problem: ${PROBLEM}")
    add_problem_test(${PROBLEM})
else()
    message(STATUS "No PROBLEM specified — building ALL problems")
    foreach(P ${PROBLEM_DIRS})
        add_problem_test(${P})
    endforeach()
endif()
