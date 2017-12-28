#pragma once
#include <QLayout>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueBoxLayout : public QBoxLayout
{
public:
    GlueBoxLayout(MonoObject*, QBoxLayout::Direction dir, QWidget* parent = 0);
    ~GlueBoxLayout();
private:
	guint32 _thisObject;
};
