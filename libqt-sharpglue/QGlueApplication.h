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
    Q_OBJECT
public:
    GlueApplication(MonoObject*, int, char**);

private:
	MonoObject* _thisObject;
};

void* qt_coreapplication_new();
void* qt_guiapplication_new();
void* qt_application_new(MonoObject*, MonoArray*);
void qt_application_attribute_set(uint32_t attribute);
uint32_t qt_application_exec(void*);
