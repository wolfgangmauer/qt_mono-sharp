#include "QGlueBoxLayout.h"

GlueBoxLayout::GlueBoxLayout(MonoObject* thisObject, QBoxLayout::Direction dir, GlueWidget* parent) : QBoxLayout(dir, parent)
{
	_thisObject = thisObject;
}
