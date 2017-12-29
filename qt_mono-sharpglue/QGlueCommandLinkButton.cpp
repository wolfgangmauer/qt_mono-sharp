#include "QGlueCommandLinkButton.h"

GlueCommandLinkButton::GlueCommandLinkButton(MonoObject* thisObject, QWidget *parent) 
	: QCommandLinkButton(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, &QCommandLinkButton::pressed, this, &GlueCommandLinkButton::onpressed);
	connect(this, &QCommandLinkButton::released, this, &GlueCommandLinkButton::onreleased);
	connect(this, &QCommandLinkButton::clicked, this, &GlueCommandLinkButton::onclicked);
	connect(this, &QCommandLinkButton::toggled, this, &GlueCommandLinkButton::ontoggled);
}

GlueCommandLinkButton::GlueCommandLinkButton(MonoObject* thisObject, char* text, QWidget *parent)
	: QCommandLinkButton(text, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, &QCommandLinkButton::pressed, this, &GlueCommandLinkButton::onpressed);
	connect(this, &QCommandLinkButton::released, this, &GlueCommandLinkButton::onreleased);
	connect(this, &QCommandLinkButton::clicked, this, &GlueCommandLinkButton::onclicked);
	connect(this, &QCommandLinkButton::toggled, this, &GlueCommandLinkButton::ontoggled);
}

GlueCommandLinkButton::~GlueCommandLinkButton()
{
	connect(this, &QCommandLinkButton::pressed, this, &GlueCommandLinkButton::onpressed);
	connect(this, &QCommandLinkButton::released, this, &GlueCommandLinkButton::onreleased);
	connect(this, &QCommandLinkButton::clicked, this, &GlueCommandLinkButton::onclicked);
	connect(this, &QCommandLinkButton::toggled, this, &GlueCommandLinkButton::ontoggled);
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GlueCommandLinkButton::onpressed()
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

void GlueCommandLinkButton::onreleased()
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

void GlueCommandLinkButton::onclicked(bool checked)
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

void GlueCommandLinkButton::ontoggled(bool checked)
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

