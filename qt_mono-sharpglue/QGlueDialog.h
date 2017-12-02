#pragma once
#include <QDialog>
#include "QGlueWidget.h"

class GlueDialog : public QDialog
{
    //Q_OBJECT
public:
    GlueDialog(MonoObject* thisObject, GlueWidget* parent = 0, Qt::WindowFlags f = 0);

protected:
    // Event handlers
    bool event(QEvent *event)  override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

	void keyPressEvent(QKeyEvent *) override;
	void keyReleaseEvent(QKeyEvent *) override;

private:
	MonoObject* _thisObject;
};
