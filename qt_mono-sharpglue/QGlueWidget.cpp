#include <stdint.h>
#include "QGlueWidget.h"

GlueWidget::GlueWidget(MonoObject* thisObject, GlueWidget* parent, Qt::WindowFlags f)  : QWidget(parent, f)
{
	_thisObject = thisObject;
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

void dokeyPressEvent(MonoObject* thisObject, QKeyEvent *keyEvent)
{
	auto klass = mono_object_get_class (thisObject);
	auto keyPressEventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"OnKeyPress", 1);
	if (keyPressEventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(keyPressEventMethod));
		MonoClass* keyEventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
		if (keyEventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), keyEventArgs);
			void *args [6];
			int type = keyEvent->type();
			int key = keyEvent->key();
			int modifiers = (int)keyEvent->modifiers();
			MonoString* text = mono_string_new(mono_domain_get (), keyEvent->text().toLatin1().data());
			bool autoRepeat = keyEvent->isAutoRepeat();
			int count = keyEvent->count();
			args[0] = &type;
			args[1] = &key;
			args[2] = &modifiers;
			args[3] = text;
			args[4] = &autoRepeat;
			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (keyEventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, keyPressEventMethod);
			mono_runtime_invoke(method, thisObject, args, NULL);
		}
	}
}

void dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent *keyEvent)
{
	auto klass = mono_object_get_class (thisObject);
	auto keyReleaseEventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"OnKeyRelease", 1);
	if (keyReleaseEventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(keyReleaseEventMethod));
		MonoClass* keyEventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
		if (keyEventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), keyEventArgs);
			void *args [6];
			int type = keyEvent->type();
			int key = keyEvent->key();
			int modifiers = (int)keyEvent->modifiers();
			MonoString* text = mono_string_new(mono_domain_get (), keyEvent->text().toLatin1().data());
			bool autoRepeat = keyEvent->isAutoRepeat();
			int count = keyEvent->count();
			args[0] = &type;
			args[1] = &key;
			args[2] = &modifiers;
			args[3] = text;
			args[4] = &autoRepeat;
			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (keyEventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, keyReleaseEventMethod);
			mono_runtime_invoke(method, thisObject, args, NULL);
		}
	}
}

void doMouseEvent(MonoObject* thisObject, QMouseEvent* event, std::string managedName)
{
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, managedName, 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "MouseEvent");
		if (eventArgs)
		{
			MonoObject* result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [11];
			int type = event->type();
			auto localPosx = event->localPos().x();
			auto localPosy = event->localPos().y();
			auto windowPosx = event->windowPos().x();
			auto windowPosy = event->windowPos().y();
			auto screenPosx = event->screenPos().x();
			auto screenPosy = event->screenPos().y();
			Qt::MouseButton button = event->button();
			Qt::MouseButtons buttons = event->buttons();
			Qt::KeyboardModifiers modifiers = event->modifiers();
			Qt::MouseEventSource source = event->source();
			args[0] = &type;
			args[1] = &localPosx;
			args[2] = &localPosy;
			args[3] = &windowPosx;
			args[4] = &windowPosy;
			args[5] = &screenPosx;
			args[6] = &screenPosy;
			args[7] = &button;
			args[8] = &buttons;
			args[9] = &modifiers;
			args[10] = &source;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 11);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			mono_runtime_invoke(method, thisObject, args, NULL);
			printf("Calling %s\n", managedName.c_str());
			fflush(stdout);
		}
		else
		{
			printf("Can't create Qt.MouseEvent\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find %s\n", managedName.c_str());
		fflush(stdout);
	}
}

void doMousePressEvent(MonoObject* thisObject, QMouseEvent* event)
{
	doMouseEvent(thisObject, event, "OnMousePressEvent");
}

void doMouseReleaseEvent(MonoObject* thisObject, QMouseEvent* event)
{
	doMouseEvent(thisObject, event, "OnMouseReleaseEvent");
}

void doMouseDoubleClickEvent(MonoObject* thisObject, QMouseEvent* event)
{
	doMouseEvent(thisObject, event, "OnMouseDoubleClickEvent");
}

void doMouseMoveEvent(MonoObject* thisObject, QMouseEvent* event)
{
	doMouseEvent(thisObject, event, "OnMouseMoveEvent");
}

bool doEvent(MonoObject* thisObject, QEvent* event)
{
	bool retVal = false;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, (char*)"OnEvent", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			MonoObject* result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [3];
			int type = event->type();
			bool spontaneous = event->spontaneous();
			bool accepted = event->isAccepted();
			args[0] = &type;
			args[1] = &spontaneous;
			args[2] = &accepted;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 3);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			result = mono_runtime_invoke(method, thisObject, args, NULL);
			retVal = *(bool*)mono_object_unbox(result);
		}
	}
	return retVal;
}

void GlueWidget::keyPressEvent(QKeyEvent *keyEvent)
{
	dokeyPressEvent(_thisObject, keyEvent);
}

void GlueWidget::keyReleaseEvent(QKeyEvent *keyEvent)
{
	dokeyReleaseEvent(_thisObject, keyEvent);
}

bool GlueWidget::event (QEvent* event)
{
	return doEvent(_thisObject, event);
}

void GlueWidget::mousePressEvent (QMouseEvent *event)
{
	doMousePressEvent(_thisObject, event);
}

void GlueWidget::mouseReleaseEvent (QMouseEvent *event)
{
	doMouseReleaseEvent(_thisObject, event);
}

void GlueWidget::mouseDoubleClickEvent (QMouseEvent *event)
{
	doMouseDoubleClickEvent(_thisObject, event);
}

void GlueWidget::mouseMoveEvent (QMouseEvent *event)
{
	doMouseMoveEvent(_thisObject, event);
}
