#pragma once

#include <widgettoolkit/inputevent.h>
#include <widgettoolkit/basewindow.h>

namespace Wt {

class WindowManager;

class WindowInteractions {
public:
    WindowInteractions(WindowManager* wm);
    void OnInputEvent(InputEvent* evt);
    BaseWindow* GetTopLevelWindow();
    BaseWindow* GetWindowThatContainsPoint(Point point);

public:
    WindowManager* mWindowManager;
    BaseWindow* mTopLevelWindow;
    BaseWindow* mCapturedWindow;
};

}