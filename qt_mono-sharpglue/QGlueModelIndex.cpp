#include "QGlueModelIndex.h"

GlueModelIndex::GlueModelIndex(MonoObject* thisObject)
	: QModelIndex()
{
	_thisObject = thisObject;
}
