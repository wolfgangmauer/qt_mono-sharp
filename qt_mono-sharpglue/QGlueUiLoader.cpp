#include "QGlueUiLoader.h"
#include "QGlueMainWindow.h"
#include "QGlueFrame.h"
#include "QGlueLabel.h"
#include "QGlueProgressBar.h"

#include "QGlueHBoxLayout.h"
#include "QGlueVBoxLayout.h"


GlueUiLoader::GlueUiLoader(MonoObject* thisObject, QObject* parent) : QUiLoader(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueUiLoader::~GlueUiLoader()
{
	doOnRawDispose(_thisObject);
	mono_gchandle_free (_thisObject); 
}

QWidget* GlueUiLoader::loadFile(QFile* uiFile, QWidget* parentWidget)
{
	return load(uiFile, parentWidget);
}

QLayout* GlueUiLoader::createLayout(const QString& className, QObject* parent, const QString& name)
{
	QLayout* retVal = NULL;
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnCreateLayout", 3);
	if (eventMethod)
	{
		void *args [3];
		MonoString* klassName = mono_string_new(mono_object_get_domain (mono_gchandle_get_target(_thisObject)), className.toStdString().c_str());
		MonoString* objectName = mono_string_new(mono_object_get_domain (mono_gchandle_get_target(_thisObject)), name.toStdString().c_str());
		args[0] = klassName;
		args[1] = &parent;
		args[2] = objectName;
		mono_thread_attach (mono_get_root_domain ());
		MonoObject* result = mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
		retVal = *(QLayout**)mono_object_unbox(result);
	}
	if (!retVal)
	{
		printf("createLayout %s \n", className.toStdString().c_str());
		fflush(stdout);
		retVal = QUiLoader::createLayout(className, parent, name);
	}
	return retVal;
}

QWidget* GlueUiLoader::createWidget(const QString& className, QWidget* parent, const QString& name)
{
	QWidget* retVal = NULL;
	auto klass = mono_object_get_class (mono_gchandle_get_target(_thisObject));
	auto eventMethod = mono_class_get_method_from_name_recursive(klass, "OnCreateWidget", 3);
	if (eventMethod)
	{
		void *args [3];
		MonoString* klassName = mono_string_new(mono_object_get_domain (mono_gchandle_get_target(_thisObject)), className.toStdString().c_str());
		MonoString* objectName = mono_string_new(mono_object_get_domain (mono_gchandle_get_target(_thisObject)), name.toStdString().c_str());
		args[0] = klassName;
		args[1] = &parent;
		args[2] = objectName;
		mono_thread_attach (mono_get_root_domain ());
		MonoObject* result = mono_runtime_invoke(eventMethod, mono_gchandle_get_target(_thisObject), args, NULL);
		retVal = *(QWidget**)mono_object_unbox(result);
	}
	if (!retVal)
	{
		printf("createWidget %s \n", className.toStdString().c_str());
		fflush(stdout);
		retVal = QUiLoader::createWidget(className, parent, name);
	}
	return retVal;
}