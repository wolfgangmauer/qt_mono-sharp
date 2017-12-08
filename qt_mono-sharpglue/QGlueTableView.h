#pragma once
#include <QTableView>
#include "QGlueWidget.h"

class GlueTableView : public QTableView
{
#define BaseClass QTableView
#include "internalevents.h"
public:
    explicit GlueTableView(MonoObject* thisObject, QWidget *parent=0);

private:
    MonoObject* _thisObject;
};

