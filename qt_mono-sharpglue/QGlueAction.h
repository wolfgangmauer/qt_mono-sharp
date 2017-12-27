#pragma once
#include <QAction>
#include "QGlueWidget.h"

class GlueAction : public QAction
{
public:
    GlueAction(MonoObject* thisObject, QObject* parent);
    GlueAction(MonoObject* thisObject, const QString& text, QObject* parent);
    ~GlueAction();

private:
	void ontriggered(bool checked);

private:
    guint32 _thisObject;
};

