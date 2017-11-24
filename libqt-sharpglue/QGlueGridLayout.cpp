#include "QGlueGridLayout.h"

GlueGridLayout::GlueGridLayout(MonoObject* thisObject, GlueWidget* parent) : QGridLayout(parent)
{
	_thisObject = thisObject;
}
