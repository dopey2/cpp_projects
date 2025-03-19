cmake_minimum_required(VERSION 3.10)

# Project name
project(GameApp VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories if needed
# target_include_directories(${PROJECT_NAME} PRIVATE include)

# If you need to link any libraries later
# target_link_libraries(${PROJECT_NAME} PRIVATE some_library)