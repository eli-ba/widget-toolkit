#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/keyevent.h>

namespace Wt {

class View;

class WIDGETTOOLKIT_EXPORT KeyEventReceiver {
public:
    virtual void KeyPress(View* sender, KeyEvent* event) = 0;
    virtual void KeyRelease(View* sender, KeyEvent* event) = 0;
    virtual void TextInput(View* sender, KeyEvent* event) = 0;
};

}