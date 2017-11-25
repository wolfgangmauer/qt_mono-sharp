#include <QtUiTools>
#include "QGlueWidget.h"

class GlueUiLoader : public QUiLoader
{
public:
    GlueUiLoader(MonoObject* thisObject, GlueObject* parent = 0);
    QWidget* loadFile(QFile* uiFile, GlueWidget* parentWidget);

private:
	MonoObject* _thisObject;
};