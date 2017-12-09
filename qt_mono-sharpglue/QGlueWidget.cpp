#include <stdint.h>
#include "QGlueWidget.h"

GlueWidget::GlueWidget(MonoObject* thisObject, QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	_thisObject = thisObject;
}

//void GlueWidget::geometry(int* x, int* y, int* width, int* height)
//{
//	QRect rect = QWidget::geometry();
//	*x = rect.x();
//	*y = rect.y();
//	*width = rect.width();
//	*height = rect.height();
//}
//
GlueSizePolicy* GlueWidget::sizePolicy()
{
	glueSizePolicy = QWidget::sizePolicy();
	return reinterpret_cast<GlueSizePolicy*>(&glueSizePolicy);
}

bool dokeyPressEvent(MonoObject* thisObject, QKeyEvent *event)
{
	printf("dokeyPressEvent\n"); fflush(stdout);
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnKeyPress", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.KeyEvent\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnKeyPress\n");
		fflush(stdout);
	}
	return false;
}

bool dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent *event)
{
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnKeyRelease", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.KeyEvent\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnKeyRelease\n");
		fflush(stdout);
	}
	return false;
}

bool doMouseEvent(MonoObject* thisObject, QMouseEvent* event, std::string managedName)
{
	printf("Execute doMouseEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, managedName, 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "MouseEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.KeyEvent\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find %s\n", managedName.c_str());
		fflush(stdout);
	}
	return false;
}

bool doMousePressEvent(MonoObject* thisObject, QMouseEvent* event)
{
	return doMouseEvent(thisObject, event, "OnMousePress");
}

bool doMouseReleaseEvent(MonoObject* thisObject, QMouseEvent* event)
{
	return doMouseEvent(thisObject, event, "OnMouseRelease");
}

bool doMouseDoubleClickEvent(MonoObject* thisObject, QMouseEvent* event)
{
	return doMouseEvent(thisObject, event, "OnMouseDoubleClick");
}

bool doMouseMoveEvent(MonoObject* thisObject, QMouseEvent* event)
{
	return doMouseEvent(thisObject, event, "OnMouseMove");
}

//bool doEvent(MonoObject* thisObject, QEvent* event)
//{
//	bool retVal = false;
//	auto klass = mono_object_get_class (thisObject);
//	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnEvent", 1);
//	if (eventMethod)
//	{
//		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
//		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
//		if (eventArgs)
//		{
//			MonoObject* result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
//			void *args [3];
//			int type = event->type();
//			bool spontaneous = event->spontaneous();
//			bool accepted = event->isAccepted();
//			args[0] = &type;
//			args[1] = &spontaneous;
//			args[2] = &accepted;
//			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 3);
//			mono_runtime_invoke (ctor, result, args, NULL);
//
//			args[0] = result;
//			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
//			result = mono_runtime_invoke(method, thisObject, args, NULL);
//			retVal = *(bool*)mono_object_unbox(result);
//		}
//	}
//	return retVal;
//}

bool dowheelEvent(MonoObject* thisObject, QWheelEvent* event)
{
	printf("Execute dowheelEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnWheel", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "WheelEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnWheel\n");
		fflush(stdout);
	}
	return false;
}

bool dofocusInEvent(MonoObject* thisObject, QFocusEvent* event)
{
	printf("Execute dofocusInEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnFocusIn", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "FocusEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnFocusIn\n");
		fflush(stdout);
	}
	return false;
}

bool dofocusOutEvent(MonoObject* thisObject, QFocusEvent* event)
{
	printf("Execute dofocusOutEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnFocusOut", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "FocusEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnFocusOut\n");
		fflush(stdout);
	}
	return false;
}

bool doenterEvent(MonoObject* thisObject, QEvent* event)
{
	printf("Execute doenterEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnEnter", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnEnter\n");
		fflush(stdout);
	}
	return false;
}

bool doleaveEvent(MonoObject* thisObject, QEvent* event)
{
	printf("Execute doleaveEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnLeave", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnLeave\n");
		fflush(stdout);
	}
	return false;
}

