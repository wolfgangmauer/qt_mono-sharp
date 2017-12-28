#include "QGlueHBoxLayout.h"

GlueHBoxLayout::GlueHBoxLayout(MonoObject* thisObject, QWidget* parent) : QHBoxLayout(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueHBoxLayout::~GlueHBoxLayout()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}