#include "QGlueMenu.h"
#include "QGlueWidget.h"

GlueMenu::GlueMenu(MonoObject* thisObject, QWidget* parent)
	: QMenu(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueMenu::GlueMenu(MonoObject* thisObject, const QString& text, QWidget* parent)
	: QMenu(text, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueMenu::~GlueMenu()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
