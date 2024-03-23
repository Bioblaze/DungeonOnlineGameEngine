# Example CMakeLists.txt for the Editor directory

# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Folders's name
project(Core)

# Add source files
set(SOURCE_FILES
    # List other source files here
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add executable for the project
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link libraries
target_link_libraries(${PROJECT_NAME}
    # Add other libraries this subproject needs
)
