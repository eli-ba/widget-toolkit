#include <widgettoolkit/messagebox.h>
#include <widgettoolkit/windowmanager.h>

namespace Wt {

extern WindowManager* TheWindowManager;

#define akMESSAGEBOX_WIDTH 250
#define akMESSAGEBOX_HEIGHT 80

MessageBoxActionsReceiver::MessageBoxActionsReceiver(Window* wnd)
{
    this->mWnd = wnd;
}

void MessageBoxActionsReceiver::ActionPerformed(Control* sender)
{
    mWnd->Close();
}

MessageBox::MessageBox(string title, string message, Window* parent)
{
    mMsgWnd = new Window(Rect(TheWindowManager->GetResolution().width / 2 - akMESSAGEBOX_WIDTH / 2,
                               TheWindowManager->GetResolution().height / 2 - akMESSAGEBOX_HEIGHT / 2,
                               akMESSAGEBOX_WIDTH,
                               akMESSAGEBOX_HEIGHT),
        title, WT_WS_CLOSABLE);

    mMessage = message;
    mLabel = new Label(Rect(10, 10, akMESSAGEBOX_WIDTH - 20, 25), message);

#define akMB_PUSHBUTTON_WIDTH 120
#define akMB_PUSHBUTTON_HEIGHT 30

    mButtonOK = new PushButton(Rect(akMESSAGEBOX_WIDTH / 2 - akMB_PUSHBUTTON_WIDTH / 2,
                                     akMESSAGEBOX_HEIGHT / 2 - akMB_PUSHBUTTON_HEIGHT / 2 + 15,
                                     akMB_PUSHBUTTON_WIDTH,
                                     akMB_PUSHBUTTON_HEIGHT),
        "OK");
    mButtonOK->AddActionReceiver(new MessageBoxActionsReceiver(mMsgWnd));

    mMsgWnd->AddView(mLabel);
    mMsgWnd->AddView(mButtonOK);
    mMsgWnd->SetVisible(true);
}

}