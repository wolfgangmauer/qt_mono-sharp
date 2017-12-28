#include <QtUiTools>
#include "QGlueWidget.h"

class GlueUiLoader : public QUiLoader
{
public:
    GlueUiLoader(MonoObject* thisObject, QObject* parent = 0);
    ~GlueUiLoader();

    QWidget* loadFile(QFile* uiFile, QWidget* parentWidget);
	QLayout* createLayout(const QString& className, QObject* parent = 0, const QString& name = QString()) override;
	QWidget* createWidget(const QString& className, QWidget* parent = 0, const QString& name = QString()) override;

private:
	guint32 _thisObject;
};