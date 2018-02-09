#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/mouseevent.h>
#include <widgettoolkit/mouseeventreceiver.h>
#include <widgettoolkit/actionreceiver.h>
#include <widgettoolkit/painter.h>
#include <widgettoolkit/control.h>
#include <string>

namespace Wt {

using namespace std;

class WIDGETTOOLKIT_EXPORT PushButton : public Control, MouseEventReceiver, Painter {
public:
    PushButton(Rect rect, string text, View* parent = NULL);
    string GetText();
    void SetText(string text);

private:
    virtual void MousePress(View* sender, MouseEvent* event);
    virtual void MouseRelease(View* sender, MouseEvent* event);
    virtual void MouseMove(View* sender, MouseEvent* event);
    virtual void MouseDrag(View* sender, MouseEvent* event);
    virtual void MouseWheelUp(View* sender, MouseEvent* event);
    virtual void MouseWheelDown(View* sender, MouseEvent* event);
    virtual void Paint(View* view, SDL_Surface* destination);

private:
    string mText;
    int mButtonState;
};

}