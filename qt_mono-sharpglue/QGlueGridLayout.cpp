#include "QGlueGridLayout.h"

GlueGridLayout::GlueGridLayout(MonoObject* thisObject, QWidget* parent) : QGridLayout(parent)
{
	_thisObject = thisObject;
}
