#pragma once
#include <QProgressBar>
#include "QGlueWidget.h"

class GlueProgressBar : public QProgressBar
{
#define BaseClass QProgressBar
#include "internalevents.h"
public:
    GlueProgressBar(MonoObject* thisObject, QWidget* parent = 0);
private:
    MonoObject* _thisObject;
};
