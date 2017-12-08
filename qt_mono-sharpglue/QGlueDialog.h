#pragma once
#include <QDialog>
#include "QGlueWidget.h"

class GlueDialog : public QDialog
{
#define BaseClass QDialog
#include "internalevents.h"
public:
    GlueDialog(MonoObject* thisObject, QWidget* parent = 0, Qt::WindowFlags f = 0);

private:
	MonoObject* _thisObject;
};
