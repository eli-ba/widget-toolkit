#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/mouseevent.h>
#include <widgettoolkit/keyevent.h>
#include <widgettoolkit/mouseeventreceiver.h>
#include <widgettoolkit/keyeventreceiver.h>
#include <widgettoolkit/viewnotificationreceiver.h>
#include <widgettoolkit/control.h>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

namespace Wt {

class WIDGETTOOLKIT_EXPORT TextBox : public Control, KeyEventReceiver, MouseEventReceiver, Painter, ViewNotificationReceiver {
public:
    TextBox(Rect rect, string text, View* parent = NULL);
    string GetText();
    void SetText(string text);

private:
    virtual void KeyPress(View* sender, KeyEvent* event);
    virtual void KeyRelease(View* sender, KeyEvent* event);
    virtual void TextInput(View* sender, KeyEvent* event);
    virtual void MousePress(View* sender, MouseEvent* event);
    virtual void MouseRelease(View* sender, MouseEvent* event);
    virtual void MouseMove(View* sender, MouseEvent* event);
    virtual void MouseDrag(View* sender, MouseEvent* event);
    virtual void MouseWheelUp(View* sender, MouseEvent* event);
    virtual void MouseWheelDown(View* sender, MouseEvent* event);
    virtual void Paint(View* view, SDL_Surface* destination);
    virtual void ViewWillResignFirstResponder();
    virtual void ViewWillBecameFirstResponder();

private:
    string mText;
    void* mTextBox;
};

}