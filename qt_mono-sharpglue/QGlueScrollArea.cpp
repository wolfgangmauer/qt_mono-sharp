#include "QGlueScrollArea.h"

GlueScrollArea::GlueScrollArea(MonoObject* thisObject, QWidget *parent) : QScrollArea(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueScrollArea::~GlueScrollArea()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}