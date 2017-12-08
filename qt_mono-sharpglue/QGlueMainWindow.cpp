#include "QGlueMainWindow.h"

GlueMainWindow::GlueMainWindow(MonoObject* thisObject, QWidget *parent, Qt::WindowFlags flags) 
	: QMainWindow(parent, flags)
{
	_thisObject = thisObject;
//	_klass = mono_object_get_class (_thisObject);
//	_keyPressEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyPress", 1);
//	_keyReleaseEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyRelease", 1);
}

GlueMainWindow::~GlueMainWindow()
{
}
