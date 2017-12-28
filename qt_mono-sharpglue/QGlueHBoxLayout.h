#pragma once
#include <QHBoxLayout>
#include "QGlueWidget.h"

class GlueHBoxLayout : public QHBoxLayout
{
public:
    GlueHBoxLayout(MonoObject* thisObject, QWidget* parent = 0);
    ~GlueHBoxLayout();
private:
    guint32 _thisObject;
};
