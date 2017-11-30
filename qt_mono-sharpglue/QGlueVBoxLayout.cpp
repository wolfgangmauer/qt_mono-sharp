#include "QGlueVBoxLayout.h"

GlueVBoxLayout::GlueVBoxLayout(MonoObject* thisObject, GlueWidget* parent) : QVBoxLayout(parent)
{
	_thisObject = thisObject;
}
