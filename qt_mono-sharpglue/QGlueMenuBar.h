#pragma once
#include <QMenuBar>
#include "QGlueWidget.h"

class GlueMenuBar : public QMenuBar
{
#define BaseClass QMenuBar
#include "internalevents.h"
public:
    GlueMenuBar(MonoObject* thisObject, QWidget* parent);
    ~GlueMenuBar();
private:
	void ontriggered(QAction *action);
 	void onhovered(QAction *action);

private:
    guint32 _thisObject;
};