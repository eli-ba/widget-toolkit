#include "sample1.h"

Demo::Demo(const string& name)
    : Application(name)
{
    mWnd = new Window(Rect(100, 50, 200, 355), "Sample", WT_WS_CLOSABLE);

    mTextBox1 = new TextBox(Rect(20, 20, 150, 25), "");
    mListBox1 = new ListBox(Rect(20, 50, 150, 200));
    mButton1 = new PushButton(Rect(20, 255, 150, 30), "Add");

    mButton1->AddActionReceiver(this);

    mWnd->AddView(mTextBox1);
    mWnd->AddView(mListBox1);
    mWnd->AddView(mButton1);

    mWnd->SetVisible(true);
}

void Demo::ActionPerformed(Control* sender)
{
    mListBox1->AddItem(mTextBox1->GetText());
}

int main(int argc, char** argv)
{
    Demo* app = new Demo("Sample Application");
    return app->Run();
}
