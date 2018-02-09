#include <widgettoolkit/types.h>

namespace Wt {

Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
}

Color::Color(int r, int g, int b, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

}