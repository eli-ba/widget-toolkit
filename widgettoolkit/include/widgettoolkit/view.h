#pragma once

#include <stdlib.h>
#include <widgettoolkit/export.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/painter.h>
#include <widgettoolkit/inputevent.h>
#include <widgettoolkit/mouseevent.h>
#include <widgettoolkit/keyevent.h>
#include <widgettoolkit/keyeventreceiver.h>
#include <widgettoolkit/mouseeventreceiver.h>
#include <widgettoolkit/viewnotificationreceiver.h>
#include <widgettoolkit/object.h>
#include <widgettoolkit/types.h>
#include <vector>

namespace Wt {

class Window;

using namespace std;

class WIDGETTOOLKIT_EXPORT View : public Object {
public:
    View();
    View(Rect rect, View* parent = NULL);
    void SetRect(Rect rect);
    Rect GetRect();
    void AddChild(View* view);
    View* RemoveChild(View* view);
    void Repaint();
    Window* GetWindow();
    void SetWindow(Window* wnd);
    void AddPainter(Painter* painter);
    void RemovePainter(Painter* painter);
    void AddKeyEventReceiver(KeyEventReceiver* receiver);
    void RemoveKeyEventReceiver(KeyEventReceiver* receiver);
    void AddMouseEventReceiver(MouseEventReceiver* receiver);
    void RemoveMouseEventReceiver(MouseEventReceiver* receiver);
    void AddViewNotificationReceiver(ViewNotificationReceiver* receiver);
    void RemoveViewNotificationReceiver(ViewNotificationReceiver* receiver);
    void InvokeKeyEventReceivers(KeyEvent* event);
    void InvokeMouseEventReceivers(MouseEvent* event);
    void InvokeViewNotificationEventReceivers(int notification);
    bool SendInputEvent(InputEvent* evt);
    void SetTag(int tag);
    int GetTag();
    static Color GetFocusColor();
    static Color GetLostFocusColor();
    static void SetFocusColor(Color c);
    static void SetLostFocusColor(Color c);
    virtual ~View();

private:
    Rect mRect;
    vector<View*> mChildren;
    Window* mWindow;
    vector<KeyEventReceiver*> mKeyEventReceivers;
    vector<MouseEventReceiver*> mMouseEventReceivers;
    vector<ViewNotificationReceiver*> mViewNotificationReceivers;
    vector<Painter*> mPainters;
    int mTag;
    View* mParent;
    static Color mFocusColor;
    static Color mLostFocusColor;
};

}