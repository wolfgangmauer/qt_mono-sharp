#pragma once
#include <QStandardItemModel>
#include "QGlueWidget.h"

class GlueStandardItemModel : QStandardItemModel
{
public:
    GlueStandardItemModel(MonoObject* thisObject, GlueObject* parent=0);
private:
    MonoObject* _thisObject;
};