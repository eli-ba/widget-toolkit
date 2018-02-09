#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/view.h>
#include <widgettoolkit/actionreceiver.h>
#include <vector>

namespace Wt {

class WIDGETTOOLKIT_EXPORT Control : public View {
public:
    Control(Rect rect, View* parent = NULL);
    void AddActionReceiver(ActionReceiver* receiver);
    void RemoveActionReceiver(ActionReceiver* receiver);
    void InvokeActionReceivers(Control* sender);

private:
    vector<ActionReceiver*> mActionReceivers;
};

}