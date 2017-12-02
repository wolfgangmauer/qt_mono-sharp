#pragma once
#include <stdint.h>
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include "QGlueObject.h"
#include "QGlueFont.h"
#include "QGlueSizePolicy.h"

bool doEvent(MonoObject* thisObject, QEvent* event);
void dokeyPressEvent(MonoObject* thisObject, QKeyEvent* keyEvent);
void dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent* keyEvent);

void doMousePressEvent(MonoObject* thisObject, QMouseEvent* event);
void doMouseReleaseEvent(MonoObject* thisObject, QMouseEvent* event);
void doMouseMoveEvent(MonoObject* thisObject, QMouseEvent* event);
void doMouseDoubleClickEvent(MonoObject* thisObject, QMouseEvent* event);

class GlueWidget : public QWidget
{
    //Q_OBJECT
public:
    GlueWidget(MonoObject* thisObject, GlueWidget* parent = 0, Qt::WindowFlags f = 0);
//	~GlueWidget();

	void geometry(int*, int*, int*, int*);
	GlueFont* font();
	GlueSizePolicy* sizePolicy();

protected:
    // Event handlers
    bool event(QEvent *event)  override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
//#ifndef QT_NO_WHEELEVENT
//    void wheelEvent(QWheelEvent *event) override;
//#endif
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
//    void focusInEvent(QFocusEvent *event) override;
//    void focusOutEvent(QFocusEvent *event) override;
//    void enterEvent(QEvent *event) override;
//    void leaveEvent(QEvent *event) override;
//    void paintEvent(QPaintEvent *event) override;
//    void moveEvent(QMoveEvent *event) override;
//    void resizeEvent(QResizeEvent *event) override;
//    void closeEvent(QCloseEvent *event) override;
//#ifndef QT_NO_CONTEXTMENU
//    void contextMenuEvent(QContextMenuEvent *event) override;
//#endif
//#ifndef QT_NO_TABLETEVENT
//    void tabletEvent(QTabletEvent *event) override;
//#endif
//#ifndef QT_NO_ACTION
//    void actionEvent(QActionEvent *event) override;
//#endif
//
//#ifndef QT_NO_DRAGANDDROP
//    void dragEnterEvent(QDragEnterEvent *event) override;
//    void dragMoveEvent(QDragMoveEvent *event) override;
//    void dragLeaveEvent(QDragLeaveEvent *event) override;
//    void dropEvent(QDropEvent *event) override;
//#endif
//
//    void showEvent(QShowEvent *event) override;
//    void hideEvent(QHideEvent *event) override;
//    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
//
//    // Misc. protected functions
//    void changeEvent(QEvent *) override;
//
private:
	QFont glueFont;
	QSizePolicy glueSizePolicy;

	MonoObject* _thisObject;

	friend class GlueMainWindow;
	friend class GlueDialog;
};
