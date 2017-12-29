#pragma once
#include <QComboBox>
#include "QGlueWidget.h"

class GlueComboBox : public QComboBox
{
public:
    GlueComboBox(MonoObject* thisObject, QWidget *parent=0);
    ~GlueComboBox();

private:
    void onindexactivated(int index);
    void ontextactivated(const QString &);

private:
    guint32 _thisObject;
};
