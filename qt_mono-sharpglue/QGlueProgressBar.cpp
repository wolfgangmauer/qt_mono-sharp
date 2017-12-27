#include "QGlueProgressBar.h"

GlueProgressBar::GlueProgressBar(MonoObject* thisObject, QWidget* parent)
	: QProgressBar(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueProgressBar::~GlueProgressBar()
{
	doOnRawDispose(_thisObject);
	mono_gchandle_free (_thisObject); 
}