#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/geometry.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <widgettoolkit/mouseeventreceiver.h>
#include <widgettoolkit/keyeventreceiver.h>
#include <widgettoolkit/viewnotificationreceiver.h>
#include <widgettoolkit/painter.h>
#include <widgettoolkit/control.h>
#include <string>

namespace Wt {

class WIDGETTOOLKIT_EXPORT ListBox : public Control, MouseEventReceiver, KeyEventReceiver, Painter, ViewNotificationReceiver {
public:
    ListBox(Rect rect, View* parent = NULL);
    void AddItem(string text);
    void RemoveItem(int index);
    string GetItemText(int index);
    void SetItemText(int index, string text);
    int GetSelectionIndex();
    int GetItemCount();

private:
    /* akPainter overrides */
    virtual void Paint(View* view, SDL_Surface* destination);
    /* akMouseEventReceiver overrides */
    virtual void MousePress(View* sender, MouseEvent* event);
    virtual void MouseRelease(View* sender, MouseEvent* event);
    virtual void MouseMove(View* sender, MouseEvent* event);
    virtual void MouseDrag(View* sender, MouseEvent* event);
    virtual void MouseWheelUp(View* sender, MouseEvent* event);
    virtual void MouseWheelDown(View* sender, MouseEvent* event);
    /* akKeyEventEventReceiver overrides */
    virtual void KeyPress(View* sender, KeyEvent* event);
    virtual void KeyRelease(View* sender, KeyEvent* event);
    virtual void TextInput(View* sender, KeyEvent* event);
    /* akViewNotificationReceiver overrides */
    virtual void ViewWillResignFirstResponder();
    virtual void ViewWillBecameFirstResponder();

private:
    void* mListBox;
};

}