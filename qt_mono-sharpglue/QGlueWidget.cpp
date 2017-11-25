#include <stdint.h>
#include "QGlueWidget.h"

GlueWidget::GlueWidget(MonoObject* thisObject, GlueWidget* parent, Qt::WindowFlags f)  : QWidget(parent, f)
{
	_thisObject = thisObject;
	_klass = mono_object_get_class (_thisObject);
	_keyPressEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyPress", 1);
	_keyReleaseEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyRelease", 1);
//	MonoImageOpenStatus *status;
//	if(!_image)
//		_image = mono_object_image_get(_thisObject);
		//_image = mono_image_open("qt-sharp.dll", status);
}

//GlueWidget::~GlueWidget()
//{
//}
//

int GlueWidget::dokeyPressEvent(MonoObject* thisObject, QKeyEvent *keyEvent)
{
	auto klass = mono_object_get_class (thisObject);
	auto keyPressEventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"KeyPress", 1);
	void* args[1];
	MonoObject *result;
	MonoImage* image = mono_class_get_image(mono_method_get_class(keyPressEventMethod));
	MonoClass* keyEventArgs = mono_class_from_name (image, "Qt", "KeyEventArgs");
	if (keyEventArgs)
	{
		result = mono_object_new (mono_object_get_domain(thisObject), keyEventArgs);
		mono_runtime_object_init (result);

		mono_property_set(result, (char*)"Key", keyEvent->key());
		mono_property_set(result, (char*)"Modifiers", (int)keyEvent->modifiers());
		mono_property_set(result, (char*)"Text", mono_string_new(mono_object_get_domain(thisObject), keyEvent->text().toLatin1().data()));
		mono_property_set(result, (char*)"AutoRepeat", keyEvent->isAutoRepeat());
		mono_property_set(result, (char*)"Count", keyEvent->count());
	}
	args[0] = result;
	MonoMethod* method = mono_object_get_virtual_method (thisObject, keyPressEventMethod);
	result = mono_runtime_invoke(method, thisObject, args, NULL);
	return *(int*)mono_object_unbox (result);
}

int GlueWidget::dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent *keyEvent)
{
	auto klass = mono_object_get_class (thisObject);
	auto keyReleaseEventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"KeyRelease", 1);
	void* args[1];
	MonoObject *result;
	MonoImage* image = mono_class_get_image(mono_method_get_class(keyReleaseEventMethod));
	MonoClass* keyEventArgs = mono_class_from_name (image, "Qt", "KeyEventArgs");
	if (keyEventArgs)
	{
		result = mono_object_new (mono_object_get_domain(thisObject), keyEventArgs);
		mono_runtime_object_init (result);

		mono_property_set(result, (char*)"Key", keyEvent->key());
		mono_property_set(result, (char*)"Modifiers", (int)keyEvent->modifiers());
		mono_property_set(result, (char*)"Text", keyEvent->text().toLatin1().data());
		mono_property_set(result, (char*)"AutoRepeat", keyEvent->isAutoRepeat());
		mono_property_set(result, (char*)"Count", keyEvent->count());
	}
	args[0] = result;
	MonoMethod* method = mono_object_get_virtual_method (thisObject, keyReleaseEventMethod);
	result = mono_runtime_invoke(method, thisObject, args, NULL);
	return *(int*)mono_object_unbox (result);
}

void GlueWidget::keyPressEvent(QKeyEvent *keyEvent)
{
	if (GlueWidget::dokeyPressEvent(_thisObject, keyEvent) == -1)
		QWidget::keyPressEvent(keyEvent);
}

void GlueWidget::keyReleaseEvent(QKeyEvent *keyEvent)
{
	if (GlueWidget::dokeyReleaseEvent(_thisObject, keyEvent) == -1)
		QWidget::keyReleaseEvent(keyEvent);
}
