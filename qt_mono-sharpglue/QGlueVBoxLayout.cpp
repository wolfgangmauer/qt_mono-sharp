#include "QGlueVBoxLayout.h"

GlueVBoxLayout::GlueVBoxLayout(MonoObject* thisObject, QWidget* parent) : QVBoxLayout(parent)
{
	_thisObject = thisObject;
}
