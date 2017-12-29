#include "QGluePushButton.h"

GluePushButton::GluePushButton(MonoObject* thisObject, QWidget *parent) 
	: QPushButton(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, &QPushButton::pressed, this, &GluePushButton::onpressed);
	connect(this, &QPushButton::released, this, &GluePushButton::onreleased);
	connect(this, &QPushButton::clicked, this, &GluePushButton::onclicked);
	connect(this, &QPushButton::toggled, this, &GluePushButton::ontoggled);
}

GluePushButton::GluePushButton(MonoObject* thisObject, char* text, QWidget *parent)
	: QPushButton(text, parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);

	connect(this, &QPushButton::pressed, this, &GluePushButton::onpressed);
	connect(this, &QPushButton::released, this, &GluePushButton::onreleased);
	connect(this, &QPushButton::clicked, this, &GluePushButton::onclicked);
	connect(this, &QPushButton::toggled, this, &GluePushButton::ontoggled);
}

GluePushButton::~GluePushButton()
{
	connect(this, &QPushButton::pressed, this, &GluePushButton::onpressed);
	connect(this, &QPushButton::released, this, &GluePushButton::onreleased);
	connect(this, &QPushButton::clicked, this, &GluePushButton::onclicked);
	connect(this, &QPushButton::toggled, this, &GluePushButton::ontoggled);
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}

void GluePushButton::onpressed()
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

void GluePushButton::onreleased()
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

void GluePushButton::onclicked(bool checked)
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

void GluePushButton::ontoggled(bool checked)
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
