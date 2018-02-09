#pragma once

#include <widgettoolkit/export.h>

namespace Wt {

class Control;

class WIDGETTOOLKIT_EXPORT ActionReceiver {
public:
	virtual void ActionPerformed(Control* sender) = 0;
};

}