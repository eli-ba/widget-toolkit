#include <widgettoolkit/application.h>
#include <widgettoolkit/windowmanager.h>

namespace Wt {

WindowManager* TheWindowManager = NULL;

Application::Application(const string& name)
{
    SetClassName("Application");
    TheWindowManager = new WindowManager(Size(800, 600), name);
}

Application::Application(Size size, const string& name)
{
    SetClassName("Application");
    TheWindowManager = new WindowManager(size, name);
}

int Application::Run()
{
    bool run = true;

    do {
        TheWindowManager->ProcessEvents();
    } while (run);

    return 0;
}

}