#include <widgettoolkit/mouseevent.h>

namespace Wt {

MouseEvent::MouseEvent()
{
    SetClassName("akMouseEvent");
    SetType(WT_INPUT_EVENT_MOUSE);
}

int MouseEvent::GetMouseEvent()
{
    return mMouseEvent;
}

int MouseEvent::GetButton()
{
    return mButton;
}

Point MouseEvent::GetLocation()
{
    return mLocation;
}

Point MouseEvent::GetLocationInWindow()
{
    return mLocationInWindow;
}

void MouseEvent::SetMouseEvent(int mouseEvent)
{
    mMouseEvent = mouseEvent;
}

void MouseEvent::SetButton(int button)
{
    mButton = button;
}

void MouseEvent::SetLocation(Point location)
{
    mLocation = location;
}

void MouseEvent::SetLocationInWindow(Point location)
{
    mLocationInWindow = location;
}

}