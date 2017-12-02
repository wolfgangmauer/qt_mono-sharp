#include "QGlueMainWindow.h"

GlueMainWindow::GlueMainWindow(MonoObject* thisObject, GlueWidget *parent, Qt::WindowFlags flags) 
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

void GlueMainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
	dokeyPressEvent(_thisObject, keyEvent);
}

void GlueMainWindow::keyReleaseEvent(QKeyEvent *keyEvent)
{
	dokeyReleaseEvent(_thisObject, keyEvent);
}

bool GlueMainWindow::event (QEvent* event)
{
	return doEvent(_thisObject, event);
}

void GlueMainWindow::mousePressEvent (QMouseEvent *event)
{
	doMousePressEvent(_thisObject, event);
}

void GlueMainWindow::mouseReleaseEvent (QMouseEvent *event)
{
	doMouseReleaseEvent(_thisObject, event);
}

void GlueMainWindow::mouseDoubleClickEvent (QMouseEvent *event)
{
	doMouseDoubleClickEvent(_thisObject, event);
}

void GlueMainWindow::mouseMoveEvent (QMouseEvent *event)
{
	doMouseMoveEvent(_thisObject, event);
}
