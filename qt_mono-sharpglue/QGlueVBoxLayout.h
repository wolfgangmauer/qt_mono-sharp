﻿#pragma once
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueVBoxLayout : public QVBoxLayout
{
    //Q_OBJECT
public:
    GlueVBoxLayout(MonoObject* thisObject, GlueWidget* parent = 0);
private:
    MonoObject* _thisObject;
};

//QVBoxLayout* qt_vboxlayout_new(QWidget* parent);
