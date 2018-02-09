#pragma once

#include <widgettoolkit/export.h>

namespace Wt {

class WIDGETTOOLKIT_EXPORT Point {
public:
    Point();
    Point(int x, int y);

public:
    int x;
    int y;
};

class WIDGETTOOLKIT_EXPORT Size {
public:
    Size();
    Size(int width, int height);

public:
    int width;
    int height;
};

class WIDGETTOOLKIT_EXPORT Rect {
public:
    Rect();
    Rect(int x, int y, int width, int height);
    Rect(Point location, Size size);

public:
    Point location;
    Size size;
};

//APPKIT_API akSize akMakeSize(int width, int height);
//APPKIT_API akPoint akMakePoint(int x, int y);
//APPKIT_API akRect akMakeRect(int x, int y, int width, int height);
//APPKIT_API akRect akMakeRect(akPoint location, akSize *size);

}