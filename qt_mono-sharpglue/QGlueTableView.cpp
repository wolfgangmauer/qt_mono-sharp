#include "QGlueTableView.h"

GlueTableView::GlueTableView(MonoObject* thisObject, GlueWidget *parent) : QTableView(parent)
{
	_thisObject = thisObject;
}
