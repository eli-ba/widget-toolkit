#include <widgettoolkit/label.h>
#include <widgettoolkit/window.h>
#include <widgettoolkit/resources.h>
#include <SDL_ttf.h>

namespace Wt {

Label::Label(Rect rect, string text, View* parent /*= NULL*/)
    : Control(rect, parent)
{
    mText = text;
    AddPainter(this);
}

void Label::SetText(string text)
{
    mText = text;
    GetWindow()->Repaint();
}

string Label::GetText()
{
    return mText;
}

void Label::Paint(View* view, SDL_Surface* destination)
{
    SDL_Color blackColor;
    blackColor.r = blackColor.g = blackColor.b = 0;
    mTextSurface = TTF_RenderText_Blended(Resources::GetFontResource(DEFAULT_FONT), mText.c_str(), blackColor);

    Rect viewRect = GetRect();
    SDL_Rect dstrect;
    dstrect.x = viewRect.location.x;
    dstrect.y = viewRect.location.y;
    dstrect.w = mTextSurface->w;
    dstrect.h = mTextSurface->h;
    SDL_BlitSurface(mTextSurface, NULL, destination, &dstrect);

    SDL_FreeSurface(mTextSurface);
}

}