#include "QGlueProgressBar.h"

GlueProgressBar::GlueProgressBar(MonoObject* thisObject, GlueWidget* parent) : QProgressBar(parent)
{
	_thisObject = thisObject;
}
