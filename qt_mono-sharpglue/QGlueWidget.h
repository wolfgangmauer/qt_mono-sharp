#pragma once
#include <stdint.h>
#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include "QGlueObject.h"
#include "QGlueFont.h"
#include "QGlueSizePolicy.h"

bool dokeyPressEvent(MonoObject* thisObject, QKeyEvent* event);
bool dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent* event);

bool doMousePressEvent(MonoObject* thisObject, QMouseEvent* event);
bool doMouseReleaseEvent(MonoObject* thisObject, QMouseEvent* event);
bool doMouseMoveEvent(MonoObject* thisObject, QMouseEvent* event);
bool doMouseDoubleClickEvent(MonoObject* thisObject, QMouseEvent* event);

bool dowheelEvent(MonoObject* thisObject, QWheelEvent *event);

void dofocusInEvent(MonoObject* thisObject, QFocusEvent* event);
void dofocusOutEvent(MonoObject* thisObject, QFocusEvent* event);

bool doenterEvent(MonoObject* thisObject, QEvent* event);
bool doleaveEvent(MonoObject* thisObject, QEvent* event);

bool dopaintEvent(MonoObject* thisObject, QPaintEvent* event);
bool domoveEvent(MonoObject* thisObject, QMoveEvent* event);
bool doresizeEvent(MonoObject* thisObject, QResizeEvent* event);
bool docloseEvent(MonoObject* thisObject, QCloseEvent* event);

#ifndef QT_NO_CONTEXTMENU
void docontextMenuEvent(MonoObject* thisObject, QContextMenuEvent *event);
#endif
#ifndef QT_NO_TABLETEVENT
void dotabletEvent(MonoObject* thisObject, QTabletEvent *event);
#endif
#ifndef QT_NO_ACTION
void doactionEvent(MonoObject* thisObject, QActionEvent *event);
#endif

#ifndef QT_NO_DRAGANDDROP
void dodragEnterEvent(MonoObject* thisObject, QDragEnterEvent *event);
void dodragMoveEvent(MonoObject* thisObject, QDragMoveEvent *event);
void dodragLeaveEvent(MonoObject* thisObject, QDragLeaveEvent *event);
void dodropEvent(MonoObject* thisObject, QDropEvent *event);
#endif
bool doshowEvent(MonoObject* thisObject, QShowEvent* event);
bool dohideEvent(MonoObject* thisObject, QHideEvent* event);
//bool donativeEvent(MonoObject* thisObject, const QByteArray &eventType, void *message, long *result);

bool dochangeEvent(MonoObject* thisObject, QEvent* event);

class GlueWidget : public QWidget
{
#define BaseClass QWidget
#include "internalevents.h"
public:
    GlueWidget(MonoObject* thisObject, QWidget* parent = 0, Qt::WindowFlags f = 0);

	GlueFont* font();
	GlueSizePolicy* sizePolicy();
private:
	QFont glueFont;
	QSizePolicy glueSizePolicy;

	MonoObject* _thisObject;

	friend class GlueMainWindow;
	friend class GlueDialog;
};
