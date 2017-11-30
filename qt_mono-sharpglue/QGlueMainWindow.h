#pragma once
#include <QMainWindow>
#include "QGlueDialog.h"

class GlueMainWindow : public QMainWindow
{
public:
    GlueMainWindow(MonoObject* thisObject, GlueWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~GlueMainWindow();

protected:
	void keyPressEvent(QKeyEvent *) override;
	void keyReleaseEvent(QKeyEvent *) override;

private:
	MonoObject* _thisObject;
};
