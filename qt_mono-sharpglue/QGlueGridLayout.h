#pragma once
#include <QLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    GlueGridLayout(MonoObject*, GlueWidget* parent = 0);
private:
	MonoObject* _thisObject;
};

