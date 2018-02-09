#include <widgettoolkit/window.h>
#include <widgettoolkit/windowmanager.h>
#include <widgettoolkit/basewindow.h>
#include <iostream>

namespace Wt {

extern WindowManager* TheWindowManager;

Window::Window(Rect rect, string title, long style)
{
    mFirstResponder = NULL;
    mCanReceiveMouseMotionEvents = false;

    mBaseWindow = new BaseWindow(rect, title, style);
    mBaseWindow->Window = this;
    TheWindowManager->AddWindow(mBaseWindow);

    mContentView = new View(GetContentRect());
    mContentView->SetWindow(this);
    mContentView->AddPainter(this);
    mContentView->SetTag(0);

    mBgColor.r = 240;
    mBgColor.g = 240;
    mBgColor.b = 240;

    if (IsVisible())
        Repaint();
}

void Window::Repaint()
{
    mContentView->Repaint();
    mBaseWindow->DrawContentSurface();
    TheWindowManager->ComposeWindows();
}

void Window::Paint(View* view, SDL_Surface* destination)
{
    SDL_FillRect(destination, NULL, SDL_MapRGB(destination->format, mBgColor.r, mBgColor.g, mBgColor.b));
}

void Window::DispatchInputEvent(InputEvent* evt)
{
    mContentView->SendInputEvent(evt);
}

View* Window::GetFirstResponder()
{
    return mFirstResponder;
}

void Window::SetFirstResponder(View* view)
{
    if (mFirstResponder)
        mFirstResponder->InvokeViewNotificationEventReceivers(akVIEW_WILL_RESIGN_FIRSTRESPONDER);
    mFirstResponder = view;
    view->InvokeViewNotificationEventReceivers(akVIEW_WILL_BECAME_FIRSTRESPONDER);
}

void Window::AddView(View* view)
{
    mContentView->AddChild(view);
    view->SetWindow(this);
    this->Repaint();
}

void Window::RemoveView(View* view)
{
    mContentView->RemoveChild(view);
    view->SetWindow(NULL);
    this->Repaint();
}

string Window::GetTitle()
{
    return mBaseWindow->GetTitle();
}

Rect Window::GetRect()
{
    return mBaseWindow->GetRect();
}

Rect Window::GetContentRect()
{
    return mBaseWindow->GetContentRect();
}

void Window::SetRect(Rect rect)
{
    mBaseWindow->SetRect(rect);
    mContentView->SetRect(GetContentRect());
    Repaint();
}

void Window::SetContentRect(Rect rect)
{
    mBaseWindow->SetContentRect(rect);
    mContentView->SetRect(GetContentRect());
    Repaint();
}

bool Window::IsVisible()
{
    return mBaseWindow->IsVisible();
}

void Window::SetVisible(bool visible)
{
    mBaseWindow->SetVisible(visible);
    if (visible) {
        Repaint();
    }
}

void Window::SetMaximizable(bool maximizable)
{
    mBaseWindow->SetMaximizable(maximizable);
}

void Window::SetMinimizable(bool minimizable)
{
    mBaseWindow->SetMinimizable(minimizable);
}

void Window::SetClosable(bool closable)
{
    mBaseWindow->SetClosable(closable);
}

bool Window::IsMaximizable()
{
    return mBaseWindow->IsMaximizable();
}

bool Window::IsMinimizable()
{
    return mBaseWindow->IsMinimizable();
}

bool Window::IsClosable()
{
    return mBaseWindow->IsClosable();
}

void Window::SetBackgroundColor(Color color)
{
    mBgColor = color;
    Repaint();
}

Color Window::GetBackgroundColor()
{
    return mBgColor;
}

void Window::SetCanReceiveMouseMoveEvents(bool receive)
{
    mCanReceiveMouseMotionEvents = receive;
}

bool Window::CanReceiveMouseMotionEvents()
{
    return mCanReceiveMouseMotionEvents;
}

void Window::Close()
{
    mBaseWindow->SetNeedsToBeClosed();
}

Window::~Window()
{
    delete mContentView;
}

}