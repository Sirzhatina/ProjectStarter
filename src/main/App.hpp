#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cxxopts.hpp>
#include "ProjectVariables.hpp"

class App
{

public:
    App(const char* projectName, const char* projectVersion = "", const char* projectDescription = "")
    : m_projectName{projectName}
    , m_projectVersion{projectVersion}
    , m_projectDescription{projectDescription}
    , m_options{getProjectName(), getProjectDescription()}
    {
        for (auto adder = m_options.add_options(); auto&& [option, descr, val] : m_defaultOptions)
        {
            adder(option, descr, val);
        }
    }

    int run(int argc, char* argv[])
    {
        cxxopts::ParseResult result;
        try
        {
            result = m_options.parse(argc, argv);       
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    
        m_proVars.m_projectName = result["project-name"].as<std::string>();
        m_proVars.m_cmakeVersion = result["cmake-version"].as<std::string>();
        m_proVars.m_cppStandard = result["cpp-standard"].as<std::string>();

        return 0;
    }

    std::string getProjectName() const { return m_projectName; }
    std::string getProjectVersion() const { return m_projectVersion; }
    std::string getProjectDescription() const { return m_projectDescription; }

private:

    using Options = std::vector<std::tuple<std::string, std::string, std::shared_ptr<cxxopts::Value>>>;

    static const inline Options m_defaultOptions
    {
        {"p, pn, project-name", "Project name", cxxopts::value<std::string>()},
        {"c, cv, cmake-version", "Minimum CMake version", cxxopts::value<std::string>()},
        {"s, std, cpp-standard", "Required C++ standard", cxxopts::value<std::string>()->default_value("20")}
    };

    const char* const m_projectName;
    const char* const m_projectVersion;
    const char* const m_projectDescription;

    cxxopts::Options m_options;
    ProjectVariables m_proVars;
};
