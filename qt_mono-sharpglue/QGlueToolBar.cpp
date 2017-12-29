#include "QGlueToolBar.h"
#include "QGlueWidget.h"

GlueToolBar::GlueToolBar(MonoObject* thisObject, QWidget* parent)
	: QToolBar(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueToolBar::~GlueToolBar()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

