#include "QGlueDialog.h"

GlueDialog::GlueDialog(MonoObject* thisObject, GlueWidget* parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	_thisObject = thisObject;
//	_klass = mono_object_get_class (_thisObject);
//	_keyPressEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyPress", 1);
//	_keyReleaseEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyRelease", 1);
//	MonoImageOpenStatus *status;
//	if(!_image)
//		_image = mono_image_open("qt-sharp.dll", status);
}

void GlueDialog::keyReleaseEvent(QKeyEvent *keyEvent)
{
	if (GlueWidget::dokeyPressEvent(_thisObject, keyEvent) == -1)
		QDialog::keyPressEvent(keyEvent); // base class implementation
}

void GlueDialog::keyPressEvent(QKeyEvent *keyEvent)
{
	if (GlueWidget::dokeyReleaseEvent(_thisObject, keyEvent) == -1)
		QDialog::keyReleaseEvent(keyEvent);
}
