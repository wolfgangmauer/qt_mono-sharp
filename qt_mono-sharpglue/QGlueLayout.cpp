#include "QGlueLayout.h"

GlueLayout::GlueLayout(MonoObject* thisObject, GlueWidget* parent) : QLayout(parent)
{
	_thisObject = thisObject;
}
