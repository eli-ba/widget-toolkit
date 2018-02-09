#include <stdlib.h>
#include <widgettoolkit/widgettoolkit.h>
#include <SDL.h>
#include <iostream>

using namespace Wt;

class MyPainter : public Painter {
    virtual void Paint(View* view, SDL_Surface* destination)
    {
        SDL_Rect dstrect;
        Rect rect = view->GetRect();
        dstrect.x = rect.location.x;
        dstrect.y = rect.location.y;
        dstrect.w = rect.size.width;
        dstrect.h = rect.size.height;
        SDL_FillRect(destination, &dstrect, SDL_MapRGB(destination->format, 255, 128, 0));
    }
};

class MyInputEventReceiver : public MouseEventReceiver {
    virtual void MousePress(View* sender, MouseEvent* event)
    {
        printf("(MyView)MousePress\n");
    }

    virtual void MouseRelease(View* sender, MouseEvent* event)
    {
        printf("(MyView)MouseRelease\n");
    }

    virtual void MouseMove(View* sender, MouseEvent* event)
    {
        printf("(MyView)MouseMove\n");
    }

    virtual void MouseDrag(View* sender, MouseEvent* event)
    {
        printf("(MyView)MouseDrag\n");
    }

    virtual void MouseWheelUp(View* sender, MouseEvent* event)
    {
        printf("(MyView)MouseWheelUp\n");
    }

    virtual void MouseWheelDown(View* sender, MouseEvent* event)
    {
        printf("(MyView)MouseWheelDown\n");
    }
};

class AnotherPainter : public Painter {
    virtual void Paint(View* view, SDL_Surface* destination)
    {
        SDL_Rect dstrect;
        Rect rect = view->GetRect();
        dstrect.x = rect.location.x;
        dstrect.y = rect.location.y;
        dstrect.w = rect.size.width;
        dstrect.h = rect.size.height;
        SDL_FillRect(destination, &dstrect, SDL_MapRGB(destination->format, 0, 128, 128));
    }
};

class AnotherInputEventReceiver : public MouseEventReceiver, public KeyEventReceiver {
    virtual void MousePress(View* sender, MouseEvent* event)
    {
        printf("(AnotherView)MousePress\n");
    }

    virtual void MouseRelease(View* sender, MouseEvent* event)
    {
        printf("(AnotherView)MouseRelease\n");
    }

    virtual void MouseMove(View* sender, MouseEvent* event)
    {
        printf("(AnotherView)MouseMove\n");
    }

    virtual void MouseDrag(View* sender, MouseEvent* event)
    {
        printf("(AnotherView)MouseDrag\n");
    }

    virtual void KeyPress(View* sender, KeyEvent* event)
    {
        printf("(AnotherView)KeyPress '%d'\n", event->GetKeycode());
    }

    virtual void TextInput(View* sender, KeyEvent* event)
    {
        printf("(AnotherView)TextInput '%s'\n", event->GetText().c_str());
    }

    virtual void KeyRelease(View* sender, KeyEvent* event)
    {
        printf("(AnotherView)KeyRelease '%d'\n", event->GetKeycode());
    }

    virtual void MouseWheelUp(View* sender, MouseEvent* event)
    {
        printf("(AnotherView)MouseWheelUp\n");
    }

    virtual void MouseWheelDown(View* sender, MouseEvent* event)
    {
        printf("(AnotherView)MouseWheelDown\n");
    }
};

class Button1ActionReceiver : public ActionReceiver {
public:
    virtual void ActionPerformed(Control* sender)
    {
        //akWindow *wnd = new akWindow(akRect(50,50,200,200), "Another window", akWS_VISIBLE|akWS_CLOSABLE);
        MessageBox("Simle title", "Simple Message but very long", NULL);
    }
};

int main(int argc, char** argv)
{
    Application* app = new Application("Sample Application");
    Window* wnd = new Window(Rect(100, 100, 400, 400), "My Window",
        WT_WS_VISIBLE | WT_WS_CLOSABLE | WT_WS_MAXIMIZABLE | WT_WS_MINIMIZABLE);

    View* view1 = new View(Rect(150, 10, 70, 70));
    view1->AddPainter(new MyPainter());
    view1->AddMouseEventReceiver(new MyInputEventReceiver());
    view1->SetTag(1);
    wnd->AddView(view1);

    View* view2 = new View(Rect(250, 10, 70, 70));
    view2->AddPainter(new AnotherPainter());
    AnotherInputEventReceiver* view2receiver = new AnotherInputEventReceiver();
    view2->AddMouseEventReceiver(view2receiver);
    view2->AddKeyEventReceiver(view2receiver);
    view2->SetTag(2);
    wnd->AddView(view2);

    PushButton* button1 = new PushButton(Rect(30, 30, 80, 35), "Button 1");
    button1->AddActionReceiver(new Button1ActionReceiver());
    wnd->AddView(button1);

    wnd->AddView(new Label(Rect(10, 100, 150, 25), "Full Name:"));
    TextBox* textbox1 = new TextBox(Rect(75, 100, 200, 25), "");
    wnd->AddView(textbox1);

    wnd->AddView(new Label(Rect(10, 140, 150, 25), "E-mail:"));
    TextBox* textbox2 = new TextBox(Rect(75, 140, 200, 25), "");
    wnd->AddView(textbox2);

    ListBox* listbox1 = new ListBox(Rect(30, 180, 150, 160));
    listbox1->AddItem("Apple");
    listbox1->AddItem("Bananas");
    listbox1->AddItem("Cocoa");
    listbox1->AddItem("Apple");
    listbox1->AddItem("Bananas");
    listbox1->AddItem("Cocoa");
    listbox1->AddItem("Apple");
    listbox1->AddItem("Bananas");
    listbox1->AddItem("Cocoa");
    listbox1->AddItem("Apple");
    listbox1->AddItem("Bananas");
    listbox1->AddItem("Cocoa");
    listbox1->AddItem("Apple");
    listbox1->AddItem("Bananas");
    listbox1->AddItem("Cocoa");
    listbox1->AddItem("Apple");
    listbox1->AddItem("Bananas");
    listbox1->AddItem("Cocoa");
    wnd->AddView(listbox1);

    RadioButton* radio1 = new RadioButton(Rect(250, 150 + 30, 150, 25), "Radio 1");
    RadioButton* radio2 = new RadioButton(Rect(250, 150 + 60, 150, 25), "Radio 2");
    RadioButton* radio3 = new RadioButton(Rect(250, 170 + 90, 150, 25), "Radio 3");
    RadioButton* radio4 = new RadioButton(Rect(250, 170 + 120, 150, 25), "Radio 4");
    wnd->AddView(radio1);
    wnd->AddView(radio2);
    wnd->AddView(radio3);
    wnd->AddView(radio4);

    RadioButtonGroup* group1 = new RadioButtonGroup;
    group1->Add(radio1);
    group1->Add(radio2);

    RadioButtonGroup* group2 = new RadioButtonGroup;
    group2->Add(radio3);
    group2->Add(radio4);

    return app->Run();
}
