#include <widgettoolkit/control.h>

namespace Wt {

Control::Control(Rect rect, View* parent /*= NULL*/)
    : View(rect, parent)
{
}

void Control::AddActionReceiver(ActionReceiver* receiver)
{
    mActionReceivers.push_back(receiver);
}

void Control::RemoveActionReceiver(ActionReceiver* receiver)
{
    for (unsigned int i = 0; i < mActionReceivers.size(); i++) {
        ActionReceiver* receiverToDelete = mActionReceivers.at(i);
        if (receiverToDelete == receiver) {
            mActionReceivers.erase(mActionReceivers.begin() + i);
            return;
        }
    }
}

void Control::InvokeActionReceivers(Control* sender)
{
    for (unsigned int i = 0; i < mActionReceivers.size(); i++) {
        ActionReceiver* rcv = mActionReceivers.at(i);
        rcv->ActionPerformed(sender);
    }
}

}