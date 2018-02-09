#include <widgettoolkit/geometry.h>

namespace Wt {

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Size::Size()
{
    this->width = 0;
    this->height = 0;
}

Size::Size(int width, int height)
{
    this->width = width;
    this->height = height;
}

Rect::Rect()
{
    this->location.x = 0;
    this->location.y = 0;
    this->size.width = 0;
    this->size.height = 0;
}

Rect::Rect(int x, int y, int width, int height)
{
    this->location.x = x;
    this->location.y = y;
    this->size.width = width;
    this->size.height = height;
}

Rect::Rect(Point location, Size size)
{
    this->location = location;
    this->size = size;
}

//APPKIT_API akSize akMakeSize(int width, int height)
//{
//	akSize size;
//	size.width = width;
//	size.height = height;
//
//	return size;
//}
//
//APPKIT_API akPoint akMakePoint(int x, int y)
//{
//	akPoint point;
//	point.x = x;
//	point.y = y;
//
//	return point;
//}
//
//APPKIT_API akRect akMakeRect(int x, int y, int width, int height)
//{
//	akRect rect;
//	rect.location.x = x;
//	rect.location.y = y;
//	rect.size.width = width;
//	rect.size.height = height;
//
//	return rect;
//}
//
//APPKIT_API akRect akMakeRect(akPoint location, akSize size)
//{
//	akRect rect;
//	rect.location.x = location.x;
//	rect.location.y = location.y;
//	rect.size.width = size.width;
//	rect.size.height = size.height;
//
//	return rect;
//}

}