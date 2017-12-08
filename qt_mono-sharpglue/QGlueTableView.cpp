#include "QGlueTableView.h"

GlueTableView::GlueTableView(MonoObject* thisObject, QWidget *parent) : QTableView(parent)
{
	_thisObject = thisObject;
}