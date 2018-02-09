#pragma once

#include <widgettoolkit/export.h>
#include <string>

namespace Wt {

using namespace std;

class WIDGETTOOLKIT_EXPORT Object {
public:
    Object();
    void SetClassName(string className);
    string GetClassName();

private:
    string mClassName;
};

}