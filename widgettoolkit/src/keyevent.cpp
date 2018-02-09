#include <widgettoolkit/keyevent.h>
#include <widgettoolkit/constants.h>

namespace Wt {

KeyEvent::KeyEvent()
{
    SetClassName("akKeyEvent");
    SetType(WT_INPUT_EVENT_KEY);
}
/*
int akKeyEvent::GetUnicode()
{
	return mUnicode;
}
*/
int KeyEvent::GetKeyEvent()
{
    return mKeyEvent;
}
/*
void akKeyEvent::SetUnicode(int unicode)
{
	mUnicode = unicode;
}
*/
void KeyEvent::SetKeyEvent(int keyEvent)
{
    mKeyEvent = keyEvent;
}

void KeyEvent::SetText(const std::string text)
{
    mText = text;
}

std::string const& KeyEvent::GetText()
{
    return mText;
}

}