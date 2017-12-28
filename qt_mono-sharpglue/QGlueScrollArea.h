#pragma once
#include <QScrollArea>
#include "QGlueWidget.h"

class GlueScrollArea : public QScrollArea
{
#define BaseClass QScrollArea
#include "internalevents.h"
public:
    GlueScrollArea(MonoObject* thisObject, QWidget *parent=0);
    ~GlueScrollArea();
private:
    guint32 _thisObject;
};