import proj_maker;
import utility;

auto main(int argc, char* argv[]) -> int
{
    

    if (argc < 3)
    {
        return exitMainWithFailure("The call must have at least two arguments provided, "
                                   "e.g. \"teframe project_name cmake_version\"");
    }

}

/* 
Order of the actions:
Take all arguments -> parse arguments -> set corresponding values -> generate project structure

 */