#pragma once
#include <QFrame>
#include "QGlueWidget.h"

class GlueFrame : public QFrame
{
#define BaseClass QFrame
#include "internalevents.h"
public:
    GlueFrame(MonoObject* thisObject, QWidget* parent = 0);
    ~GlueFrame();
private:
	guint32 _thisObject;
};
