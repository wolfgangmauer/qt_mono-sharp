#pragma once
#include "QGlueEvents.h"

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/class.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>

class GlueEvents : QWidget
{
public:
	GlueEvents(MonoObject* thisObject);

private:
	MonoObject* _thisObject;

};
