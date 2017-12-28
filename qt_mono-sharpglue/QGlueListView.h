#pragma once
#include <QListView>
#include "QGlueWidget.h"

class GlueListView : public QListView
{
#define BaseClass QListView
#include "internalevents.h"
public:
    explicit GlueListView(MonoObject* thisObject, QWidget *parent=0);
    ~GlueListView();
private:
	void onpressed(const QModelIndex &index);

private:
    guint32 _thisObject;
};