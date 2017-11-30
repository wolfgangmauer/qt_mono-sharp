#pragma once
#include <QLayout>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "QGlueWidget.h"

class GlueBoxLayout : public QBoxLayout
{
    //Q_OBJECT
public:
    GlueBoxLayout(MonoObject*, QBoxLayout::Direction dir, GlueWidget* parent = 0);
private:
	MonoObject* _thisObject;
};

//QBoxLayout* qt_boxlayout_new(QBoxLayout::Direction dir, QWidget* parent);
//void qt_boxlayout_widget_add(QBoxLayout* boxlayout, QWidget* widget, int stretch, Qt::Alignment alignment);
