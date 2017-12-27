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
#include "QGlueBoxLayout.h"

GlueApplication::GlueApplication(MonoObject* thisObject, int &argc, char**argv) : QApplication(argc, argv)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

GlueApplication::~GlueApplication()
{
	doOnRawDispose(_thisObject);
	mono_gchandle_free (_thisObject); 
}
