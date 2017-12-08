#include "QGlueHBoxLayout.h"

GlueHBoxLayout::GlueHBoxLayout(MonoObject* thisObject, QWidget* parent) : QHBoxLayout(parent)
{
	_thisObject = thisObject;
}
