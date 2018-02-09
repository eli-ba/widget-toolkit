#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/constants.h>
#include <widgettoolkit/object.h>

namespace Wt {

class Window;

class WIDGETTOOLKIT_EXPORT InputEvent : public Object {
public:
    InputEvent();
    void SetWindow(Window* wnd);
    Window* GetWindow();
    void SetType(int type);
    int GetType();

private:
    Window* mWindow;
    int mType;

public:
    void* Reserved;
};

}