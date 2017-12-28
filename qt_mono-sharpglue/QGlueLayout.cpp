#include "QGlueLayout.h"

GlueLayout::GlueLayout(MonoObject* thisObject, GlueWidget* parent) : QLayout(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueLayout::~GlueLayout()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
