#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/window.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/label.h>
#include <widgettoolkit/pushbutton.h>
#include <widgettoolkit/actionreceiver.h>
#include <string>

namespace Wt {

using namespace std;

class MessageBoxActionsReceiver : public ActionReceiver {
public:
    MessageBoxActionsReceiver(Window* wnd);
    virtual void ActionPerformed(Control* sender);

private:
    Window* mWnd;
};

class WIDGETTOOLKIT_EXPORT MessageBox {
public:
    MessageBox(string title, string message, Window* parent = NULL);

private:
    string mMessage;
    Label* mLabel;
    PushButton* mButtonOK;
    Window* mMsgWnd;
};

}