#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/painter.h>
#include <widgettoolkit/control.h>
#include <string>

namespace Wt {

class WIDGETTOOLKIT_EXPORT Label : public Control, Painter {
public:
    Label(Rect rect, string text, View* parent = NULL);
    void SetText(string text);
    string GetText();

private:
    virtual void Paint(View* view, SDL_Surface* destination);

private:
    string mText;
    SDL_Surface* mTextSurface;
};

}