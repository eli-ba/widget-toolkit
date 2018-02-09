#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/mouseevent.h>

namespace Wt {

class View;

class WIDGETTOOLKIT_EXPORT MouseEventReceiver {
public:
    virtual void MousePress(View* sender, MouseEvent* event) = 0;
    virtual void MouseRelease(View* sender, MouseEvent* event) = 0;
    virtual void MouseMove(View* sender, MouseEvent* event) = 0;
    virtual void MouseDrag(View* sender, MouseEvent* event) = 0;
    virtual void MouseWheelUp(View* sender, MouseEvent* event) = 0;
    virtual void MouseWheelDown(View* sender, MouseEvent* event) = 0;
};

}