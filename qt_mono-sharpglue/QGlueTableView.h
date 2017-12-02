#pragma once
#include <QTableView>
#include "QGlueWidget.h"

class Q_WIDGETS_EXPORT GlueTableView : public QTableView
{
    Q_OBJECT
public:
    explicit GlueTableView(QWidget *parent=0);
    explicit GlueTableView(MonoObject* thisObject, GlueWidget *parent=0);

//protected:
//    // Event handlers
//    bool event(QEvent *event)  override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
//    void mouseDoubleClickEvent(QMouseEvent *event) override;
//    void mouseMoveEvent(QMouseEvent *event) override;
//
//	void keyPressEvent(QKeyEvent *) override;
//	void keyReleaseEvent(QKeyEvent *) override;

private:
    MonoObject* _thisObject;
};

