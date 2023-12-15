export module proj_maker;

import cmd_parser;

export class ProjMaker
{
    ProjectVariables projVars;
public:
    void generate(int argc, char* argv[]) 
    {
        CmdParser parser{argc, argv};

        projVars = parser.parse();
    }
};