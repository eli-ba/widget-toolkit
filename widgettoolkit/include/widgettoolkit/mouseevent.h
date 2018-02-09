#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/constants.h>
#include <widgettoolkit/inputevent.h>
#include <widgettoolkit/geometry.h>

namespace Wt {

class WIDGETTOOLKIT_EXPORT MouseEvent : public InputEvent {
public:
    MouseEvent();
    int GetMouseEvent();
    int GetButton();
    Point GetLocation();
    Point GetLocationInWindow();
    void SetMouseEvent(int mouseEvent);
    void SetButton(int button);
    void SetLocation(Point location);
    void SetLocationInWindow(Point location);

private:
    int mMouseEvent;
    int mButton;
    Point mLocation;
    Point mLocationInWindow;
};

}