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

void GlueWidget::geometry(int* x, int* y, int* width, int* height)
{
	QRect rect = QWidget::geometry();
	*x = rect.x();
	*y = rect.y();
	*width = rect.width();
	*height = rect.height();
}

GlueFont* GlueWidget::font()
{
	glueFont = QWidget::font();
	return reinterpret_cast<GlueFont*>(&glueFont);
}

GlueSizePolicy* GlueWidget::sizePolicy()
{
	glueSizePolicy = QWidget::sizePolicy();
	return reinterpret_cast<GlueSizePolicy*>(&glueSizePolicy);
}

void GlueWidget::dokeyPressEvent(MonoObject* thisObject, QKeyEvent *keyEvent)
{
	auto klass = mono_object_get_class (thisObject);
	auto keyPressEventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"OnKeyPress", 1);
	void* args[1];
	MonoObject *result = NULL;
	if (keyPressEventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(keyPressEventMethod));
		MonoClass* keyEventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
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
		mono_runtime_invoke(method, thisObject, args, NULL);
	}
}

void GlueWidget::dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent *keyEvent)
{
	auto klass = mono_object_get_class (thisObject);
	auto keyReleaseEventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"OnKeyRelease", 1);
	void* args[1];
	MonoObject *result = NULL;
	if (keyReleaseEventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(keyReleaseEventMethod));
		MonoClass* keyEventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
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
		mono_runtime_invoke(method, thisObject, args, NULL);
	}
}

void GlueWidget::keyPressEvent(QKeyEvent *keyEvent)
{
	dokeyPressEvent(_thisObject, keyEvent);
}

void GlueWidget::keyReleaseEvent(QKeyEvent *keyEvent)
{
	dokeyReleaseEvent(_thisObject, keyEvent);
}
