#pragma once
#include <QDialog>
#include "QGlueWidget.h"

class GlueDialog : public QDialog
{
    //Q_OBJECT
public:
    GlueDialog(MonoObject* thisObject, GlueWidget* parent = 0, Qt::WindowFlags f = 0);

protected:
	void keyPressEvent(QKeyEvent *) override;
	void keyReleaseEvent(QKeyEvent *) override;

private:
	MonoObject* _thisObject;
//	MonoClass* _klass;
//	MonoMethod* _keyPressEventMethod;
//	MonoMethod* _keyReleaseEventMethod;
};

//extern "C" void* qt_dialog_new(void* parent);
//extern "C" int qt_dialog_exec(void* dialog);
//extern "C" bool qt_dialog_modal_get(void* dialog);
//extern "C" void qt_dialog_modal_set(void* dialog, bool modal);
