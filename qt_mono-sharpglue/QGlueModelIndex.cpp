#include "QGlueModelIndex.h"

GlueModelIndex::GlueModelIndex(MonoObject* thisObject)
	: QModelIndex()
{
	_thisObject = mono_gchandle_new(thisObject, TRUE);
}
