#pragma once
#include <stdint.h>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include "QGlueObject.h"


bool dokeyPressEvent(guint32 thisObject, QKeyEvent* event);
bool dokeyReleaseEvent(guint32 thisObject, QKeyEvent* event);

bool doMousePressEvent(guint32 thisObject, QMouseEvent* event);
bool doMouseReleaseEvent(guint32 thisObject, QMouseEvent* event);
bool doMouseMoveEvent(guint32 thisObject, QMouseEvent* event);
bool doMouseDoubleClickEvent(guint32 thisObject, QMouseEvent* event);

bool dowheelEvent(guint32 thisObject, QWheelEvent *event);

bool dofocusInEvent(guint32 thisObject, QFocusEvent* event);
bool dofocusOutEvent(guint32 thisObject, QFocusEvent* event);

bool doenterEvent(guint32 thisObject, QEvent* event);
bool doleaveEvent(guint32 thisObject, QEvent* event);

bool dopaintEvent(guint32 thisObject, QPaintEvent* event);
bool domoveEvent(guint32 thisObject, QMoveEvent* event);
bool doresizeEvent(guint32 thisObject, QResizeEvent* event);
bool docloseEvent(guint32 thisObject, QCloseEvent* event);

#ifndef QT_NO_CONTEXTMENU
void docontextMenuEvent(guint32 thisObject, QContextMenuEvent *event);
#endif
#ifndef QT_NO_TABLETEVENT
void dotabletEvent(guint32 thisObject, QTabletEvent *event);
#endif
#ifndef QT_NO_ACTION
void doactionEvent(guint32 thisObject, QActionEvent *event);
#endif

#ifndef QT_NO_DRAGANDDROP
void dodragEnterEvent(guint32 thisObject, QDragEnterEvent *event);
void dodragMoveEvent(guint32 thisObject, QDragMoveEvent *event);
void dodragLeaveEvent(guint32 thisObject, QDragLeaveEvent *event);
void dodropEvent(guint32 thisObject, QDropEvent *event);
#endif
bool doshowEvent(guint32 thisObject, QShowEvent* event);
bool dohideEvent(guint32 thisObject, QHideEvent* event);
//bool donativeEvent(guint32 thisObject, const QByteArray &eventType, void *message, long *result);

bool dochangeEvent(guint32 thisObject, QEvent* event);

void doOnRawDelete(guint32 thisObject);

class GlueWidget : public QWidget
{
#define BaseClass QWidget
#include "internalevents.h"
public:
    GlueWidget(MonoObject* thisObject, QWidget* parent=0, Qt::WindowFlags f=0);
    ~GlueWidget();
private:
	guint32 _thisObject;
};
