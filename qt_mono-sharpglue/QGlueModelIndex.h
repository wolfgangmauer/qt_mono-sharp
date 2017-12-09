#pragma once
#include <QStandardItemModel>
#include "QGlueWidget.h"

class GlueModelIndex : public QModelIndex
{
public:
    GlueModelIndex(MonoObject* thisObject);
private:
    MonoObject* _thisObject;
};