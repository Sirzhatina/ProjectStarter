#include "App.hpp"
#include <About.h>

auto main(int argc, char* argv[]) -> int
{
    App app(PROJECT_NAME, PROJECT_VERSION, PROJECT_DESCRIPTION);

    return app.run(argc, argv);
}