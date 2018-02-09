#include <widgettoolkit/radiobutton.h>
#include <widgettoolkit/resources.h>
#include <widgettoolkit/window.h>
#include <widgettoolkit/types.h>
#include <SDL_ttf.h>

namespace Wt {

enum RadioButtonStates {
    STATE1_RADIOBUTTON,
    STATE2_RADIOBUTTON,
    STATE3_RADIOBUTTON
};

RadioButtonGroup::RadioButtonGroup()
{
}

void RadioButtonGroup::Add(RadioButton* radioButton)
{
    radioButton->SetGroup(this);
    mButtons.push_back(radioButton);
}

void RadioButtonGroup::Remove(RadioButton* radioButton)
{
    radioButton->SetGroup(NULL);
    for (unsigned int i = 0; i < mButtons.size(); i++) {
        RadioButton* radioToRemove = mButtons.at(i);
        if (radioToRemove == radioButton) {
            mButtons.erase(mButtons.begin() + i);
            return;
        }
    }
}

vector<RadioButton*> RadioButtonGroup::GetButtons()
{
    return mButtons;
}

RadioButton::RadioButton(Rect rect, string text, View* parent)
    : Control(rect, parent)
{
    SetClassName("akRadioButton");
    mButtonState = STATE1_RADIOBUTTON;
    mText = text;
    mGroup = NULL;

    AddMouseEventReceiver(this);
    AddKeyEventReceiver(this);
    AddPainter(this);
}

void RadioButton::SetGroup(RadioButtonGroup* group)
{
    mGroup = group;
}

void RadioButton::SetText(string text)
{
    mText = text;
}

string RadioButton::GetText()
{
    return mText;
}

void RadioButton::SetSelected(bool selected)
{
    if (selected) {
        mButtonState = STATE3_RADIOBUTTON;
    }
    else {
        mButtonState = STATE1_RADIOBUTTON;
    }
    GetWindow()->Repaint();
}

bool RadioButton::IsSelected()
{
    if (mButtonState == STATE3_RADIOBUTTON)
        return true;
    else
        return false;
}

/* akMouseEventReceiver overrides */
void RadioButton::MousePress(View* sender, MouseEvent* event)
{
    if (mButtonState == STATE1_RADIOBUTTON) {
        mButtonState = STATE3_RADIOBUTTON;
        GetWindow()->SetFirstResponder(this);
        this->InvokeActionReceivers(this);

        if (mGroup) {
            vector<RadioButton*> buttons = mGroup->GetButtons();
            for (unsigned int i = 0; i < buttons.size(); i++) {
                RadioButton* radio = buttons.at(i);
                if (radio != this) {
                    radio->mButtonState = STATE1_RADIOBUTTON;
                    radio->InvokeActionReceivers(radio);
                }
            }
        }
        GetWindow()->Repaint();
    }
}

void RadioButton::MouseRelease(View* sender, MouseEvent* event)
{
}

void RadioButton::MouseMove(View* sender, MouseEvent* event)
{
}

void RadioButton::MouseDrag(View* sender, MouseEvent* event)
{
}

void RadioButton::MouseWheelUp(View* sender, MouseEvent* event)
{
}

void RadioButton::MouseWheelDown(View* sender, MouseEvent* event)
{
}

/* akKeyEventReceiver overrides */
void RadioButton::KeyPress(View* sender, KeyEvent* event)
{
}

void RadioButton::KeyRelease(View* sender, KeyEvent* event)
{
}

void RadioButton::TextInput(View* sender, KeyEvent* event)
{
}

/* akPainter overrides */
void RadioButton::Paint(View* view, SDL_Surface* destination)
{
    SDL_Color black_color = { 0, 0, 0 };
    SDL_Surface *surf = NULL, *text = NULL, *img = NULL;
    Rect viewRect = GetRect();
    int x = viewRect.location.x;
    int y = viewRect.location.y;
    int width = viewRect.size.width;
    int height = viewRect.size.height;
    SDL_Surface* radiobutton_state1 = Resources::GetImageResource(RADIOBUTTON_STATE1);
    SDL_Surface* radiobutton_state2 = Resources::GetImageResource(RADIOBUTTON_STATE2);
    SDL_Surface* radiobutton_state3 = Resources::GetImageResource(RADIOBUTTON_STATE3);

    SDL_Rect p = { x, y }, pt = { x + 5, y + 5 }, z = { 0, 0 };

    switch (mButtonState) {
    case STATE1_RADIOBUTTON:
        img = radiobutton_state1;
        break;

    case STATE2_RADIOBUTTON:
        img = radiobutton_state2;
        break;

    case STATE3_RADIOBUTTON:
        img = radiobutton_state3;
        break;

    default:
        break;
    }

    text = TTF_RenderText_Blended(Resources::GetFontResource(DEFAULT_FONT), mText.c_str(), black_color);
    //SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 255, 0, 255));
    surf = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    Color defaultBgColor = GetWindow()->GetBackgroundColor();
    SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, defaultBgColor.r, defaultBgColor.g, defaultBgColor.b));
    z.y += (height / 2) - (img->h / 2);
    z.x += 2;
    SDL_BlitSurface(img, NULL, surf, &z);
    pt.x = img->w + 9;
    pt.y = 3;
    SDL_BlitSurface(text, NULL, surf, &pt);

    SDL_Rect dstrect;
    dstrect.x = p.x;
    dstrect.y = p.y;
    SDL_BlitSurface(surf, NULL, destination, &dstrect);

    SDL_FreeSurface(surf);
    SDL_FreeSurface(text);
}

}