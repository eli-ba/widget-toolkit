#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/object.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/mouseevent.h>
#include <widgettoolkit/mouseeventreceiver.h>
#include <widgettoolkit/keyevent.h>
#include <widgettoolkit/keyeventreceiver.h>
#include <widgettoolkit/control.h>
#include <string>
#include <vector>

namespace Wt {

using namespace std;

class RadioButton;

class WIDGETTOOLKIT_EXPORT RadioButtonGroup : public Object {
public:
    RadioButtonGroup();
    void Add(RadioButton* radioButton);
    void Remove(RadioButton* radioButton);
    vector<RadioButton*> GetButtons();

private:
    vector<RadioButton*> mButtons;
};

class WIDGETTOOLKIT_EXPORT RadioButton : public Control, Painter, MouseEventReceiver, KeyEventReceiver {
public:
    RadioButton(Rect rect, string text, View* parent = NULL);
    void SetText(string text);
    string GetText();
    void SetSelected(bool selected);
    bool IsSelected();
    void SetGroup(RadioButtonGroup* group);

private:
    /* akMouseEventReceiver overrides */
    virtual void MousePress(View* sender, MouseEvent* event);
    virtual void MouseRelease(View* sender, MouseEvent* event);
    virtual void MouseMove(View* sender, MouseEvent* event);
    virtual void MouseDrag(View* sender, MouseEvent* event);
    virtual void MouseWheelUp(View* sender, MouseEvent* event);
    virtual void MouseWheelDown(View* sender, MouseEvent* event);
    /* akKeyEventReceiver overrides */
    virtual void KeyPress(View* sender, KeyEvent* event);
    virtual void KeyRelease(View* sender, KeyEvent* event);
    virtual void TextInput(View* sender, KeyEvent* event);
    /* akPainter overrides */
    virtual void Paint(View* view, SDL_Surface* destination);

private:
    string mText;
    int mButtonState;
    RadioButtonGroup* mGroup;
};

}