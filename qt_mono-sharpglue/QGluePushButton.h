#pragma once
#include <QPushButton>
#include "QGlueWidget.h"

class GluePushButton : public QPushButton
{
public:
    GluePushButton(MonoObject* thisObject, QWidget *parent=0);
    GluePushButton(MonoObject* thisObject, char* text, QWidget *parent=0);
    ~GluePushButton();

private:
   	void onpressed();
 	void onreleased();
 	void onclicked(bool checked);
 	void ontoggled(bool checked);

private:
    guint32 _thisObject;
};
