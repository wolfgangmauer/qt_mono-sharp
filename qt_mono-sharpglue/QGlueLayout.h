#pragma once
#include <QLayout>
#include "QGlueWidget.h"

class GlueLayout : public QLayout
{
public:
    GlueLayout(MonoObject* thisObject, GlueWidget* parent = 0);
    ~GlueLayout();
private:
    guint32 _thisObject;
};
