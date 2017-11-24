#include "QGlueMainWindow.h"

GlueMainWindow::GlueMainWindow(MonoObject* thisObject, GlueWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags)
{
	_thisObject = thisObject;
//	_klass = mono_object_get_class (_thisObject);
//	_keyPressEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyPress", 1);
//	_keyReleaseEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyRelease", 1);
}

GlueMainWindow::~GlueMainWindow()
{
}

void GlueMainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
	if (GlueWidget::dokeyPressEvent(_thisObject, keyEvent) == -1)
		QMainWindow::keyPressEvent(keyEvent); // base class implementation
}

void GlueMainWindow::keyReleaseEvent(QKeyEvent *keyEvent)
{
	if (GlueWidget::dokeyReleaseEvent(_thisObject, keyEvent) == -1)
		QMainWindow::keyReleaseEvent(keyEvent);
}
