﻿#include "QGlueLabel.h"

GlueLabel::GlueLabel(MonoObject* thisObject, QWidget *parent, Qt::WindowFlags f) 
	: QLabel(parent, f)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueLabel::GlueLabel(MonoObject* thisObject, char* text, QWidget *parent, Qt::WindowFlags f)
	: QLabel(text, parent, f)
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
	_nameSpace = mono_class_get_namespace(mono_object_get_class (mono_gchandle_get_target(_thisObject)));
}

GlueLabel::~GlueLabel()
{
	doOnRawDelete(_thisObject);
	mono_gchandle_free (_thisObject); 
}
