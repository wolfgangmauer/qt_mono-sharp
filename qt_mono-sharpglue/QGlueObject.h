#pragma once
#include <stdint.h>
#include <QObject>
#include <QKeyEvent>
#include <glib.h>
#include <mono/jit/jit.h>
#include <mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/threads.h>

typedef MonoObject* (*getmanangedobjectcallback) ();

class GlueObject : public QObject
{
    Q_OBJECT
public:
	GlueObject(MonoObject* thisObject, GlueObject* parent = 0);

private:
	MonoObject* _thisObject;
};

MonoMethod* mono_class_get_method_from_name_recursive(MonoClass *klass, std::string name, uint32_t param_count);
MonoClass* mono_class_get_base(MonoClass* klass);
void mono_property_set(MonoObject* obj, char* property, int value);
void mono_property_set(MonoObject* obj, char* property, bool value);
void mono_property_set(MonoObject* obj, char* property, MonoString* value);

//extern MonoImage* _image;