#include "QGlueComboBox.h"

GlueComboBox::GlueComboBox(MonoObject* thisObject, QWidget *parent) 
	: QComboBox(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &GlueComboBox::onindexactivated);
	connect(this, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated), this, &GlueComboBox::ontextactivated);
}

GlueComboBox::~GlueComboBox()
{
	disconnect(this, static_cast<void (QComboBox::*)(int)>(&QComboBox::activated), this, &GlueComboBox::onindexactivated);
	disconnect(this, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::activated), this, &GlueComboBox::ontextactivated);
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueComboBox::onindexactivated(int index)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnActivatedByIndex", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = &index;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnActivatedByIndex\n");
		fflush(stdout);
	}
}

void GlueComboBox::ontextactivated(const QString& text)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnActivatedByString", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = mono_string_new(mono_domain_get (), text.toStdString().c_str());
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnActivatedByString\n");
		fflush(stdout);
	}
}