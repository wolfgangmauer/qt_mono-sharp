#include <string.h>
#include <stdlib.h>
#include <glib.h>

#include <QApplication>
//#include <mono/jit/jit.h>
//#include <mono/metadata/assembly.h>
//#include <mono/metadata/class.h>
//#include <mono/metadata/debug-helpers.h>
//#include <mono/metadata/mono-config.h>

#include "QGlueApplication.h"
#include "QGlueLabel.h"
#include "QGlueFrame.h"
#include "QGlueSizePolicy.h"
#include "QGlueBoxLayout.h"


void* qt_application_new(MonoObject* obj, MonoArray* argv)
{
	GlueApplication* retVal;
	int argc = mono_array_length (argv);
	char* _argv[argc];
	for (int i = 0; i < argc; i++)
		_argv[i] = mono_string_to_utf8(mono_array_get (argv, MonoString*, i));
	retVal = new GlueApplication(obj, argc, _argv);
	for (int i = 0; i < argc; i++)
		g_free(_argv[i]);
	return retVal;
}
GlueApplication::GlueApplication(MonoObject* thisObject, int argc, char**argv) : QApplication(argc, argv)
{
	_thisObject = thisObject;
//	_klass = mono_object_get_class (_thisObject);
//	_keyPressEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyPress", 1);
//	_keyReleaseEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyRelease", 1);
//	MonoImageOpenStatus *status;
}

void* qt_coreapplication_new()
{
	QCoreApplication* retVal;
	int argc = 1; //mono_array_length (argv);
	char* _argv[] = {(char*)"enterprise"};
//	for (int i = 0; i < argc; i++)
//		_argv[i] = mono_string_to_utf8(mono_array_get (argv, MonoString*, i));
	retVal = new QCoreApplication(argc, _argv);
//	for (int i = 0; i < argc; i++)
//		g_free(_argv[i]);
	return retVal;
}

void* qt_guiapplication_new()
{
	QGuiApplication* retVal;
	int argc = 1; //mono_array_length (argv);
	char* _argv[] = {(char*)"enterprise"};
//	for (int i = 0; i < argc; i++)
//		_argv[i] = mono_string_to_utf8(mono_array_get (argv, MonoString*, i));
	retVal = new QGuiApplication(argc, _argv);
//	for (int i = 0; i < argc; i++)
//		g_free(_argv[i]);
	return retVal;
}

uint32_t qt_application_exec(void* application)
{
	return reinterpret_cast<QApplication*>(application)->exec();
}

void qt_application_attribute_set(uint32_t attribute)
{
	QApplication::setAttribute((Qt::ApplicationAttribute)attribute);
}
