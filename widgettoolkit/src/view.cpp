#include <widgettoolkit/view.h>
#include <widgettoolkit/basewindow.h>
#include <widgettoolkit/window.h>
#include <widgettoolkit/utility.h>
#include <iostream>

namespace Wt {

Color View::mFocusColor = Color(153, 217, 234, 0);
Color View::mLostFocusColor = Color(255, 255, 255, 0);

View::View()
{
    SetClassName("akView");
    mRect = Rect(0, 0, 0, 0);
    mParent = NULL;
}

View::View(Rect rect, View* parent /* = NULL*/)
{
    mRect = rect;
    mParent = parent;
    if (mParent != NULL)
        mParent->AddChild(this);
}

void View::SetRect(Rect rect)
{
    mRect = rect;
    Repaint();
}

Rect View::GetRect()
{
    return mRect;
}

Color View::GetFocusColor()
{
    return mFocusColor;
}

Color View::GetLostFocusColor()
{
    return mLostFocusColor;
}

void View::SetFocusColor(Color c)
{
    mFocusColor = c;
}

void View::SetLostFocusColor(Color c)
{
    mLostFocusColor = c;
}

void View::AddChild(View* view)
{
    mChildren.push_back(view);
    view->SetWindow(mWindow);
}

View* View::RemoveChild(View* view)
{
    for (unsigned int i = 0; i < mChildren.size(); i++) {
        View* viewToRemove = mChildren.at(i);
        if (view == viewToRemove) {
            mChildren.erase(mChildren.begin() + i);
            viewToRemove->SetWindow(NULL);
            return viewToRemove;
        }
    }
    return NULL;
}

Window* View::GetWindow()
{
    return mWindow;
}

void View::SetWindow(Window* wnd)
{
    mWindow = wnd;
}

void View::Repaint()
{
    if (!mWindow)
        return;

    BaseWindow* baseWnd = (BaseWindow*)mWindow->mBaseWindow;

    SDL_Surface* destination = baseWnd->GetContentSurface();

    for (unsigned int i = 0; i < mPainters.size(); i++) {
        Painter* painter = mPainters.at(i);
        painter->Paint(this, destination);
    }

    for (unsigned int i = 0; i < mChildren.size(); i++) {
        View* child = mChildren.at(i);
        child->Repaint();
    }
}

bool View::SendInputEvent(InputEvent* evt)
{
    if (evt->GetType() == WT_INPUT_EVENT_KEY) {
        KeyEvent* keyEvent = (KeyEvent*)evt;

        if (mWindow->GetFirstResponder() == this) {
            InvokeKeyEventReceivers(keyEvent);
        }

        // Send the event to children
        for (unsigned int i = 0; i < mChildren.size(); i++) {
            View* child = mChildren.at(i);
            child->SendInputEvent(evt);
        }

        return true;
    }
    else if (evt->GetType() == WT_INPUT_EVENT_MOUSE) {
        MouseEvent* mouseEvent = (MouseEvent*)evt;
        if (Utility::RectContainsPoint(mRect, mouseEvent->GetLocationInWindow())) {
            // Call mouse event receivers
            InvokeMouseEventReceivers(mouseEvent);

            // Send the event to children
            for (unsigned int i = 0; i < mChildren.size(); i++) {
                View* child = mChildren.at(i);
                child->SendInputEvent(evt);
            }
            return true;
        }
        else
            return false;
    }
    return false;
}

void View::AddPainter(Painter* painter)
{
    mPainters.push_back(painter);
}

void View::RemovePainter(Painter* painter)
{
    for (unsigned int i = 0; i < mPainters.size(); i++) {
        Painter* painterToRemove = mPainters.at(i);
        if (painterToRemove == painter) {
            mPainters.erase(mPainters.begin() + i);
            return;
        }
    }
}

void View::AddKeyEventReceiver(KeyEventReceiver* receiver)
{
    this->mKeyEventReceivers.push_back(receiver);
}

void View::RemoveKeyEventReceiver(KeyEventReceiver* receiver)
{
    for (unsigned int i = 0; i < mKeyEventReceivers.size(); i++) {
        KeyEventReceiver* rcv = mKeyEventReceivers.at(i);
        if (rcv == receiver) {
            mKeyEventReceivers.erase(mKeyEventReceivers.begin() + i);
            return;
        }
    }
}

void View::AddMouseEventReceiver(MouseEventReceiver* receiver)
{
    this->mMouseEventReceivers.push_back(receiver);
}

void View::RemoveMouseEventReceiver(MouseEventReceiver* receiver)
{
    for (unsigned int i = 0; i < mMouseEventReceivers.size(); i++) {
        MouseEventReceiver* rcv = mMouseEventReceivers.at(i);
        if (rcv == receiver) {
            mMouseEventReceivers.erase(mMouseEventReceivers.begin() + i);
            return;
        }
    }
}

void View::AddViewNotificationReceiver(ViewNotificationReceiver* receiver)
{
    this->mViewNotificationReceivers.push_back(receiver);
}

void View::RemoveViewNotificationReceiver(ViewNotificationReceiver* receiver)
{
    for (unsigned int i = 0; i < mViewNotificationReceivers.size(); i++) {
        ViewNotificationReceiver* rcv = mViewNotificationReceivers.at(i);
        if (rcv == receiver) {
            mViewNotificationReceivers.erase(mViewNotificationReceivers.begin() + i);
            return;
        }
    }
}

void View::InvokeKeyEventReceivers(KeyEvent* event)
{
    for (unsigned int i = 0; i < mKeyEventReceivers.size(); i++) {
        KeyEventReceiver* rcv = mKeyEventReceivers.at(i);
        if (event->GetKeyEvent() == WT_KEY_EVENT_PRESS)
            rcv->KeyPress(this, event);
        else if (event->GetKeyEvent() == WT_KEY_EVENT_RELEASE)
            rcv->KeyRelease(this, event);
        else if (event->GetKeyEvent() == WT_KEY_EVENT_TEXT)
            rcv->TextInput(this, event);
    }
}

void View::InvokeMouseEventReceivers(MouseEvent* event)
{
    for (unsigned int i = 0; i < mMouseEventReceivers.size(); i++) {
        MouseEventReceiver* rcv = mMouseEventReceivers.at(i);
        if (event->GetMouseEvent() == WT_MOUSE_EVENT_PRESS)
            rcv->MousePress(this, event);
        else if (event->GetMouseEvent() == WT_MOUSE_EVENT_RELEASE)
            rcv->MouseRelease(this, event);
        else if (event->GetMouseEvent() == WT_MOUSE_EVENT_MOVE)
            rcv->MouseMove(this, event);
        else if (event->GetMouseEvent() == WT_MOUSE_EVENT_DRAG)
            rcv->MouseDrag(this, event);
        else if (event->GetMouseEvent() == WT_MOUSE_EVENT_WHEEL_UP)
            rcv->MouseWheelUp(this, event);
        else if (event->GetMouseEvent() == WT_MOUSE_EVENT_WHEEL_DOWN)
            rcv->MouseWheelDown(this, event);
    }
}

void View::InvokeViewNotificationEventReceivers(int notification)
{
    for (int i = 0; i < mViewNotificationReceivers.size(); i++) {
        ViewNotificationReceiver* rcv = mViewNotificationReceivers.at(i);
        if (notification == akVIEW_WILL_BECAME_FIRSTRESPONDER)
            rcv->ViewWillBecameFirstResponder();
        else if (notification == akVIEW_WILL_RESIGN_FIRSTRESPONDER)
            rcv->ViewWillResignFirstResponder();
    }
}

void View::SetTag(int tag)
{
    mTag = tag;
}

int View::GetTag()
{
    return mTag;
}

View::~View()
{
    mChildren.clear();
}

}