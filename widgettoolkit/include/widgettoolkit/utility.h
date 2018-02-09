#pragma once

#include <widgettoolkit/geometry.h>

namespace Wt {

class Utility {
public:
    static bool BitTest(long value, int bitIndex);
    static bool RectContainsPoint(Rect rect, Point point);
};

}