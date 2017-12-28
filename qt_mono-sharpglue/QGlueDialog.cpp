#include "QGlueDialog.h"

GlueDialog::GlueDialog(MonoObject* thisObject, QWidget* parent, Qt::WindowFlags f)
	: QDialog(parent, f)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueDialog::~GlueDialog()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
