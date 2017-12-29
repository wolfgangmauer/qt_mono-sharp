#pragma once
#include <QToolButton>
#include "QGlueWidget.h"

class GlueToolButton : public QToolButton
{
public:
    GlueToolButton(MonoObject* thisObject, QWidget *parent=0);
    ~GlueToolButton();

private:
   	void onpressed();
 	void onreleased();
 	void onclicked(bool checked);
 	void ontoggled(bool checked);

private:
    guint32 _thisObject;
};

