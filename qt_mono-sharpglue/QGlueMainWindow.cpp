#include "QGlueMainWindow.h"

GlueMainWindow::GlueMainWindow(MonoObject* thisObject, QWidget *parent, Qt::WindowFlags flags) 
	: QMainWindow(parent, flags)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueMainWindow::~GlueMainWindow()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
