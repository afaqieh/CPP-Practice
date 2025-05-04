# Set cmake version
cmake_minimum_required(VERSION 3.27)

# Set project name and language
project(exercise4 LANGUAGES CXX)

# Set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")

# Set source files
set(SRC
    src/main.cpp
    src/myClasses.cpp
)

# Create executable using the specified source files
add_executable(exercise4 ${SRC})

# Set include directories (for this target only)
target_include_directories(exercise4 PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Define required C++ standard
target_compile_features(exercise4 PUBLIC cxx_std_23)

# Set compile options, enable warnings
target_compile_options(exercise4 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
    $<$<CXX_COMPILER_ID:MSVC>: /W3>
)