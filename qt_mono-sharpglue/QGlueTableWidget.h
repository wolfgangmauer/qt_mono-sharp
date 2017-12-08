#pragma once
#include <QTableWidget>
#include "QGlueWidget.h"

class GlueTableWidget : public QTableWidget
{
#define BaseClass QTableWidget
#include "internalevents.h"
public:
    explicit GlueTableWidget(MonoObject* thisObject, QWidget *parent=0);

private:
    MonoObject* _thisObject;
};
