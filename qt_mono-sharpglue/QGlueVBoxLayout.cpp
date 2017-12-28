#include "QGlueVBoxLayout.h"

GlueVBoxLayout::GlueVBoxLayout(MonoObject* thisObject, QWidget* parent) : QVBoxLayout(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueVBoxLayout::~GlueVBoxLayout()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}