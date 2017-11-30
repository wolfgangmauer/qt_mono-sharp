#pragma once
#include <stdint.h>
#include <QWidget>
#include <QKeyEvent>
#include "QGlueObject.h"
#include "QGlueFont.h"
#include "QGlueSizePolicy.h"

class GlueWidget : public QWidget
{
    //Q_OBJECT
public:
    GlueWidget(MonoObject* thisObject, GlueWidget* parent = 0, Qt::WindowFlags f = 0);
//	~GlueWidget();

	void geometry(int*, int*, int*, int*);
	GlueFont* font();
	GlueSizePolicy* sizePolicy();

protected:
	void keyPressEvent(QKeyEvent *) override;
	void keyReleaseEvent(QKeyEvent *) override;

	static void dokeyPressEvent(MonoObject* thisObject, QKeyEvent *keyEvent);
	static void dokeyReleaseEvent(MonoObject* thisObject, QKeyEvent *keyEvent);
//
private:
	QFont glueFont;
	QSizePolicy glueSizePolicy;

	MonoObject* _thisObject;
	MonoClass* _klass;
	MonoMethod* _keyPressEventMethod;
	MonoMethod* _keyReleaseEventMethod;

	friend class GlueMainWindow;
	friend class GlueDialog;
};

//GlueWidget* qt_widget_new(MonoObject* obj,GlueWidget* parent, uint32_t f);
//void qt_widget_show(GlueWidget*);
//
//extern "C" void qt_widget_stylesheet_set(QWidget* widget, char* stylesheet);
//extern "C" void qt_widget_fixedsize_set(QWidget* widget, uint32_t w, uint32_t h);
//extern "C" void qt_widget_shown(QWidget* widget);
//extern "C" void qt_widget_hide(QWidget* widget);
//extern "C" void qt_widget_resize(QWidget* widget, uint32_t w, uint32_t h);
//extern "C" void qt_widget_windowopacity_set(QWidget* widget, float windowopacity);
//extern "C" float qt_widget_windowopacity_get(QWidget* widget);
//extern "C" GlueFont* qt_widget_font_get(QWidget* widget);
//extern "C" void qt_widget_font_set(QWidget* widget, GlueFont* font);
//extern "C" void qt_widget_windowflags_set(QWidget* widget, uint32_t type);
//extern "C" uint32_t qt_widget_windowflags_get(QWidget* widget);
//extern "C" void qt_widget_attribute_set(QWidget* widget, uint32_t attribute);
//extern "C" void qt_widget_sizepolicyhv_set(QWidget* widget, uint32_t horizontal, uint32_t vertical);
//extern "C" void qt_widget_sizepolicy_set(QWidget* widget, QSizePolicy* sizePolicy);
//extern "C" QSizePolicy* qt_widget_sizepolicy_get(QWidget* widget);
//extern "C" void qt_widget_minimumsize_get(QWidget* widget, uint32_t* w, uint32_t* h);
//extern "C" void qt_widget_minimumsize_set(QWidget* widget, uint32_t w, uint32_t h);
//extern "C" void qt_widget_maximumsize_get(QWidget* widget, uint32_t* w, uint32_t* h);
//extern "C" void qt_widget_maximumsize_set(QWidget* widget, uint32_t w, uint32_t h);
//extern "C" uint32_t qt_widget_windowmodality_get(QWidget* widget);
//extern "C" void qt_widget_windowmodality_set(QWidget* widget, uint windowModality);
//extern "C" uint32_t qt_widget_focuspolicy_get(QWidget* widget);
//extern "C" void qt_widget_focuspolicy_set(QWidget* widget, uint32_t focusPolicy);
//extern "C" uint32_t qt_widget_contextmenupolicy_get(QWidget* widget);
//extern "C" void qt_widget_contextmenupolicy_set(QWidget* widget, uint32_t contextMenuPolicy);
//extern "C" bool qt_widget_autofillbackground_get(QWidget* widget);
//extern "C" void qt_widget_autofillbackground_set(QWidget* widget, bool autofillbackground);
