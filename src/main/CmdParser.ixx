export module cmd_parser;

import <map>;
import <string>;
import <filesystem>;
import <functional>;
import <vector>;

using Options = std::pair<std::string, std::string>;

using OptionCallback = std::map<Options, std::function<void(std::string)>>;


export struct ProjectVariables
{
    std::string projectName;
    std::string cmakeVersion;
    std::string cppStandard;
};

export class CmdParser
{
//    static inline OptionCallback opts
//    {
//         {{"--project-name", "-pn"},},
//         {{"--cmake-version", "-cv"},},
//         {{"--cxx-standard", "-std"},}
//    };

    int m_argc;
    char** m_argv;

public:
    CmdParser(int argc, char* argv[]): m_argc{argc}, m_argv{argv}
    {
    }
    ProjectVariables parse()
    {
        for (int i = 1; i < m_argc; ++i)
        {

        }
    }
};

/* 
Possible options

--project-name name | -pn name
--cmake-version x.y[.z] | -cv x.y[.z]
--std number
--lang [C | CXX] | -l [C | CXX]


Grammar:

    Arguments:
        Option [Option...]
    Option:
        --key=value
        --key value
        -k=value
        -k value
    key:
        project-name
        cmake-version
        cxx-standard
    k:
        pn
        cv
        std
    value:
        arbitrary_string

 */