#include "QGlueProgressBar.h"

GlueProgressBar::GlueProgressBar(MonoObject* thisObject, QWidget* parent) : QProgressBar(parent)
{
	_thisObject = thisObject;
}
