#include "QGlueCheckBox.h"

GlueCheckBox::GlueCheckBox(MonoObject* thisObject, QWidget *parent) 
	: QCheckBox(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, &QCheckBox::pressed, this, &GlueCheckBox::onpressed);
	connect(this, &QCheckBox::released, this, &GlueCheckBox::onreleased);
	connect(this, &QCheckBox::clicked, this, &GlueCheckBox::onclicked);
	connect(this, &QCheckBox::toggled, this, &GlueCheckBox::ontoggled);
}

GlueCheckBox::GlueCheckBox(MonoObject* thisObject, char* text, QWidget *parent)
	: QCheckBox(text, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, &QCheckBox::pressed, this, &GlueCheckBox::onpressed);
	connect(this, &QCheckBox::released, this, &GlueCheckBox::onreleased);
	connect(this, &QCheckBox::clicked, this, &GlueCheckBox::onclicked);
	connect(this, &QCheckBox::toggled, this, &GlueCheckBox::ontoggled);
}

GlueCheckBox::~GlueCheckBox()
{
	connect(this, &QCheckBox::pressed, this, &GlueCheckBox::onpressed);
	connect(this, &QCheckBox::released, this, &GlueCheckBox::onreleased);
	connect(this, &QCheckBox::clicked, this, &GlueCheckBox::onclicked);
	connect(this, &QCheckBox::toggled, this, &GlueCheckBox::ontoggled);
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueCheckBox::onpressed()
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnPressed", 0);
	if (eventMethod)
	{
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), NULL, NULL);
	}
	else
	{
		printf("Can't find OnPressed\n");
		fflush(stdout);
	}
}

void GlueCheckBox::onreleased()
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnReleased", 0);
	if (eventMethod)
	{
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), NULL, NULL);
	}
	else
	{
		printf("Can't find OnReleased\n");
		fflush(stdout);
	}
}

void GlueCheckBox::onclicked(bool checked)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnClicked", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = &checked;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnClicked\n");
		fflush(stdout);
	}
}

void GlueCheckBox::ontoggled(bool checked)
{
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnToggled", 1);
	if (eventMethod)
	{
		void *args [1];
		args[0] = &checked;
		mono_thread_attach (mono_get_root_domain ());
		mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
	}
	else
	{
		printf("Can't find OnToggled\n");
		fflush(stdout);
	}
}