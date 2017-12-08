#pragma once
#include <QLabel>
#include "QGlueWidget.h"

class GlueLabel : public QLabel
{
#define BaseClass QLabel
#include "internalevents.h"
public:
    GlueLabel(MonoObject* thisObject, QWidget *parent=0, Qt::WindowFlags f=0);
    GlueLabel(MonoObject* thisObject, char* text, QWidget *parent=0, Qt::WindowFlags f=0);

    void setText(MonoString*);
private:
    MonoObject* _thisObject;
};

//void qt_label_alignment_set(QLabel* label, Qt::Alignment alignment);
//Qt::Alignment qt_label_alignment_get(QLabel* label);
//
//QLabel* qt_label_new(QWidget* parent, Qt::WindowFlags f);
//QLabel* qt_label_new_with_text(char* text, QWidget* parent, Qt::WindowFlags f);
