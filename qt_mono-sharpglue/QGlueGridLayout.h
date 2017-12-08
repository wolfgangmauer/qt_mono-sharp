#pragma once
#include <QLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueGridLayout : public QGridLayout
{
public:
    GlueGridLayout(MonoObject*, QWidget* parent = 0);

private:
	MonoObject* _thisObject;
};

