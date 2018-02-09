#include <widgettoolkit/object.h>

namespace Wt {

Object::Object()
{
    mClassName = "akObject";
}

void Object::SetClassName(string className)
{
    mClassName = className;
}

string Object::GetClassName()
{
    return mClassName;
}

}