#pragma once

#include <widgettoolkit/export.h>

namespace Wt {

class WIDGETTOOLKIT_EXPORT Color {
public:
    Color();
    Color(int r, int g, int b, int a);

public:
    int r;
    int g;
    int b;
    int a;
};

}