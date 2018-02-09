#pragma once

#define akVIEW_WILL_RESIGN_FIRSTRESPONDER 1
#define akVIEW_WILL_BECAME_FIRSTRESPONDER 2

namespace Wt {

class ViewNotificationReceiver {
public:
    virtual void ViewWillResignFirstResponder() = 0;
    virtual void ViewWillBecameFirstResponder() = 0;
};

}