#include <stdlib.h>
#include <widgettoolkit/inputevent.h>

namespace Wt {

InputEvent::InputEvent()
{
    SetClassName("akInputEvent");
    mWindow = NULL;
}

void InputEvent::SetWindow(Window* wnd)
{
    mWindow = wnd;
}

void InputEvent::SetType(int type)
{
    mType = type;
}

Window* InputEvent::GetWindow()
{
    return mWindow;
}

int InputEvent::GetType()
{
    return mType;
}

}