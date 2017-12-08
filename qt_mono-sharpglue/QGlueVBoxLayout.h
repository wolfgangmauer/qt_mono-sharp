#pragma once
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueVBoxLayout : public QVBoxLayout
{
public:
    GlueVBoxLayout(MonoObject* thisObject, QWidget* parent = 0);
private:
    MonoObject* _thisObject;
};

//QVBoxLayout* qt_vboxlayout_new(QWidget* parent);
