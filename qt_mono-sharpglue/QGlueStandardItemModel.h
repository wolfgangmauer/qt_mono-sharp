#pragma once
#include <QStandardItemModel>
#include "QGlueWidget.h"

class GlueStandardItemModel : public QStandardItemModel
{
public:
    GlueStandardItemModel(MonoObject* thisObject, GlueObject* parent=0);
    GlueStandardItemModel(MonoObject* thisObject, int rows, int cols, GlueObject* parent=0);

private:
    MonoObject* _thisObject;
};