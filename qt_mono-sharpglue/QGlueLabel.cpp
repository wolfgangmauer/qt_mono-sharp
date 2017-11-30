#include "QGlueLabel.h"

GlueLabel::GlueLabel(MonoObject* thisObject, GlueWidget *parent, Qt::WindowFlags f) : QLabel(parent, f)
{
	_thisObject = thisObject;
}

GlueLabel::GlueLabel(MonoObject* thisObject, char* text, GlueWidget *parent, Qt::WindowFlags f) : QLabel(text, parent, f)
{
	_thisObject = thisObject;
}
//
//GlueLabel::~GlueLabel()
//{
//}

void GlueLabel::setText(MonoString* text)
{
	char* p = mono_string_to_utf8(text);
	QLabel::setText(p);
	g_free(p);
}