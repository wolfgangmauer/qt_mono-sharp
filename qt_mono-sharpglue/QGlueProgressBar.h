#pragma once
#include <QProgressBar>
#include "QGlueWidget.h"

class GlueProgressBar : public QProgressBar
{
	Q_OBJECT
public:
    GlueProgressBar(MonoObject* thisObject, GlueWidget* parent = 0);
};
