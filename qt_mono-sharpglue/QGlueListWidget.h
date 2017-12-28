#pragma once
#include <QListWidget>
#include "QGlueWidget.h"

class GlueListWidget : public QListWidget
{
#define BaseClass QListWidget
#include "internalevents.h"
public:
    GlueListWidget(MonoObject* thisObject, QWidget *parent=0);
    ~GlueListWidget();
private:
    guint32 _thisObject;
};

