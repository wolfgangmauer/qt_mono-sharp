#pragma once
#include <QApplication>

//#include <mono/jit/jit.h>
//#include <mono/metadata/assembly.h>
//#include <mono/metadata/class.h>
//#include <mono/metadata/debug-helpers.h>
//#include <mono/metadata/mono-config.h>

#include "QGlueMainWindow.h"

class GlueApplication : public QApplication
{
public:
	GlueApplication(MonoObject*, int&, char**);
	~GlueApplication();
private:
	guint32 _thisObject;
};
