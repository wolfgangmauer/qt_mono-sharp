#include "QGlueDialog.h"

GlueDialog::GlueDialog(MonoObject* thisObject, QWidget* parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	_thisObject = thisObject;
}
