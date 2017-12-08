#pragma once
#include <QHBoxLayout>
#include "QGlueWidget.h"

class GlueHBoxLayout : public QHBoxLayout
{
public:
    GlueHBoxLayout(MonoObject* thisObject, QWidget* parent = 0);
private:
    MonoObject* _thisObject;
};

//QHBoxLayout* qt_hboxlayout_new(QWidget* parent);
