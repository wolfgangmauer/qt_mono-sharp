#include "QGlueStandardItemModel.h"

GlueStandardItemModel::GlueStandardItemModel(MonoObject* thisObject, GlueObject* parent)
	: QStandardItemModel(parent)
{
	_thisObject = thisObject;
}

GlueStandardItemModel::GlueStandardItemModel(MonoObject* thisObject, int rows, int cols, GlueObject* parent)
	: QStandardItemModel(rows, cols, parent)
{
	_thisObject = thisObject;
}
