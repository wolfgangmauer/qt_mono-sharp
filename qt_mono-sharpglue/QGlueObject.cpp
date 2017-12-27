#include <glib.h>
#include "QGlueMainWindow.h"

//MonoImage* _image;
//
GlueObject::GlueObject(MonoObject* thisObject, GlueObject* parent) : QObject(parent)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}

void GlueObject::setObjectName(MonoString* name)
{
	char* p = mono_string_to_utf8(name);
	QObject::setObjectName(p);
	g_free(p);
}

MonoMethod* mono_class_get_method_from_name_recursive(MonoClass *klass, std::string name, uint32_t param_count)
{
	MonoMethod *method = NULL;
	while (klass != NULL && method == NULL)
	{
		method = mono_class_get_method_from_name (klass, name.c_str(), param_count);
		if (method == NULL)
			klass = mono_class_get_parent (klass);
	}
	return method;
}

MonoClass* mono_class_get_base(MonoClass* klass)
{
	MonoClass* retVal = klass;
	while (klass != NULL)
	{
		klass = mono_class_get_parent (klass);
		if (klass != NULL)
			retVal = klass;
	}
	return retVal;
}

void mono_property_set(MonoObject* obj, std::string property, int value)
{
	MonoClass* klass = mono_object_get_class (obj);
	MonoProperty* prop = mono_class_get_property_from_name(klass, property.c_str());
	int key = value;
	void *args[1];
	args[0] = &key;
	mono_property_set_value(prop, obj, args, NULL);
}

void mono_property_set(MonoObject* obj, std::string property, bool value)
{
	MonoClass* klass = mono_object_get_class (obj);
	MonoProperty* prop = mono_class_get_property_from_name(klass, property.c_str());
	bool key = value;
	void *args[1];
	args[0] = &key;
	mono_property_set_value(prop, obj, args, NULL);
}

void mono_property_set(MonoObject* obj, std::string property, MonoString* value)
{
	MonoClass* klass = mono_object_get_class (obj);
	MonoProperty* prop = mono_class_get_property_from_name(klass, property.c_str());
	void *args[1];
	args[0] = value;
	mono_property_set_value(prop, obj, args, NULL);
}
