#include "QGlueTableWidget.h"

GlueTableWidget::GlueTableWidget(MonoObject* thisObject, QWidget *parent) : QTableWidget(parent)
{
	_thisObject = thisObject;
}