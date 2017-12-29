#pragma once
#include <QCommandLinkButton>
#include "QGlueWidget.h"

class GlueCommandLinkButton : public QCommandLinkButton
{
public:
    GlueCommandLinkButton(MonoObject* thisObject, QWidget *parent=0);
    GlueCommandLinkButton(MonoObject* thisObject, char* text, QWidget *parent=0);
    ~GlueCommandLinkButton();

    QSize sizeHint() const override
    {
    	return QCommandLinkButton::sizeHint();
    }
private:
   	void onpressed();
 	void onreleased();
 	void onclicked(bool checked);
 	void ontoggled(bool checked);

private:
    guint32 _thisObject;
};

