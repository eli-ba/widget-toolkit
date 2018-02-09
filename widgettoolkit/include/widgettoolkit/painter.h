#pragma once

#include <widgettoolkit/export.h>
#include <SDL.h>

namespace Wt {

class View;

class WIDGETTOOLKIT_EXPORT Painter {
public:
    virtual void Paint(View* view, SDL_Surface* destination) = 0;
};

}