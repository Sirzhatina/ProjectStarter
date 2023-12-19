#pragma once

#include <fstream>
#include <filesystem>
#include <format>
#include "ProjectVariables.hpp"

class Generator
{
public:
    Generator(ProjectVariables pv): m_proVars{std::move(pv)} { }
    
    void generate()
    {
        cmakeGen();
        dirGen();
    }
    
private:

    void cmakeGen();
    void dirGen();

    ProjectVariables m_proVars;
};


void Generator::cmakeGen()
{
    std::ofstream of("CMakeLists.txt");

    if (!of.is_open())
    {
        throw std::ios_base::failure{"Failed attempt to open file"};
    }

    of << std::format(
        "cmake_minimum_required(VERSION {0})\n\n"
        "project({1} LANGUAGES CXX)\n\n"
        "set(CMAKE_CXX_STANDARD {2})\n"
        "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
        "set(CMAKE_CXX_EXTENSIONS OFF)\n\n"
        "add_subdirectory(src)", 
        m_proVars.m_cmakeVersion, m_proVars.m_projectName, m_proVars.m_cppStandard
    );

}

void Generator::dirGen()
{
    namespace fsys = std::filesystem;

    fsys::create_directories(R"(src\main)");
    std::ofstream fs;

    fs.open("src\\CMakeLists.txt");
    fs << "add_subdirectory(main)";
    fs.close();

    fs.open("src\\main\\CMakeLists.txt");

    fs << "set(TARGET ${CMAKE_PROJECT_NAME})\n"
          "set(SOURCES main.cpp)\n\n"
          "add_executable(${TARGET})\n\n"
          "target_sources(${TARGET} PRIVATE ${SOURCES})\n\n";
    fs.close();

    fs.open("src\\main\\main.cpp");
    fs << "\nint main(int argc, char* argv[])\n{\n\n}";
    fs.close();    

}