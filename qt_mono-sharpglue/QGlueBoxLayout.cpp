#include "QGlueBoxLayout.h"

GlueBoxLayout::GlueBoxLayout(MonoObject* thisObject, QBoxLayout::Direction dir, QWidget* parent) : QBoxLayout(dir, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueBoxLayout::~GlueBoxLayout()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
