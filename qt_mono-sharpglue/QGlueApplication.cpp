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

GlueApplication::GlueApplication(MonoObject* thisObject, int &argc, char**argv) : QApplication(argc, argv)
{
	_thisObject = thisObject;
//	_klass = mono_object_get_class (_thisObject);
//	_keyPressEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyPress", 1);
//	_keyReleaseEventMethod = mono_class_get_method_from_name_recursive(_klass, (char*)"KeyRelease", 1);
//	MonoImageOpenStatus *status;
}
