#include "QGlueAction.h"

GlueAction::GlueAction(MonoObject* thisObject, QObject* parent)
	: QAction(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	connect(this, &QAction::triggered, this, &GlueAction::ontriggered);
}

GlueAction::GlueAction(MonoObject* thisObject, const QString& text, QObject* parent)
	: QAction(text, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	connect(this, &QAction::triggered, this, &GlueAction::ontriggered);
}

GlueAction::~GlueAction()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueAction::ontriggered(bool checked)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnTriggered", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = &checked;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnTriggered\n");
		fflush(stdout);
	}
}