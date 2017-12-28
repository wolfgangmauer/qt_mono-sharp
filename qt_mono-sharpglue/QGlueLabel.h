#pragma once
#include <QLabel>
#include "QGlueWidget.h"

class GlueLabel : public QLabel
{
#define BaseClass QLabel
#include "internalevents.h"
public:
    GlueLabel(MonoObject* thisObject, QWidget *parent=0, Qt::WindowFlags f=0);
    GlueLabel(MonoObject* thisObject, char* text, QWidget *parent=0, Qt::WindowFlags f=0);
    ~GlueLabel();
private:
    guint32 _thisObject;
};
