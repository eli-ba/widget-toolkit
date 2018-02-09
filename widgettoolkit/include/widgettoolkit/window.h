#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/basewindow.h>
#include <widgettoolkit/types.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/object.h>
#include <string>

namespace Wt {

using namespace std;

class WIDGETTOOLKIT_EXPORT Window : public Object, Painter {
public:
    Window(Rect contentRect, string title, long style);
    string GetTitle();
    Rect GetRect();
    Rect GetContentRect();
    void SetRect(Rect rect);
    void SetContentRect(Rect rect);
    bool IsVisible();
    void SetVisible(bool visible);
    void SetMaximizable(bool maximizable);
    void SetMinimizable(bool minimizable);
    void SetClosable(bool closable);
    bool IsMaximizable();
    bool IsMinimizable();
    bool IsClosable();
    void SetBackgroundColor(Color color);
    Color GetBackgroundColor();
    void Repaint();
    void AddView(View* view);
    void RemoveView(View* view);
    virtual void Paint(View* view, SDL_Surface* destination);
    View* GetFirstResponder();
    void SetFirstResponder(View* view);
    void DispatchInputEvent(InputEvent* evt);
    void SetCanReceiveMouseMoveEvents(bool receive);
    bool CanReceiveMouseMotionEvents();
    void Close();
    ~Window();

public:
    BaseWindow* mBaseWindow;
    View* mContentView;
    Color mBgColor;
    View* mFirstResponder;
    bool mCanReceiveMouseMotionEvents;
};

}