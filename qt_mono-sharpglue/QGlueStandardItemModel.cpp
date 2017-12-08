#include "QGlueStandardItemModel.h"

GlueStandardItemModel::GlueStandardItemModel(MonoObject* thisObject, GlueObject* parent)
	: QStandardItemModel(parent)
{
	_thisObject = thisObject;
}