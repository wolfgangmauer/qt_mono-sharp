#pragma once
#include <QCheckBox>
#include "QGlueWidget.h"

class GlueCheckBox : public QCheckBox
{
public:
    GlueCheckBox(MonoObject* thisObject, QWidget *parent=0);
    GlueCheckBox(MonoObject* thisObject, char* text, QWidget *parent=0);
    ~GlueCheckBox();

private:
   	void onpressed();
 	void onreleased();
 	void onclicked(bool checked);
 	void ontoggled(bool checked);

private:
    guint32 _thisObject;
};