#pragma once
#include <QHBoxLayout>
#include "QGlueWidget.h"

class GlueHBoxLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    GlueHBoxLayout(MonoObject* thisObject, GlueWidget* parent = 0);
};

//QHBoxLayout* qt_hboxlayout_new(QWidget* parent);
