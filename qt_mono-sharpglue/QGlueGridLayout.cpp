#include "QGlueGridLayout.h"

GlueGridLayout::GlueGridLayout(MonoObject* thisObject, QWidget* parent) : QGridLayout(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueGridLayout::~GlueGridLayout()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
