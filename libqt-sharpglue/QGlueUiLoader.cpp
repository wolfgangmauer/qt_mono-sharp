#include "QGlueUiLoader.h"

GlueUiLoader::GlueUiLoader(MonoObject* thisObject, GlueObject* parent) : QUiLoader(parent)
{
	_thisObject = thisObject;
}

QWidget* GlueUiLoader::loadFile(QFile* uiFile, GlueWidget* parentWidget)
{
	return load(uiFile, parentWidget);
}