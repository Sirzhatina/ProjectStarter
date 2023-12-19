cmake_minimum_required(VERSION 3.28)

project(ProjectStarter 
    VERSION 0.1 
    LANGUAGES CXX 
    DESCRIPTION "Little script creating directory structure on the initial step of C++-project"
)

find_package(cxxopts REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)