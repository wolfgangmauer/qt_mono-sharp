#pragma once
#include <QTableView>
#include "QGlueWidget.h"

class GlueTableView : public QTableView
{
    //Q_OBJECT
public:
    GlueTableView(MonoObject* thisObject, GlueWidget *parent=0);
private:
    MonoObject* _thisObject;
};

