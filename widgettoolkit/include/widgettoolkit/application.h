#pragma once

#include <widgettoolkit/export.h>
#include <widgettoolkit/geometry.h>
#include <widgettoolkit/inputevent.h>
#include <widgettoolkit/object.h>
#include <string>

namespace Wt {

using namespace std;

class WIDGETTOOLKIT_EXPORT Application : public Object {
public:
    Application(const string& name);
    Application(Size size, const string& name);
    int Run();

private:
    void DispatchEvent(InputEvent* evt);
};

}