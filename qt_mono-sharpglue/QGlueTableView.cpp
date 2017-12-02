#include "QGlueTableView.h"

GlueTableView::GlueTableView(QWidget *parent) : QTableView(parent)
{
}

GlueTableView::GlueTableView(MonoObject* thisObject, GlueWidget *parent) : QTableView(parent)
{
	_thisObject = thisObject;
}

//void GlueTableView::keyPressEvent(QKeyEvent *keyEvent)
//{
//	dokeyPressEvent(_thisObject, keyEvent);
//}
//
//void GlueTableView::keyReleaseEvent(QKeyEvent *keyEvent)
//{
//	dokeyReleaseEvent(_thisObject, keyEvent);
//}
//
//bool GlueTableView::event (QEvent* event)
//{
//	return doEvent(_thisObject, event);
//}
//
//void GlueTableView::mousePressEvent (QMouseEvent *event)
//{
//	doMousePressEvent(_thisObject, event);
//}
//
//void GlueTableView::mouseReleaseEvent (QMouseEvent *event)
//{
//	doMouseReleaseEvent(_thisObject, event);
//}
//
//void GlueTableView::mouseDoubleClickEvent (QMouseEvent *event)
//{
//	doMouseDoubleClickEvent(_thisObject, event);
//}
//
//void GlueTableView::mouseMoveEvent (QMouseEvent *event)
//{
//	doMouseMoveEvent(_thisObject, event);
//}
