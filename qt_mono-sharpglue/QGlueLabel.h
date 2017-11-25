#pragma once
#include <QLabel>
#include "QGlueWidget.h"

class GlueLabel : public QLabel
{
    Q_OBJECT
public:
    GlueLabel(MonoObject* thisObject, GlueWidget *parent=0, Qt::WindowFlags f=0);
    GlueLabel(MonoObject* thisObject, char* text, GlueWidget *parent=0, Qt::WindowFlags f=0);
};

//void qt_label_alignment_set(QLabel* label, Qt::Alignment alignment);
//Qt::Alignment qt_label_alignment_get(QLabel* label);
//
//QLabel* qt_label_new(QWidget* parent, Qt::WindowFlags f);
//QLabel* qt_label_new_with_text(char* text, QWidget* parent, Qt::WindowFlags f);
