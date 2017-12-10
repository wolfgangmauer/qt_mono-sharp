#pragma once
#include <QStandardItemModel>
#include <QVariant>
#include <QModelIndex>
#include "QGlueWidget.h"

class GlueModelIndex : public QModelIndex
{
public:
    GlueModelIndex(MonoObject* thisObject);
private:
    MonoObject* _thisObject;
};