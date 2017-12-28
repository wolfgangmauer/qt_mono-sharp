#pragma once
#include <QMenu>
#include "QGlueWidget.h"

class GlueMenu : public QMenu
{
#define BaseClass QMenu
#include "internalevents.h"
public:
    GlueMenu(MonoObject* thisObject, QWidget* parent);
    GlueMenu(MonoObject* thisObject, const QString& text, QWidget* parent);
    ~GlueMenu();
private:
    guint32 _thisObject;
};


