cmake_minimum_required(VERSION 3.0)
project(DungeonEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Retrieve the VCPKG_ROOT from environment variable and set the CMAKE_TOOLCHAIN_FILE
set(VCPKG_ROOT $ENV{VCPKG_ROOT} CACHE STRING "Vcpkg root directory")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

# Find packages
find_package(assimp CONFIG REQUIRED)
find_package(sml CONFIG REQUIRED)
find_package(Bullet CONFIG REQUIRED)
find_package(cereal CONFIG REQUIRED)
find_package(cpp-httplib CONFIG REQUIRED)
find_package(ENet CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(libgit2 CONFIG REQUIRED)
find_package(LuaJIT CONFIG REQUIRED)
find_package(NumCpp CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(recastnavigation CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2-image CONFIG REQUIRED)
find_package(uWebSockets CONFIG REQUIRED)

# Add your source files here
add_executable(DungeonEngine DungeonEngine/DungeonEngine.cpp)

# Link libraries
target_link_libraries(DungeonEngine PRIVATE 
    assimp::assimp
    sml
    Bullet3::Bullet3
    cereal
    cpp-httplib::cpp-httplib
    enet
    EnTT::EnTT
    glm::glm
    imgui::imgui
    jsoncpp_lib
    jsoncpp_object
    libgit2
    LuaJIT::LuaJIT
    NumCpp::NumCpp
    OpenGL::GL
    recastnavigation::Recast
    recastnavigation::Detour
    SDL2::SDL2 SDL2::SDL2main
    SDL2_image::SDL2_image
    uWebSockets
)

# Include directories, if needed
# target_include_directories(DungeonEngine PRIVATE ${YOUR_INCLUDE_DIRECTORIES})


# Add subdirectories
add_subdirectory(DungeonEngine/Editor)
add_subdirectory(DungeonEngine/Server)
add_subdirectory(DungeonEngine/Client)
add_subdirectory(DungeonEngine/Core)