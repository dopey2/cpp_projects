cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Create library mylibA
add_library(mylibA STATIC libs/mylibA/mylibA.cpp)
target_include_directories(mylibA PUBLIC libs/mylibA)

# Create library mylibB
add_library(mylibB STATIC libs/mylibB/mylibB.cpp)
target_include_directories(mylibB PUBLIC libs/mylibB)

# Create executable main
add_executable(main src/main.cpp)

# Link main with mylibA and mylibB
target_link_libraries(main PRIVATE mylibA mylibB)

# Set output directory for executables (optional)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")