#include "QGlueFrame.h"

GlueFrame::GlueFrame(MonoObject* thisObject, QWidget* parent) : QFrame(parent)
{
	_thisObject = thisObject;
}