bool dopaintEvent(MonoObject* thisObject, QPaintEvent* event)
{
	printf("Execute dopaintEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnPaint", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "PaintEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnCloseEvent\n");
		fflush(stdout);
	}
	return false;
}

bool domoveEvent(MonoObject* thisObject, QMoveEvent* event)
{
	printf("Execute domoveEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnMove", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "MoveEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnMove\n");
		fflush(stdout);
	}
}

bool doresizeEvent(MonoObject* thisObject, QResizeEvent* event)
{
	printf("Execute doresizeEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnResize", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ResizeEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnCloseEvent\n");
		fflush(stdout);
	}
	return false;
}

bool docloseEvent(MonoObject* thisObject, QCloseEvent* event)
{
	printf("Execute docloseEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnClose", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "CloseEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnCloseEvent\n");
		fflush(stdout);
	}
	return false;
}

#ifndef QT_NO_CONTEXTMENU
void docontextMenuEvent(MonoObject* thisObject, QContextMenuEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnContextMenu", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ContextMenuEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}
#endif
#ifndef QT_NO_TABLETEVENT
void dotabletEvent(MonoObject* thisObject, QTabletEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnTable", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "TabletEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}
#endif
#ifndef QT_NO_ACTION
void doactionEvent(MonoObject* thisObject, QActionEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnAction", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ActionEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}
#endif

#ifndef QT_NO_DRAGANDDROP
void dodragEnterEvent(MonoObject* thisObject, QDragEnterEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDragEnter", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragEnterEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}

void dodragMoveEvent(MonoObject* thisObject, QDragMoveEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDragMove", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragMoveEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}

void dodragLeaveEvent(MonoObject* thisObject, QDragLeaveEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDragLeave", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragLeaveEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}

void dodropEvent(MonoObject* thisObject, QDropEvent *event)
{
	printf("Execute Event %d\n", event->type()); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDrop", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DropEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			void *args [6];
			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
			mono_runtime_invoke (ctor, result, args, NULL);
			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL)));
		}
	}
}
#endif

bool doshowEvent(MonoObject* thisObject, QShowEvent* event)
{
	printf("Execute doshowEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnShow", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ShowEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnShow\n");
		fflush(stdout);
	}
	return false;
}

bool dohideEvent(MonoObject* thisObject, QHideEvent *event)
{
	printf("Execute dohideEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnHide", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "HideEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnShow\n");
		fflush(stdout);
	}
	return false;
}

//bool donativeEvent(MonoObject* thisObject, const QByteArray &eventType, void *message, long *result)
//{
//	bool retVal = false;
//	auto klass = mono_object_get_class (thisObject);
//	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnNativeEvent", 3);
//	if (eventMethod)
//	{
//		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
//		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragEnterEvent");
//		if (eventArgs)
//		{
//			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
//			void *args [6];
//			int type = event->type();
//			int key = event->key();
//			int modifiers = (int)event->modifiers();
//			MonoString* text = mono_string_new(mono_domain_get (), event->text().toLatin1().data());
//			bool autoRepeat = event->isAutoRepeat();
//			int count = event->count();
//			args[0] = &type;
//			args[1] = &key;
//			args[2] = &modifiers;
//			args[3] = text;
//			args[4] = &autoRepeat;
//			args[5] = &count;
//			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 6);
//			mono_runtime_invoke (ctor, result, args, NULL);
//			args[0] = result;
//			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
//			mono_runtime_invoke(method, thisObject, args, NULL);
//		}
//	}
//	return retVal;
//}

bool dochangeEvent(MonoObject* thisObject, QEvent* event)
{
	printf("Execute dochangeEvent\n"); fflush(stdout);//if (!thisObject) return;
	auto klass = mono_object_get_class (thisObject);
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnChange", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(thisObject), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (thisObject, eventMethod);
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, thisObject, args, NULL));
		}
		else
		{
			printf("Can't create Qt.Event\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnShow\n");
		fflush(stdout);
	}
	return false;
}
