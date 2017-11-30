#include "QGlueFrame.h"

GlueFrame::GlueFrame(MonoObject* thisObject, GlueWidget* parent) : QFrame(parent)
{
	_thisObject = thisObject;
}

