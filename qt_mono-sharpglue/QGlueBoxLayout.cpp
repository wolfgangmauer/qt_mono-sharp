#include "QGlueBoxLayout.h"

GlueBoxLayout::GlueBoxLayout(MonoObject* thisObject, QBoxLayout::Direction dir, QWidget* parent) : QBoxLayout(dir, parent)
{
	_thisObject = thisObject;
}
