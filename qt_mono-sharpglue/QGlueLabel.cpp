#include "QGlueLabel.h"

GlueLabel::GlueLabel(MonoObject* thisObject, GlueWidget *parent, Qt::WindowFlags f) : QLabel(parent, f)
{
}

GlueLabel::GlueLabel(MonoObject* thisObject, char* text, GlueWidget *parent, Qt::WindowFlags f) : QLabel(text, parent, f)
{
}
//
//GlueLabel::~GlueLabel()
//{
//}
