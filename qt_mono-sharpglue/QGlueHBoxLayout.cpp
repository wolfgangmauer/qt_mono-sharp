#include "QGlueHBoxLayout.h"

GlueHBoxLayout::GlueHBoxLayout(MonoObject* thisObject, GlueWidget* parent) : QHBoxLayout(parent)
{
	_thisObject = thisObject;
}
