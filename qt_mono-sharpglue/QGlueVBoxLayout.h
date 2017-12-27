#pragma once
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueVBoxLayout : public QVBoxLayout
{
public:
    GlueVBoxLayout(MonoObject* thisObject, QWidget* parent = 0);
    ~GlueVBoxLayout();
private:
    guint32 _thisObject;
};
