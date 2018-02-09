#pragma once

#include <widgettoolkit/widgettoolkit.h>

using namespace Wt;

class Demo : public Application, ActionReceiver {
public:
    Demo(const string& name);
    virtual void ActionPerformed(Control* sender);

private:
    Window* mWnd;
    TextBox* mTextBox1;
    ListBox* mListBox1;
    PushButton* mButton1;
};
