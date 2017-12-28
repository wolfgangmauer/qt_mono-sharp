#pragma once
#include <QTableView>
#include "QGlueWidget.h"

class GlueTableView : public QTableView
{
#define BaseClass QTableView
#include "internalevents.h"
public:
    explicit GlueTableView(MonoObject* thisObject, QWidget *parent=0);
    ~GlueTableView();
private:
	void onpressed(const QModelIndex &index);

private:
    guint32 _thisObject;
};