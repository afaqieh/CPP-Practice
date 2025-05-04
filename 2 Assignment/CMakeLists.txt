# Set cmake version
cmake_minimum_required(VERSION 3.27)

# Set Name of project and language
project(exercise2 LANGUAGES CXX)

# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

# Define the variable BEFORE using it
set(exercise2 "exercise2") 

# Create executable using the specified src
add_executable(${exercise2} main.cpp calculator.cpp)

# Define required c++ standard
target_compile_features(${exercise2} PUBLIC cxx_std_23)

# Set compile options, enable warnings
target_compile_options(${exercise2} PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
    $<$<CXX_COMPILER_ID:MSVC>: /W3>
)

