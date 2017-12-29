#include <stdint.h>
#include "QGlueWidget.h"

GlueWidget::GlueWidget(MonoObject* thisObject, QWidget* parent, Qt::WindowFlags f)
	: QWidget(parent, f)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueWidget::~GlueWidget()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void doOnRawDelete(guint32 thisObject)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(thisObject));
	auto method = mono_class_get_method_from_name_recursive(klass, "OnUnmanagedDeleted", 1);
	if (method)
	{
		void *args [1];
		args[0] = mono_gchandle_get_target(thisObject);
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke (method, NULL, args, NULL);
	}
}

bool dokeyPressEvent(guint32 _thisObject, QKeyEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnKeyPress", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool dokeyReleaseEvent(guint32 _thisObject, QKeyEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnKeyRelease", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "KeyEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool doMouseEvent(guint32 _thisObject, QMouseEvent* event, std::string managedName)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, managedName, 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "MouseEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool doMousePressEvent(guint32 _thisObject, QMouseEvent* event)
{
	return doMouseEvent(_thisObject, event, "OnMousePress");
}

bool doMouseReleaseEvent(guint32 _thisObject, QMouseEvent* event)
{
	return doMouseEvent(_thisObject, event, "OnMouseRelease");
}

bool doMouseDoubleClickEvent(guint32 _thisObject, QMouseEvent* event)
{
	return doMouseEvent(_thisObject, event, "OnMouseDoubleClick");
}

bool doMouseMoveEvent(guint32 _thisObject, QMouseEvent* event)
{
	return doMouseEvent(_thisObject, event, "OnMouseMove");
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

bool dowheelEvent(guint32 _thisObject, QWheelEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnWheel", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "WheelEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool dofocusInEvent(guint32 _thisObject, QFocusEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnFocusIn", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "FocusEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool dofocusOutEvent(guint32 _thisObject, QFocusEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnFocusOut", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "FocusEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool doenterEvent(guint32 _thisObject, QEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnEnter", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool doleaveEvent(guint32 _thisObject, QEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnLeave", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool dopaintEvent(guint32 _thisObject, QPaintEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnPaint", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "PaintEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool domoveEvent(guint32 _thisObject, QMoveEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnMove", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "MoveEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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
	return false;
}

bool doresizeEvent(guint32 _thisObject, QResizeEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnResize", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ResizeEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool docloseEvent(guint32 _thisObject, QCloseEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnClose", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "CloseEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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
bool docontextMenuEvent(guint32 _thisObject, QContextMenuEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnContextMenu", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ContextMenuEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
		}
		else
		{
			printf("Can't create Qt.ContextMenuEvent\n");
			fflush(stdout);
		}
	}
	else
	{
		printf("Cant find OnContextMenu\n");
		fflush(stdout);
	}
	return false;
}
#endif
#ifndef QT_NO_TABLETEVENT
void dotabletEvent(guint32 _thisObject, QTabletEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnTable", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "TabletEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
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
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL)));
		}
	}
}
#endif
#ifndef QT_NO_ACTION
void doactionEvent(guint32 _thisObject, QActionEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnAction", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ActionEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
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
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL)));
		}
	}
}
#endif

#ifndef QT_NO_DRAGANDDROP
void dodragEnterEvent(guint32 _thisObject, QDragEnterEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDragEnter", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragEnterEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
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
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL)));
		}
	}
}

void dodragMoveEvent(guint32 _thisObject, QDragMoveEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDragMove", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragMoveEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
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
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL)));
		}
	}
}

void dodragLeaveEvent(guint32 _thisObject, QDragLeaveEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDragLeave", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DragLeaveEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
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
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL)));
		}
	}
}

void dodropEvent(guint32 _thisObject, QDropEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnDrop", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "DropEvent");
		if (eventArgs)
		{
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
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
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			event->setAccepted(*(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL)));
		}
	}
}
#endif

bool doshowEvent(guint32 _thisObject, QShowEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnShow", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "ShowEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool dohideEvent(guint32 _thisObject, QHideEvent *event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnHide", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "HideEvent");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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

bool dochangeEvent(guint32 _thisObject, QEvent* event)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnChange", 1);
	if (eventMethod)
	{
		MonoImage* image = mono_class_get_image(mono_method_get_class(eventMethod));
		MonoClass* eventArgs = mono_class_from_name (image, "Qt", "Event");
		if (eventArgs)
		{
			void *args [1];
			args[0] = &event;
			auto result = mono_object_new (mono_object_get_domain(mono_gchandle_get_target(_thisObject)), eventArgs);
			MonoMethod* ctor = mono_class_get_method_from_name (eventArgs, ".ctor", 1);
			mono_thread_attach (mono_get_root_domain ());
			mono_runtime_invoke (ctor, result, args, NULL);

			args[0] = result;
			MonoMethod* method = mono_object_get_virtual_method (mono_gchandle_get_target(_thisObject), eventMethod);
			mono_thread_attach (mono_get_root_domain ());
			return *(bool*)mono_object_unbox(mono_runtime_invoke(method, mono_gchandle_get_target(_thisObject), args, NULL));
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
