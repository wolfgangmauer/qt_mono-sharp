#pragma once
#include <QToolBar>
#include "QGlueWidget.h"

class GlueToolBar : public QToolBar
{
#define BaseClass QToolBar
#include "internalevents.h"
public:
    GlueToolBar(MonoObject* thisObject, QWidget* parent);
    ~GlueToolBar();
private:
    guint32 _thisObject;
};
