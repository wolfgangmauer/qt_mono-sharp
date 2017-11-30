#pragma once
#include <QLayout>
#include "QGlueWidget.h"

class GlueLayout : public QLayout
{
    //Q_OBJECT
public:
    GlueLayout(MonoObject* thisObject, GlueWidget* parent = 0);
private:
    MonoObject* _thisObject;
};
