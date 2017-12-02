﻿#pragma once
#include <QMainWindow>
#include "QGlueEvents.h"
#include "QGlueDialog.h"

class GlueMainWindow : public QMainWindow
{
public:
    GlueMainWindow(MonoObject* thisObject, GlueWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~GlueMainWindow();

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
