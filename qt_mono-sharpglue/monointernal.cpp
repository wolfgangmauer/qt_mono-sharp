#include <QScreen>

#include "QGlueApplication.h"
#include "QGlueLabel.h"
#include "QGlueFrame.h"
#include "QGlueBoxLayout.h"
#include "QGlueGridLayout.h"
#include "QGlueHBoxLayout.h"
#include "QGlueVBoxLayout.h"
#include "QGlueLayout.h"
#include "QGlueUiLoader.h"
#include "QGlueProgressBar.h"
#include "QGlueStandardItemModel.h"
#include "QGlueModelIndex.h"
#include "QGlueTableView.h"
#include "QGlueTableWidget.h"
#include "QGlueListView.h"
#include "QGlueListWidget.h"
#include "QGlueAction.h"
#include "QGlueMenu.h"
#include "QGlueMenuBar.h"
#include "QGlueToolBar.h"
#include "QGlueCheckBox.h"
#include "QGluePushButton.h"
#include "QGlueToolButton.h"
#include "QGlueCommandLinkButton.h"

#include <QtPlatformHeaders/qeglfsfunctions.h>

//Warning: The data referred to by argc and argv must stay valid for the entire lifetime of the QApplication object.
//In addition, argc must be greater than zero and argv must contain at least one valid character string." 
static int argc;
static char** _argv;
GlueApplication* qt_application_new(MonoObject* thisObject, MonoArray* argv)
{
	GlueApplication* retVal;
	argc = mono_array_length (argv);
	_argv = new char*[argc];
	for (int i = 0; i < argc; i++)
		_argv[i] = mono_string_to_utf8(mono_array_get (argv, MonoString*, i));
	retVal = new GlueApplication(thisObject, argc, _argv);
	return retVal;
}

int qt_application_exec(GlueApplication* application)
{
	return application->exec();
}

void qt_coreapplication_quit()
{
	QCoreApplication::quit();
}

void qt_eglfs_loadkeymap(MonoString* keymap)
{
	char* p = mono_string_to_utf8(keymap);
	QEglFSFunctions::loadKeymap(p);
	g_free(p);
}

QStyle* qt_application_style_get()
{
	return QApplication::style();
}

void qt_application_style_set(QStyle* style)
{
	QApplication::setStyle(style);
}

QWidget* qt_application_activewindow_get()
{
	return QApplication::activeWindow();
}

void qt_application_postevent(QObject* receiver, QEvent* event, int priority)
{
	QCoreApplication::postEvent(receiver, event, priority);
}

void qt_application_events_process(QEventLoop::ProcessEventsFlags flags)
{
	QCoreApplication::processEvents(flags);
}

void qt_application_attribute_set(Qt::ApplicationAttribute attribute)
{
	GlueApplication::setAttribute(attribute);
}

QScreen* qt_guiapplication_primaryscreen_get()
{
	return QGuiApplication::primaryScreen();
}

QStyle* qt_stylefactory_create(MonoString* name)
{
	char* p = mono_string_to_utf8(name);
	QStyle* retVal = QStyleFactory::create(p);
	g_free(p);
	return retVal;
}

extern "C" MonoClass* mono_class_bind_generic_parameters(MonoClass *klass, int type_argc, MonoType **types, bool is_dynamic);

MonoArray* qt_stylefactory_keys()
{
	auto keyList = QStyleFactory::keys();
	MonoArray* retVal = mono_array_new (mono_domain_get (), mono_get_string_class(), keyList.size());

	int i = 0;
	foreach (const QString &str, keyList)
	{
		printf("%s\n", str.toStdString().c_str());
		auto _string = mono_string_new (mono_domain_get (), str.toStdString().c_str());
		mono_array_set (retVal, gpointer, i, _string);
		i++;
	}
	fflush(stdout);
//
//	MonoAssemblyName *aname = mono_assembly_name_new ("mscorlib");
//	MonoAssembly* mscorlibAssembly = mono_assembly_loaded(aname);
//	MonoImage* systemImage = mono_assembly_get_image(mscorlibAssembly);
//	mono_assembly_name_free (aname);
//
//	MonoClass* list = mono_class_from_name(systemImage, "System.Collections.Generic", "List`1");
//	MonoClass* strcls = mono_class_from_name(systemImage, "System", "String");
//	printf("str class: %p\n", strcls);
//	MonoType* strtype = mono_class_get_type(strcls);
//	printf("str type: %p\n", strtype);
//	MonoType* types[1];
//	types[0] = strtype;
//	list = mono_class_bind_generic_parameters(list, 1, types, false);
//	printf("list[string] class: %p\n", list);
//	MonoObject* obj = mono_object_new(mono_domain_get (), list);
//	printf("list[string] created: %p\n", obj);
	//char* p = mono_string_to_utf8(name);
	//QStyle* retVal = QStyleFactory::create(p);
	//g_free(p);
	return retVal;
}

MonoString* qt_objectname_get(GlueObject* obj)
{
	return mono_string_new(mono_domain_get (), obj->objectName().toStdString().c_str());
}

void qt_objectname_set(GlueObject* obj, MonoString* name)
{
	char* p = mono_string_to_utf8(name);
	obj->setObjectName(p);
	g_free(p);
}

GlueUiLoader* qt_uiloader_new(MonoObject* obj, GlueObject* parent)
{
	return new GlueUiLoader(obj, parent);
}

QWidget* qt_uiloader_load(GlueUiLoader* loader, MonoString* uiFile, QWidget* parentWidget)
{
	char* p = mono_string_to_utf8(uiFile);
	QFile file(p);
	g_free(p);
	return loader->loadFile(&file, parentWidget);
}

QObject* qt_object_find(QWidget* startFrom, MonoString* name)
{
	QObject* retVal = NULL;
	char* p = mono_string_to_utf8(name);
	retVal = startFrom->findChild<QObject*>(QLatin1String(p));
	g_free(p);
	return retVal;
}

GlueWidget* qt_widget_new(MonoObject* obj, QWidget* parent, Qt::WindowFlags f)
{
	return new GlueWidget(obj, parent, f);
}

void qt_widget_delete(GlueWidget* widget)
{
	delete widget;
}

MonoString* qt_widget_windowtitle_get(QWidget* widget)
{
	return mono_string_new(mono_domain_get (), widget->windowTitle().toStdString().c_str());
}

void qt_widget_windowtitle_set(QWidget* widget, MonoString* windowtitle)
{
	char* p = mono_string_to_utf8(windowtitle);
	widget->setWindowTitle(p);
	g_free(p);
}

QWidget* qt_widget_parent_get(QWidget* widget)
{
	return (QWidget*)widget->parentWidget();
}

void qt_widget_parent_set(QWidget* widget, QWidget* parent)
{
	widget->setParent(parent);
}

void qt_widget_show(QWidget* widget)
{
	widget->show();
}

void qt_widget_fullscreen_show(QWidget* widget)
{
	widget->showFullScreen();
}

void qt_widget_hide(QWidget* widget)
{
	widget->hide();
}

void qt_widget_update(QWidget* widget)
{
	widget->update();
}

void qt_widget_move(QWidget* widget, int x, int y)
{
	widget->move(x, y);
}

void qt_widget_attribute_set(QWidget* widget, Qt::WidgetAttribute attribute)
{
	widget->setAttribute(attribute);
}

Qt::WindowFlags qt_widget_windowflags_get(QWidget* widget)
{
	return widget->windowFlags();
}

void qt_widget_windowflags_set(QWidget* widget, Qt::WindowFlags type)
{
	widget->setWindowFlags(type);
}

void qt_widget_stylesheet_set(QWidget* widget, MonoString* stylesheet)
{
	char* p = mono_string_to_utf8(stylesheet);
	widget->setStyleSheet(p);
	g_free(p);
}

void qt_widget_fixedsize_set(QWidget* widget, uint32_t w, uint32_t h)
{
	widget->setFixedSize(w, h);
}

void qt_widget_resize(QWidget* widget, uint32_t w, uint32_t h)
{
	widget->resize(w, h);
}

QSize* qt_widget_size_get(QWidget* widget)
{
	return new QSize(widget->size());
}

void qt_widget_size_set(QWidget* widget, QSize* size)
{
	widget->resize(*size);
}

QSize* qt_widget_sizehint_get(QWidget* widget)
{
	return new QSize(widget->sizeHint());
}

int qt_widget_width_get(QWidget* widget)
{
	return widget->width();
}

int qt_widget_height_get(QWidget* widget)
{
	return widget->height();
}

void qt_widget_font_set(QWidget* widget, QFont* font)
{
	widget->setFont(*font);
}

QFont* qt_widget_font_get(QWidget* widget)
{
	return new QFont(widget->font());
}

double qt_widget_windowopacity_get(QWidget* widget)
{
	return widget->windowOpacity();
}

void qt_widget_windowopacity_set(QWidget* widget, double windowopacity)
{
	widget->setWindowOpacity(windowopacity);
}

QSizePolicy* qt_widget_sizepolicy_get(QWidget* widget)
{
	return new QSizePolicy(widget->sizePolicy());
}

void qt_widget_sizepolicy_set(QWidget* widget, QSizePolicy* sizePolicy)
{
	widget->setSizePolicy(*sizePolicy);
}

void qt_widget_sizepolicyhv_set(QWidget* widget, QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical)
{
	widget->setSizePolicy(horizontal, vertical);
}

QSize* qt_widget_minimumsize_get(QWidget* widget)
{
	return new QSize(widget->minimumSize());
}

void qt_widget_minimumsize_set(QWidget* widget, uint32_t w, uint32_t h)
{
	QSize s(w, h);
	widget->setMinimumSize(s);
}

QSize* qt_widget_maximumsize_get(QWidget* widget)
{
	return new QSize(widget->maximumSize());
}

void qt_widget_maximumsize_set(QWidget* widget, uint32_t w, uint32_t h)
{
	QSize s(w, h);
	widget->setMaximumSize(s);
}

int qt_widget_minimumwidth_get(QWidget* widget)
{
	return widget->minimumWidth();
}

void qt_widget_minimumwidth_set(QWidget* widget, int min)
{
	return widget->setMinimumWidth(min);
}

int qt_widget_maximumwidth_get(QWidget* widget)
{
	return widget->maximumWidth();
}

void qt_widget_maximumwidth_set(QWidget* widget, int max)
{
	return widget->setMaximumWidth(max);
}

int qt_widget_minimumheight_get(QWidget* widget)
{
	return widget->minimumHeight();
}

void qt_widget_minimumheight_set(QWidget* widget, int min)
{
	return widget->setMinimumHeight(min);
}

int qt_widget_maximumheight_get(QWidget* widget)
{
	return widget->maximumHeight();
}

void qt_widget_maximumheight_set(QWidget* widget, int max)
{
	return widget->setMaximumHeight(max);
}

Qt::WindowModality qt_widget_windowmodality_get(QWidget* widget)
{
	return widget->windowModality();
}

void qt_widget_windowmodality_set(QWidget* widget, Qt::WindowModality windowModality)
{
	widget->setWindowModality(windowModality);
}

Qt::LayoutDirection qt_widget_layoutdirection_get(QWidget* widget)
{
	return widget->layoutDirection();
}

void qt_widget_layoutdirection_set(QWidget* widget, Qt::LayoutDirection layoutdirection)
{
	widget->setLayoutDirection(layoutdirection);
}

Qt::FocusPolicy qt_widget_focuspolicy_get(QWidget* widget)
{
	return widget->focusPolicy();
}

void qt_widget_focuspolicy_set(QWidget* widget, Qt::FocusPolicy focusPolicy)
{
	widget->setFocusPolicy(focusPolicy);
}

Qt::ContextMenuPolicy qt_widget_contextmenupolicy_get(QWidget* widget)
{
	return widget->contextMenuPolicy();
}

void qt_widget_contextmenupolicy_set(QWidget* widget, Qt::ContextMenuPolicy contextMenuPolicy)
{
	widget->setContextMenuPolicy(contextMenuPolicy);
}

bool qt_widget_autofillbackground_get(QWidget* widget)
{
	return widget->autoFillBackground();
}

void qt_widget_autofillbackground_set(QWidget* widget, bool autofillbackground)
{
	widget->setAutoFillBackground(autofillbackground);
}

void qt_widget_action_add(QWidget* widget, QAction* action)
{
	widget->addAction(action);
}

QLayout* qt_widget_layout_get(QWidget* widget)
{
	return widget->layout();
}

void qt_widget_layout_set(QWidget* widget, QLayout* layout)
{
	return widget->setLayout(layout);
}

void qt_widget_adjustsize(QWidget* widget)
{
	widget->adjustSize();
}

QRect* qt_widget_geometry_get(QWidget* widget)
{
	return new QRect(widget->geometry());
}

void qt_widget_geometry_set(QWidget* widget, QRect* rect)
{
	widget->setGeometry(*rect);
}

bool qt_widget_enabled_get(QWidget* widget)
{
	return widget->isEnabled();
}

void qt_widget_enabled_set(QWidget* widget, bool enabled)
{
	widget->setEnabled(enabled);
}

void qt_widget_updategeometry(QWidget* widget)
{
	widget->updateGeometry();
}

GlueBoxLayout* qt_boxlayout_new(MonoObject* thisObject, QBoxLayout::Direction dir, QWidget* parent)
{
	return new GlueBoxLayout(thisObject, dir, parent);
}

void qt_boxlayout_widget_add(GlueBoxLayout* layout, QWidget* widget, int stretch, Qt::Alignment alignment)
{
	layout->addWidget(widget, stretch, alignment);
}

void qt_boxlayout_layout_add(GlueBoxLayout* layout, GlueLayout* widget, int stretch)
{
	layout->addLayout(widget, stretch);
}

QBoxLayout::Direction qt_boxlayout_direction_get(GlueBoxLayout* boxlayout)
{
	return boxlayout->direction();
}

void qt_boxlayout_direction_set(GlueBoxLayout* boxlayout, QBoxLayout::Direction direction)
{
	return boxlayout->setDirection(direction);
}

GlueGridLayout* qt_gridlayout_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueGridLayout(thisObject, parent);
}

void qt_gridlayout_widget_add(GlueGridLayout* gridlayout, QWidget* widget)
{
	gridlayout->addWidget(widget);
}

void qt_gridlayout_widget_alignment_add(GlueGridLayout* gridlayout, QWidget* widget, int row, int col, Qt::Alignment alignment)
{
	gridlayout->addWidget(widget, row, col, alignment);
}

void qt_gridlayout_widget_span_add(GlueGridLayout* gridlayout, QWidget* widget, int row, int col, int rowSpan, int colSpan, Qt::Alignment alignment)
{
	gridlayout->addWidget(widget, row, col, rowSpan, colSpan, alignment);
}

GlueDialog* qt_dialog_new(MonoObject* thisObject, QWidget* parent, uint32_t f)
{
	return new GlueDialog(thisObject, parent, (Qt::WindowFlags)f);
}

void qt_dialog_delete(GlueDialog* dialog)
{
	delete dialog;
}

int qt_dialog_exec(GlueDialog* dialog)
{
	return dialog->exec();
}

void qt_dialog_accept(GlueDialog* dialog)
{
	dialog->accept();
}

void qt_dialog_reject(GlueDialog* dialog)
{
	dialog->reject();
}

bool qt_dialog_modal_get(GlueDialog* dialog)
{
	return dialog->isModal();
}

void qt_dialog_modal_set(GlueDialog* dialog, bool modal)
{
	dialog->setModal(modal);
}

GlueVBoxLayout* qt_vboxlayout_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueVBoxLayout(thisObject, parent);
}

GlueHBoxLayout* qt_hboxlayout_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueHBoxLayout(thisObject, parent);
}

GlueFrame* qt_frame_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueFrame(thisObject, parent);
}

QFrame::Shape qt_frame_shape_get(GlueFrame* widget)
{
	return widget->frameShape();
}

void qt_frame_shape_set(GlueFrame* widget, QFrame::Shape shape)
{
	widget->setFrameShape(shape);
}

QFrame::Shadow qt_frame_shadow_get(GlueFrame* widget)
{
	return widget->frameShadow();
}

void qt_frame_shadow_set(GlueFrame* widget, QFrame::Shadow shadow)
{
	widget->setFrameShadow(shadow);
}

int qt_frame_width_get(GlueFrame* widget)
{
	return widget->frameWidth();
}

int qt_frame_linewidth_get(GlueFrame* widget)
{
	return widget->lineWidth();
}

void qt_frame_linewidth_set(GlueFrame* widget, int lineWidth)
{
	widget->setLineWidth(lineWidth);
}

int qt_progressbar_value_get(GlueProgressBar* widget)
{
	return widget->value();
}

void qt_progressbar_value_set(GlueProgressBar* widget, int value)
{
	widget->setValue(value);
}

MonoString* qt_progressbar_format_get(GlueProgressBar* widget)
{
	return mono_string_new(mono_domain_get (), widget->format().toStdString().c_str());
}

void qt_progressbar_format_set(GlueProgressBar* widget, MonoString* format)
{
	char* p = mono_string_to_utf8(format);
	widget->setFormat(p);
	g_free(p);
}


int qt_progressbar_minimum_get(GlueProgressBar* widget)
{
	return widget->minimum();
}

void qt_progressbar_minimum_set(GlueProgressBar* widget, int value)
{
	widget->setMinimum(value);
}

int qt_progressbar_maximum_get(GlueProgressBar* widget)
{
	return widget->maximum();
}

void qt_progressbar_maximum_set(GlueProgressBar* widget, int value)
{
	widget->setMaximum(value);
}

void qt_progressbar_range_set(GlueProgressBar* widget, int min, int max)
{
	widget->setRange(min, max);
}

GlueLabel* qt_label_new(MonoObject* thisObject, QWidget* parent, Qt::WindowFlags f)
{
	return new GlueLabel(thisObject, parent, f);
}

GlueLabel* qt_label_new_with_text(MonoObject* thisObject, MonoString* text, QWidget* parent, Qt::WindowFlags f)
{
	GlueLabel* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new GlueLabel(thisObject, p, parent, f);
	g_free(p);
	return retVal;
}

MonoString* qt_label_text_get(GlueLabel* label)
{
	return mono_string_new(mono_domain_get (), label->text().toStdString().c_str());
}

void qt_label_text_set(GlueLabel* label, MonoString* text)
{
	char* p = mono_string_to_utf8(text);
	label->setText(p);
	g_free(p);
}

void qt_label_clear(GlueLabel* label)
{
	label->clear();
}

const QPixmap* qt_label_pixmap_get(GlueLabel* label)
{
	return label->pixmap();
}

void qt_label_pixmap_set(GlueLabel* label, QPixmap* pixmap)
{
	label->setPixmap(*pixmap);
}

Qt::Alignment qt_label_alignment_get(GlueLabel* label)
{
	return label->alignment();
}

void qt_label_alignment_set(GlueLabel* label, Qt::Alignment alignment)
{
	label->setAlignment(alignment);
}

void qt_label_indent_set(GlueLabel* label, int indent)
{
	label->setIndent(indent);
}

int qt_label_indent_get(GlueLabel* label)
{
	return label->indent();
}

Qt::TextInteractionFlags qt_label_textinteractionflags_get(GlueLabel* label)
{
	return label->textInteractionFlags();
}

void qt_label_textinteractionflags_set(GlueLabel* label, Qt::TextInteractionFlags flags)
{
	label->setTextInteractionFlags(flags);
}

Qt::TextFormat qt_label_textformat_get(GlueLabel* label)
{
	return label->textFormat();
}

void qt_label_textformat_set(GlueLabel* label, Qt::TextFormat textFormat)
{
	label->setTextFormat(textFormat);
}

bool qt_label_scaledcontents_get(GlueLabel* label)
{
	return label->hasScaledContents();
}

void qt_label_scaledcontents_set(GlueLabel* label, bool scaled)
{
	label->setScaledContents(scaled);
}

bool qt_label_wordwrap_get(GlueLabel* label)
{
	return label->wordWrap();
}

void qt_label_wordwrap_set(GlueLabel* label, bool wrap)
{
	label->setWordWrap(wrap);
}

int qt_label_margin_get(GlueLabel* label)
{
	return label->margin();
}

void qt_label_margin_set(GlueLabel* label, int margin)
{
	label->setMargin(margin);
}

GlueCheckBox* qt_checkbox_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueCheckBox(thisObject, parent);
}

GlueCheckBox* qt_checkbox_new_with_text(MonoObject* thisObject, MonoString* text, QWidget* parent)
{
	GlueCheckBox* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new GlueCheckBox(thisObject, p, parent);
	g_free(p);
	return retVal;
}

QSize* qt_checkbox_sizehint_get(GlueCheckBox* checkbox)
{
	return new QSize(checkbox->sizeHint());
}

bool qt_checkbox_tristate_get(GlueCheckBox* checkbox)
{
	return checkbox->isTristate();
}

void qt_checkbox_tristate_set(GlueCheckBox* checkbox, bool tristate)
{
	return checkbox->setTristate(tristate);
}

GluePushButton* qt_pushbutton_new(MonoObject* thisObject, QWidget* parent)
{
	return new GluePushButton(thisObject, parent);
}

GluePushButton* qt_pushbutton_new_with_text(MonoObject* thisObject, MonoString* text, QWidget* parent)
{
	GluePushButton* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new GluePushButton(thisObject, p, parent);
	g_free(p);
	return retVal;
}

QSize* qt_pushbutton_sizehint_get(GluePushButton* button)
{
	return new QSize(button->sizeHint());
}

GlueCommandLinkButton* qt_commandlinkbutton_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueCommandLinkButton(thisObject, parent);
}

GlueCommandLinkButton* qt_commandlinkbutton_new_with_text(MonoObject* thisObject, MonoString* text, QWidget* parent)
{
	GlueCommandLinkButton* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new GlueCommandLinkButton(thisObject, p, parent);
	g_free(p);
	return retVal;
}

QSize* qt_commandlinkbutton_sizehint_get(GlueCommandLinkButton* button)
{
	return new QSize(button->sizeHint());
}

GlueToolButton* qt_toolbutton_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueToolButton(thisObject, parent);
}

QSize* qt_toolbutton_sizehint_get(GlueToolButton* button)
{
	return new QSize(button->sizeHint());
}

GlueProgressBar* qt_progressbar_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueProgressBar(thisObject, parent);
}

void qt_layout_widget_add(GlueLayout* layout, QWidget* widget)
{
	layout->addWidget(widget);
}

QWidget* qt_layout_parent_get(GlueLayout* layout)
{
	return layout->parentWidget();
}

void qt_layout_contentsmargins_get(QLayout* widget, int* left, int* top, int* right, int* bottom)
{
	widget->getContentsMargins(left, top, right, bottom);
}

void qt_layout_contentsmargins_set(QLayout* widget, int left, int top, int right, int bottom)
{
	widget->setContentsMargins(left, top, right, bottom);
}

int qt_layout_spacing_get(QLayout* layout)
{
	return layout->spacing();
}

void qt_layout_spacing_set(QLayout* layout, int spacing)
{
	layout->setSpacing(spacing);
}

int qt_layout_margin_get(QLayout* layout)
{
	return layout->margin();
}

void qt_layout_margin_set(QLayout* layout, int margin)
{
	layout->setMargin(margin);
}

QLayout::SizeConstraint qt_layout_sizeconstraint_get(QLayout* layout)
{
	return layout->sizeConstraint();
}

void qt_layout_sizeconstraint_set(QLayout* layout, QLayout::SizeConstraint sizeConstraint)
{
	return layout->setSizeConstraint(sizeConstraint);
}

QRect* qt_layout_geometry_get(QLayout* layout)
{
	return new QRect(layout->geometry());
}

void qt_layout_geometry_set(GlueLayout* layout, QRect* rect)
{
	layout->setGeometry(*rect);
}

QFont* qt_font_new()
{
	return new QFont();
}

QFont* qt_font_new_with_params(MonoString* fontfamily, int pointSize, int weight, bool italic)
{
	QFont* retVal;
	char* p = mono_string_to_utf8(fontfamily);
	retVal = new QFont(QLatin1String(p), pointSize, weight, italic);
	g_free(p);
	return retVal;
}

MonoString* qt_font_family_get(QFont* font)
{
	return mono_string_new(mono_domain_get (), font->family().toStdString().c_str());
}

void qt_font_family_set(QFont* obj, MonoString* fontfamily)
{
	char* p = mono_string_to_utf8(fontfamily);
	obj->setFamily(p);
	g_free(p);
}

int qt_font_pointsize_get(QFont* obj)
{
	return obj->pointSize();
}

void qt_font_pointsize_set(QFont* obj, int pointsize)
{
	obj->setPointSize(pointsize);
}

GlueMainWindow* qt_mainwindow_new(MonoObject* obj, QWidget* parent, Qt::WindowFlags f)
{
	return new GlueMainWindow(obj, parent, f);
}

QMenuBar* qt_mainwindow_menubar_get(GlueMainWindow* mainwindow)
{
	return mainwindow->menuBar();
}

void qt_mainwindow_menubar_set(GlueMainWindow* mainwindow, GlueMenuBar* menubar)
{
	mainwindow->setMenuBar(menubar);
}

QSizePolicy* qt_sizepolicy_new ()
{
	return new QSizePolicy();
}

QSizePolicy* qt_sizepolicy_new_with_policy (QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical)
{
	return new QSizePolicy(horizontal, vertical);
}

QSizePolicy* qt_sizepolicy_new_with_controltype (QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical, QSizePolicy::ControlType type)
{
	return new QSizePolicy(horizontal, vertical, type);
}

QSizePolicy::Policy qt_sizepolicy_horizontal_get(QSizePolicy* policy)
{
	return policy->horizontalPolicy();
}

void qt_sizepolicy_horizontal_set(QSizePolicy* policy, QSizePolicy::Policy horizontal)
{
	policy->setHorizontalPolicy(horizontal);
}

QSizePolicy::Policy qt_sizepolicy_vertical_get(QSizePolicy* policy)
{
	return policy->verticalPolicy();
}

void qt_sizepolicy_vertical_set(QSizePolicy* policy, QSizePolicy::Policy vertical)
{
	policy->setVerticalPolicy(vertical);
}

QSizePolicy::ControlType qt_sizepolicy_controltype_get(QSizePolicy* policy)
{
	return policy->controlType();
}

void qt_sizepolicy_controltype_set(QSizePolicy* policy, QSizePolicy::ControlType controlType)
{
	policy->setControlType(controlType);
}

Qt::Orientations qt_sizepolicy_expanding_directions(QSizePolicy* policy)
{
	return policy->expandingDirections();
}

bool qt_sizepolicy_heightforwidth_get(QSizePolicy* policy)
{
	return policy->hasHeightForWidth();
}

void qt_sizepolicy_heightforwidth_set(QSizePolicy* policy, bool heightForWidth)
{
	policy->setHeightForWidth(heightForWidth);
}

bool qt_sizepolicy_widthforheight_get(QSizePolicy* policy)
{
	return policy->hasHeightForWidth();
}

void qt_sizepolicy_widthforheight_set(QSizePolicy* policy, bool widthForHeight)
{
	policy->setHeightForWidth(widthForHeight);
}

int qt_sizepolicy_horizontalstretch_get(QSizePolicy* policy)
{
	return policy->horizontalStretch();
}

void qt_sizepolicy_horizontalstretch_set(QSizePolicy* policy, int horizontalStretch)
{
	policy->setHorizontalStretch((unsigned char)horizontalStretch);
}

bool qt_sizepolicy_verticalstretch_get(QSizePolicy* policy)
{
	return policy->verticalStretch();
}

void qt_sizepolicy_verticalstretch_set(QSizePolicy* policy, int verticalStretch)
{
	policy->setVerticalStretch((unsigned char)verticalStretch);
}

GlueTableView* qt_tableview_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueTableView(thisObject, parent);
}

QHeaderView* qt_widget_horizontalheader_get(GlueTableView* tableView)
{
	return tableView->horizontalHeader();
}

QHeaderView* qt_widget_verticalheader_get(GlueTableView* tableView)
{
	return tableView->verticalHeader();
}

QEvent::Type qt_event_type_get(QEvent* event)
{
	return event->type();
}

bool qt_event_spontaneous_get(QEvent* event)
{
	return event->spontaneous();
}

bool qt_event_accepted_get(QEvent* event)
{
	return event->isAccepted();
}

void qt_event_accepted_set(QEvent* event, bool accepted)
{
	event->setAccepted(accepted);
}

ulong qt_inputevent_timestamp_get(QInputEvent* event)
{
	return event->timestamp();
}

void qt_inputevent_timestamp_set(QInputEvent* event, ulong timestamp)
{
	event->setTimestamp(timestamp);
}

Qt::KeyboardModifiers qt_inputevent_modifiers_get(QInputEvent* event)
{
	return event->modifiers();
}

void qt_inputevent_modifiers_set(QInputEvent* event, Qt::KeyboardModifiers modifiers)
{
	event->setModifiers(modifiers);
}

QContextMenuEvent::Reason qt_contextmenuevent_reason_get(QContextMenuEvent* event)
{
	return event->reason();
}

QPoint* qt_contextmenuevent_pos_get(QContextMenuEvent* event)
{
	return new QPoint(event->pos());
}

QPoint* qt_contextmenuevent_globalpos_get(QContextMenuEvent* event)
{
	return new QPoint(event->globalPos());
}

QRect* qt_paintevent_rect_get(QPaintEvent* event)
{
	return new QRect(event->rect());
}

Qt::FocusReason qt_focusevent_reason_get(QFocusEvent* event)
{
	return event->reason();
}

bool qt_wheelevent_inverted_get(QWheelEvent* event)
{
	return event->inverted();
}

Qt::ScrollPhase qt_wheelevent_phase_get(QWheelEvent* event)
{
	return event->phase();
}

Qt::MouseEventSource qt_wheelevent_source_get(QWheelEvent* event)
{
	return event->source();
}

Qt::MouseButtons qt_wheelevent_buttons_get(QWheelEvent* event)
{
	return event->buttons();
}

QPointF* qt_wheelevent_globalposf_get(QWheelEvent* event)
{
	return new QPointF(event->globalPosF());
}

QPointF* qt_wheelevent_posf_get(QWheelEvent* event)
{
	return new QPointF(event->posF());
}

Qt::Orientation qt_wheelevent_orientation_get(QWheelEvent* event)
{
	return event->orientation();
}

int qt_wheelevent_delta_get(QWheelEvent* event)
{
	return event->delta();
}

QPoint* qt_wheelevent_angledelta_get(QWheelEvent* event)
{
	return new QPoint(event->angleDelta());
}

QPoint* qt_wheelevent_pixeldelta_get(QWheelEvent* event)
{
	return new QPoint(event->pixelDelta());
}

Qt::MouseEventSource qt_mouseevent_source_get(QMouseEvent* event)
{
	return event->source();
}

Qt::MouseEventFlags qt_mouseevent_flags_get(QMouseEvent* event)
{
	return event->flags();
}

Qt::MouseButton qt_mouseevent_button_get(QMouseEvent* event)
{
	return event->button();
}

Qt::MouseButtons qt_mouseevent_buttons_get(QMouseEvent* event)
{
	return event->buttons();
}

QPointF* qt_mouseevent_localpos_get(QMouseEvent* event)
{
	return new QPointF(event->localPos());
}

QPointF* qt_mouseevent_windowpos_get(QMouseEvent* event)
{
	return new QPointF(event->windowPos());
}

QPointF* qt_mouseevent_screenpos_get(QMouseEvent* event)
{
	return new QPointF(event->screenPos());
}

QKeyEvent* qt_keyevent_new(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, MonoString* text, bool autorep, ushort count)
{
	QKeyEvent* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new QKeyEvent(type, key, modifiers, p, autorep, count);
	g_free(p);
	return retVal;
}

QKeyEvent* qt_keyevent_native_new(QEvent::Type type, int key, Qt::KeyboardModifiers modifiers, quint32 nativeScanCode, quint32 nativeVirtualKey, quint32 nativeModifiers, MonoString* text, bool autorep, ushort count)
{
	QKeyEvent* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new QKeyEvent(type, key, modifiers, nativeScanCode, nativeVirtualKey, nativeModifiers, p, autorep, count);
	g_free(p);
	return retVal;
}

uint32_t qt_keyevent_nativescancode_get(QKeyEvent* event)
{
	return event->nativeScanCode();
}

uint32_t qt_keyevent_nativevirtualkey_get(QKeyEvent* event)
{
	return event->nativeVirtualKey();
}

uint32_t qt_keyevent_nativemodifiers_get(QKeyEvent* event)
{
	return event->nativeModifiers();
}

Qt::KeyboardModifiers qt_keyevent_modifiers_get(QKeyEvent* event)
{
	return event->modifiers();
}

MonoString* qt_keyevent_text_get(QKeyEvent* event)
{
	return mono_string_new(mono_domain_get (), event->text().toStdString().c_str());
}

bool qt_keyevent_autorepeat_get(QKeyEvent* event)
{
	return event->isAutoRepeat();
}

ushort qt_keyevent_count_get(QKeyEvent* event)
{
	return event->count();
}

int qt_keyevent_key_get(QKeyEvent* event)
{
	return event->key();
}

QPoint* qt_moveevent_pos_get(QMoveEvent* event)
{
	return new QPoint(event->pos());
}

QPoint* qt_moveevent_oldpos_get(QMoveEvent* event)
{
	return new QPoint(event->oldPos());
}

QSize* qt_resizeevent_size_get(QResizeEvent* event)
{
	return new QSize(event->size());
}

QSize* qt_resizeevent_oldsize_get(QResizeEvent* event)
{
	return new QSize(event->oldSize());
}

QSize* qt_size_new(int width, int height)
{
	return new QSize(width, height);
}

int qt_size_width_get(QSize* size)
{
	return size->width();
}

void qt_size_width_set(QSize* size, int width)
{
	return size->setWidth(width);
}

int qt_size_height_get(QSize* size)
{
	return size->height();
}

void qt_size_height_set(QSize* size, int height)
{
	return size->setHeight(height);
}

int qt_rectangle_x_get(QRect* rect)
{
	return rect->x();
}

void qt_rectangle_x_set(QRect* rect, int x)
{
	return rect->setX(x);
}

int qt_rectangle_y_get(QRect* rect)
{
	return rect->y();
}

void qt_rectangle_y_set(QRect* rect, int y)
{
	return rect->setY(y);
}

int qt_rectangle_width_get(QRect* rect)
{
	return rect->width();
}

void qt_rectangle_width_set(QRect* rect, int width)
{
	return rect->setWidth(width);
}

int qt_rectangle_height_get(QRect* rect)
{
	return rect->height();
}

void qt_rectangle_height_set(QRect* rect, int height)
{
	return rect->setHeight(height);
}

QPoint* qt_point_new(int x, int y)
{
	return new QPoint(x, y);
}

int qt_point_x_get(QPoint* point)
{
	return point->x();
}

void qt_point_x_set(QPoint* point, int x)
{
	return point->setX(x);
}

int qt_point_y_get(QPoint* point)
{
	return point->y();
}

void qt_point_y_set(QPoint* point, int y)
{
	return point->setY(y);
}

double qt_pointf_x_get(QPointF* point)
{
	return point->x();
}

void qt_pointf_x_set(QPointF* point, double x)
{
	return point->setX(x);
}

double qt_pointf_y_get(QPointF* point)
{
	return point->y();
}

void qt_pointf_y_set(QPointF* point, double y)
{
	return point->setY(y);
}

GlueStandardItemModel* qt_standarditemmodel_new(MonoObject* thisObject, GlueObject* parent)
{
	return new GlueStandardItemModel(thisObject, parent);
}

QModelIndex* qt_standarditemmodel_index_get(QStandardItemModel* standardItemModel, int row, int col)
{
	return new QModelIndex(standardItemModel->index(row, col));
}

void qt_standarditemmodel_item_row_set(GlueStandardItemModel* standardItemModel, int row, QStandardItem* item)
{
	standardItemModel->setItem(row, item);
}

void qt_standarditemmodel_item_row_col_set(GlueStandardItemModel* standardItemModel, int row, int col, QStandardItem* item)
{
	standardItemModel->setItem(row, col, item);
}

void qt_standarditemmodel_item_append(GlueStandardItemModel* standardItemModel, QStandardItem* item)
{
	standardItemModel->appendRow(item);
}

int qt_standarditemmodel_rowcount_get(GlueStandardItemModel* standardItemModel)
{
	return standardItemModel->rowCount();
}

void qt_standarditemmodel_rowcount_set(GlueStandardItemModel* standardItemModel, int rows)
{
	standardItemModel->setRowCount(rows);
}

int qt_standarditemmodel_colcount_get(GlueStandardItemModel* standardItemModel)
{
	return standardItemModel->columnCount();
}

void qt_standarditemmodel_colcount_set(GlueStandardItemModel* standardItemModel, int cols)
{
	standardItemModel->setColumnCount(cols);
}

GlueStandardItemModel* qt_itemview_model_get(QAbstractItemView* abstractItemView)
{
	return (GlueStandardItemModel*)abstractItemView->model();
}

void qt_itemview_model_set(QAbstractItemView* abstractItemView, GlueStandardItemModel* itemModel)
{
	abstractItemView->setModel(itemModel);
}

QAbstractItemView::SelectionBehavior qt_itemview_selectctionbehavior_get(QAbstractItemView* abstractItemView)
{
	return abstractItemView->selectionBehavior();
}

void qt_itemview_selectctionbehavior_set(QAbstractItemView* abstractItemView, QAbstractItemView::SelectionBehavior selectionBehavior)
{
	abstractItemView->setSelectionBehavior(selectionBehavior);
}

QAbstractItemView::SelectionMode qt_itemview_selectctionmode_get(QAbstractItemView* abstractItemView)
{
	return abstractItemView->selectionMode();
}

void qt_itemview_selectctionmode_set(QAbstractItemView* abstractItemView, QAbstractItemView::SelectionMode mode)
{
	abstractItemView->setSelectionMode(mode);
}

int qt_itemview_autoscrollmargin_get(QAbstractItemView* abstractItemView)
{
	return abstractItemView->autoScrollMargin();
}

void qt_itemview_autoscrollmargin_set(QAbstractItemView* abstractItemView, int margin)
{
	return abstractItemView->setAutoScrollMargin(margin);
}

MonoString* qt_abstractbutton_text_get(QAbstractButton* widget)
{
	return mono_string_new(mono_domain_get (), widget->text().toStdString().c_str());
}

void qt_abstractbutton_text_set(QAbstractButton* widget, MonoString* text)
{
	char* p = mono_string_to_utf8(text);
	widget->setText(p);
	g_free(p);
}

QIcon* qt_abstractbutton_icon_get(QAbstractButton* widget)
{
	return new QIcon(widget->icon());
}

void qt_abstractbutton_icon_set(QAbstractButton* widget, QIcon* icon)
{
	widget->setIcon(*icon);
}

QSize* qt_abstractbutton_iconsize_get(QAbstractButton* widget)
{
	return new QSize(widget->iconSize());
}

void qt_abstractbutton_iconsize_set(QAbstractButton* widget, QSize* iconsize)
{
	widget->setIconSize(*iconsize);
}

void qt_tableview_resizerowtocontents(GlueTableView* tableView, int row)
{
	tableView->resizeRowToContents(row);
}

void qt_tableview_resizerowstocontents(GlueTableView* tableView)
{
	tableView->resizeRowsToContents();
}

void qt_tableview_resizecoltocontents(GlueTableView* tableView, int col)
{
	tableView->resizeColumnToContents(col);
}

void qt_tableview_resizecolstocontents(GlueTableView* tableView)
{
	tableView->resizeColumnsToContents();
}

void qt_tableview_selectrow(GlueTableView* tableView, int row)
{
	tableView->selectRow(row);
}

void qt_tableview_selectcol(GlueTableView* tableView, int col)
{
	tableView->selectColumn(col);
}

void qt_tableview_showrow(GlueTableView* tableView, int row)
{
	tableView->showRow(row);
}

void qt_tableview_showcol(GlueTableView* tableView, int col)
{
	tableView->showColumn(col);
}

void qt_tableview_hiderow(GlueTableView* tableView, int row)
{
	tableView->hideRow(row);
}

void qt_tableview_hidecol(GlueTableView* tableView, int col)
{
	tableView->hideColumn(col);
}

void qt_tableview_colwidth_set(GlueTableView* tableView, int col, int width)
{
	tableView->setColumnWidth(col, width);
}

int qt_tableview_colwidth_get(GlueTableView* tableView, int col)
{
	return tableView->columnWidth(col);
}

void qt_tableview_grid_show(GlueTableView* tableView, bool show)
{
	tableView->setShowGrid(show);
}

void qt_tableview_scrollto(GlueTableView* tableView, int row, int col, QAbstractItemView::ScrollHint hint)
{
	tableView->scrollTo(tableView->model()->index(row, col), hint);
}

int qt_tableview_rowheight_get(GlueTableView* tableView, int row)
{
	return tableView->rowHeight(row);
}

void qt_tableview_rowheight_set(GlueTableView* tableView, int row, int height)
{
	tableView->setRowHeight(row, height);
}

QTableWidgetItem* qt_tablewidgetitem_new(MonoString* text)
{
	QTableWidgetItem* retVal = NULL;
	char* p = mono_string_to_utf8(text);
	retVal = new QTableWidgetItem(p);
	g_free(p);
	return retVal;
}

MonoString* qt_tablewidgetitem_text_get(QTableWidgetItem* item)
{
	return mono_string_new(mono_domain_get (), item->text().toStdString().c_str());
}

void qt_tablewidgetitem_text_set(QTableWidgetItem* item, MonoString* text)
{
	char* p = mono_string_to_utf8(text);
	item->setText(p);
	g_free(p);
}

QStandardItem* qt_standarditem_new(MonoString* text)
{
	QStandardItem* retVal = NULL;
	char* p = mono_string_to_utf8(text);
	retVal = new QStandardItem(p);
	g_free(p);
	return retVal;
}

void qt_headerview_visible_set(QHeaderView* headerView, bool visible)
{
	headerView->setVisible(visible);
}

QHeaderView::ResizeMode qt_headerview_section_resizemode_get(QHeaderView* headerView, int logicalIndex)
{
	return headerView->sectionResizeMode(logicalIndex);
}

void qt_headerview_section_resizemode_index_set(QHeaderView* headerView, int logicalIndex, QHeaderView::ResizeMode mode)
{
	headerView->setSectionResizeMode(logicalIndex, mode);
}

int qt_headerview_sectionsize_get(QHeaderView* headerView)
{
	return headerView->defaultSectionSize();
}

void qt_headerview_sectionsize_set(QHeaderView* headerView, int size)
{
	return headerView->setDefaultSectionSize(size);
}

Qt::Alignment qt_headerview_defaultalignment_get(QHeaderView* headerView)
{
	return headerView->defaultAlignment();
}

void qt_headerview_defaultalignment_set(QHeaderView* headerView, Qt::Alignment alignment)
{
	headerView->setDefaultAlignment(alignment);
}

void qt_headerview_section_resizemode_set(QHeaderView* headerView, QHeaderView::ResizeMode mode)
{
	headerView->setSectionResizeMode(mode);
}

GlueTableWidget* qt_tablewidget_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueTableWidget(thisObject, parent);
}

int qt_tablewidget_rowcount_get(GlueTableWidget* tableWidget)
{
	return tableWidget->rowCount();
}

void qt_tablewidget_rowcount_set(GlueTableWidget* tableWidget, int rows)
{
	return tableWidget->setRowCount(rows);
}

int qt_tablewidget_colcount_get(GlueTableWidget* tableWidget)
{
	return tableWidget->columnCount();
}

void qt_tablewidget_colcount_set(GlueTableWidget* tableWidget, int cols)
{
	return tableWidget->setColumnCount(cols);
}

QTableWidgetItem* qt_tablewidget_row_col_get(GlueTableWidget* tableWidget, int row, int col)
{
	return tableWidget->item(row, col);
}

void qt_tablewidget_row_col_set(GlueTableWidget* tableWidget, int row, int col, QTableWidgetItem* item)
{
	tableWidget->setItem(row, col, item);
}

void qt_tablewidget_item_select(GlueTableWidget* tableWidget, QTableWidgetItem* item, bool select)
{
	tableWidget->setItemSelected(item, select);
}

QRect* qt_tablewidget_visual_item_rect(GlueTableWidget* tableWidget, QTableWidgetItem* item)
{
	return new QRect(tableWidget->visualItemRect(item));
}

GlueListWidget* qt_listwidget_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueListWidget(thisObject, parent);
}

void qt_listwidget_item_add(GlueListWidget* listWidget, QListWidgetItem* item)
{
	listWidget->addItem(item);
}

QListWidgetItem* qt_listwidget_item_get(GlueListWidget* listWidget, int row)
{
	return listWidget->item(row);
}

void qt_listwidget_item_select(GlueListWidget* listWidget, QListWidgetItem* item, bool select)
{
	listWidget->setItemSelected(item, select);
}

QListWidgetItem* qt_listwidgetitem_new (QIcon* icon, MonoString* text, QListWidget* view, int type)
{
	QListWidgetItem* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new QListWidgetItem(*icon, p, view, type);
	g_free(p);
	return retVal;
}

MonoString* qt_listwidgetitem_text_get(QListWidgetItem* item)
{
	return mono_string_new(mono_domain_get (), item->text().toStdString().c_str());
}

void qt_listwidgetitem_text_set(QListWidgetItem* item, MonoString* text)
{
	char* p = mono_string_to_utf8(text);
	item->setText(p);
	g_free(p);
}

GlueModelIndex* qt_modelindex_new(MonoObject* thisObject)
{
	return new GlueModelIndex(thisObject);
}

int qt_modelindex_row_get(QModelIndex* index)
{
	return index->row();
}

int qt_modelindex_col_get(QModelIndex* index)
{
	return index->column();
}

uint32_t qt_modelindex_flags_get(QModelIndex* index)
{
	return index->flags();
}

QIcon* qt_icon_new(MonoString* filename)
{
	QIcon* retVal;
	char* p = mono_string_to_utf8(filename);
	retVal = new QIcon(p);
	g_free(p);
	return retVal;
}

void qt_icon_delete(QIcon* icon)
{
	delete icon;
}

QIcon* qt_icon_from_pixmap_new(QPixmap* pixmap)
{
	return new QIcon(*pixmap);
}

QPixmap* qt_pixmap_new(MonoString* filename, MonoString* format, Qt::ImageConversionFlag flags)
{
	QPixmap* retVal;
	char* p = mono_string_to_utf8(filename);
	char* p1 = mono_string_to_utf8(format);
	retVal = new QPixmap(p, p1, flags);
	g_free(p1);
	g_free(p);
	return retVal;
}

void qt_pixmap_delete(QPixmap* pixmap)
{
	delete pixmap;
}

bool qt_pixmap_save(QPixmap* pixmap, MonoString* fileName, MonoString* format, int quality)
{
	bool retVal;
	char* p = mono_string_to_utf8(fileName);
	char* p1 = mono_string_to_utf8(format);
	retVal = pixmap->save(p, p1, quality);
	g_free(p1);
	g_free(p);
	return retVal;
}

QPixmap* qt_pixmap_data_new(const unsigned char* data, uint32_t len, MonoString* format)
{
	QPixmap* retVal = new QPixmap();
	char* p1 = mono_string_to_utf8(format);
	retVal->loadFromData(data, len, p1);
	g_free(p1);
	return retVal;
}

QPixmap* qt_pixmap_scaled(QPixmap* pixmap, QSize* size, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode)
{
	return new QPixmap(pixmap->scaled(*size, aspectMode, mode));
}

QPixmap* qt_pixmap_rotate(QPixmap* pixmap, qreal deg)
{
	QTransform transform;
	QTransform trans = transform.rotate(deg);
	return new QPixmap(pixmap->transformed(trans));
}

int qt_pixmap_width_get(QPixmap* pixmap)
{
	return pixmap->width();
}

int qt_pixmap_height_get(QPixmap* pixmap)
{
	return pixmap->height();
}

QSize* qt_pixmap_size_get(QPixmap* pixmap)
{
	return new QSize(pixmap->size());
}

int qt_pixmap_depth_get(QPixmap* pixmap)
{
	return pixmap->depth();
}

QPainter* qt_painter_new(MonoObject* thisObject, QPixmap* pixmap)
{
	return new QPainter(pixmap);
}

void qt_painter_pixmap_draw(QPainter* painter, int x, int y, QPixmap* pixmap)
{
	painter->drawPixmap(x, y, *pixmap);
}

QPixmap* qt_screen_window_grab(QScreen* screen, WId window, int x, int y, int w, int h)
{
	return new QPixmap(screen->grabWindow(window, x, y, w, h));
}

QRect* qt_style_alignrect_get(Qt::LayoutDirection direction, Qt::Alignment alignment, QSize* size, QRect* rectangle)
{
	return new QRect(QStyle::alignedRect(direction, alignment, *size, *rectangle));
}

QDesktopWidget* qt_application_desktop_get()
{
	return QApplication::desktop();
}

QRect* qt_desktopwidget_availablegeometry_get(QDesktopWidget* desktopwidget, int screen)
{
	return new QRect(desktopwidget->screenGeometry(screen));
}

QMenu* qt_menu_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueMenu(thisObject, parent);
}

QMenu* qt_menu_title_new(MonoObject* thisObject, MonoString* title, QWidget* parent)
{
	GlueMenu* retVal;
	char* p = mono_string_to_utf8(title);
	retVal = new GlueMenu(thisObject, p, parent);
	g_free(p);
	return retVal;
}

void qt_menu_delete(GlueMenu* menu)
{
	delete menu;
}

QAction* qt_menu_exec(GlueMenu* menu, QPoint* pos, GlueAction* action)
{
	return menu->exec(*pos, action);
}

QAction* qt_menu_seperator_add(GlueMenu* menu)
{
	return menu->addSeparator();
}

QAction* qt_menu_action_text_add(GlueMenu* menu, MonoString* text)
{
	QAction* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = menu->addAction(p);
	g_free(p);
	return retVal;
}

QAction* qt_menu_action_icon_text_add(GlueMenu* menu, QIcon* icon, MonoString* text)
{
	QAction* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = menu->addAction(*icon, p);
	g_free(p);
	return retVal;
}

QAction* qt_menu_activeaction_get(GlueMenu* menu)
{
	return menu->activeAction();
}

void qt_menu_activeaction_set(GlueMenu* menu, GlueAction* action)
{
	return menu->setActiveAction(action);
}

GlueMenuBar* qt_menubar_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueMenuBar(thisObject, parent);
}

void qt_menubar_delete(GlueMenuBar* menuBar)
{
	delete menuBar;
}

QAction* qt_menubar_action_text_add(GlueMenuBar* menubar, MonoString* text)
{
	QAction* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = menubar->addAction(p);
	g_free(p);
	return retVal;
}

QAction* qt_menubar_activeaction_get(GlueMenuBar* menu)
{
	return menu->activeAction();
}

void qt_menubar_activeaction_set(GlueMenuBar* menu, GlueAction* action)
{
	return menu->setActiveAction(action);
}

GlueToolBar* qt_toolbar_new(MonoObject* thisObject, QWidget* parent)
{
	return new GlueToolBar(thisObject, parent);
}

GlueAction* qt_action_new(MonoObject* thisObject, QObject* parent)
{
	return new GlueAction(thisObject, parent);
}

void qt_action_delete(GlueAction* action)
{
	delete action;
}

GlueAction* qt_action_text_new(MonoObject* thisObject, MonoString* text, QObject* parent)
{
	GlueAction* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new GlueAction(thisObject, p, parent);
	g_free(p);
	return retVal;
}

MonoString* qt_action_text_get(GlueAction* action)
{
	return mono_string_new(mono_domain_get (), action->text().toStdString().c_str());
}

void qt_action_text_set(GlueAction* action, MonoString* text)
{
	char* p = mono_string_to_utf8(text);
	action->setText(p);
	g_free(p);
}

extern "C" void qt_application_monointernal_init()
{
	mono_add_internal_call ("Qt.Application::qt_application_new", reinterpret_cast<void*>(qt_application_new));
	mono_add_internal_call ("Qt.Application::qt_application_exec", reinterpret_cast<void*>(qt_application_exec));
	mono_add_internal_call ("Qt.Application::qt_application_postevent", reinterpret_cast<void*>(qt_application_postevent));
	mono_add_internal_call ("Qt.Application::qt_application_events_process", reinterpret_cast<void*>(qt_application_events_process));
	mono_add_internal_call ("Qt.Application::qt_application_desktop_get", reinterpret_cast<void*>(qt_application_desktop_get));
	mono_add_internal_call ("Qt.Application::qt_application_activewindow_get", reinterpret_cast<void*>(qt_application_activewindow_get));
	mono_add_internal_call ("Qt.Application::qt_application_style_get", reinterpret_cast<void*>(qt_application_style_get));
	mono_add_internal_call ("Qt.Application::qt_application_style_set", reinterpret_cast<void*>(qt_application_style_set));

	mono_add_internal_call ("Qt.GuiApplication::qt_guiapplication_primaryscreen_get", reinterpret_cast<void*>(qt_guiapplication_primaryscreen_get));

	mono_add_internal_call ("Qt.CoreApplication::qt_application_attribute_set", reinterpret_cast<void*>(qt_application_attribute_set));
	mono_add_internal_call ("Qt.CoreApplication::qt_coreapplication_quit", reinterpret_cast<void*>(qt_coreapplication_quit));

	mono_add_internal_call ("Qt.StyleFactory::qt_stylefactory_create", reinterpret_cast<void*>(qt_stylefactory_create));
	mono_add_internal_call ("Qt.StyleFactory::qt_stylefactory_keys", reinterpret_cast<void*>(qt_stylefactory_keys));

	mono_add_internal_call ("Qt.EglFSFunctions::qt_eglfs_loadkeymap", reinterpret_cast<void*>(qt_eglfs_loadkeymap));

	mono_add_internal_call ("Qt.UiLoader::qt_uiloader_new", reinterpret_cast<void*>(qt_uiloader_new));
	mono_add_internal_call ("Qt.UiLoader::qt_uiloader_load", reinterpret_cast<void*>(qt_uiloader_load));

	mono_add_internal_call ("Qt.MainWindow::qt_mainwindow_new", reinterpret_cast<void*>(qt_mainwindow_new));
	mono_add_internal_call ("Qt.MainWindow::qt_mainwindow_menubar_get", reinterpret_cast<void*>(qt_mainwindow_menubar_get));
	mono_add_internal_call ("Qt.MainWindow::qt_mainwindow_menubar_set", reinterpret_cast<void*>(qt_mainwindow_menubar_set));

	mono_add_internal_call ("Qt.Dialog::qt_dialog_new", reinterpret_cast<void*>(qt_dialog_new));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_delete", reinterpret_cast<void*>(qt_dialog_delete));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_modal_get", reinterpret_cast<void*>(qt_dialog_modal_get));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_modal_set", reinterpret_cast<void*>(qt_dialog_modal_set));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_exec", reinterpret_cast<void*>(qt_dialog_exec));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_accept", reinterpret_cast<void*>(qt_dialog_accept));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_reject", reinterpret_cast<void*>(qt_dialog_reject));

	mono_add_internal_call ("Qt.TableView::qt_tableview_new", reinterpret_cast<void*>(qt_tableview_new));
	mono_add_internal_call ("Qt.TableView::qt_tableview_horizontalheader_get", reinterpret_cast<void*>(qt_widget_horizontalheader_get));
	mono_add_internal_call ("Qt.TableView::qt_tableview_verticalheader_get", reinterpret_cast<void*>(qt_widget_verticalheader_get));
	mono_add_internal_call ("Qt.TableView::qt_tableview_resizerowstocontents", reinterpret_cast<void*>(qt_tableview_resizerowstocontents));
	mono_add_internal_call ("Qt.TableView::qt_tableview_resizerowtocontents", reinterpret_cast<void*>(qt_tableview_resizerowtocontents));
	mono_add_internal_call ("Qt.TableView::qt_tableview_resizecolstocontents", reinterpret_cast<void*>(qt_tableview_resizecolstocontents));
	mono_add_internal_call ("Qt.TableView::qt_tableview_resizecoltocontents", reinterpret_cast<void*>(qt_tableview_resizecoltocontents));
	mono_add_internal_call ("Qt.TableView::qt_tableview_selectrow", reinterpret_cast<void*>(qt_tableview_selectrow));
	mono_add_internal_call ("Qt.TableView::qt_tableview_selectcol", reinterpret_cast<void*>(qt_tableview_selectcol));
	mono_add_internal_call ("Qt.TableView::qt_tableview_showrow", reinterpret_cast<void*>(qt_tableview_showrow));
	mono_add_internal_call ("Qt.TableView::qt_tableview_hiderow", reinterpret_cast<void*>(qt_tableview_hiderow));
	mono_add_internal_call ("Qt.TableView::qt_tableview_showcol", reinterpret_cast<void*>(qt_tableview_showcol));
	mono_add_internal_call ("Qt.TableView::qt_tableview_hidecol", reinterpret_cast<void*>(qt_tableview_hidecol));
	mono_add_internal_call ("Qt.TableView::qt_tableview_colwidth_get", reinterpret_cast<void*>(qt_tableview_colwidth_get));
	mono_add_internal_call ("Qt.TableView::qt_tableview_colwidth_set", reinterpret_cast<void*>(qt_tableview_colwidth_set));
	mono_add_internal_call ("Qt.TableView::qt_tableview_grid_show", reinterpret_cast<void*>(qt_tableview_grid_show));
	mono_add_internal_call ("Qt.TableView::qt_tableview_scrollto", reinterpret_cast<void*>(qt_tableview_scrollto));
	mono_add_internal_call ("Qt.TableView::qt_tableview_rowheight_get", reinterpret_cast<void*>(qt_tableview_rowheight_get));
	mono_add_internal_call ("Qt.TableView::qt_tableview_rowheight_set", reinterpret_cast<void*>(qt_tableview_rowheight_set));

	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_new", reinterpret_cast<void*>(qt_tablewidget_new));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_rowcount_get", reinterpret_cast<void*>(qt_tablewidget_rowcount_get));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_rowcount_set", reinterpret_cast<void*>(qt_tablewidget_rowcount_set));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_colcount_get", reinterpret_cast<void*>(qt_tablewidget_colcount_get));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_colcount_set", reinterpret_cast<void*>(qt_tablewidget_colcount_set));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_row_col_get", reinterpret_cast<void*>(qt_tablewidget_row_col_get));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_row_col_set", reinterpret_cast<void*>(qt_tablewidget_row_col_set));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_item_select", reinterpret_cast<void*>(qt_tablewidget_item_select));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_visual_item_rect", reinterpret_cast<void*>(qt_tablewidget_visual_item_rect));

	mono_add_internal_call ("Qt.ListWidget::qt_listwidget_new", reinterpret_cast<void*>(qt_listwidget_new));
	mono_add_internal_call ("Qt.ListWidget::qt_listwidget_item_add", reinterpret_cast<void*>(qt_listwidget_item_add));
	mono_add_internal_call ("Qt.ListWidget::qt_listwidget_item_get", reinterpret_cast<void*>(qt_listwidget_item_get));
	mono_add_internal_call ("Qt.ListWidget::qt_listwidget_item_select", reinterpret_cast<void*>(qt_listwidget_item_select));

	mono_add_internal_call ("Qt.ListWidgetItem::qt_listwidgetitem_new", reinterpret_cast<void*>(qt_listwidgetitem_new));
	mono_add_internal_call ("Qt.ListWidgetItem::qt_listwidgetitem_text_get", reinterpret_cast<void*>(qt_listwidgetitem_text_get));
	mono_add_internal_call ("Qt.ListWidgetItem::qt_listwidgetitem_text_set", reinterpret_cast<void*>(qt_listwidgetitem_text_set));

	mono_add_internal_call ("Qt.TableWidgetItem::qt_tablewidgetitem_new", reinterpret_cast<void*>(qt_tablewidgetitem_new));
	mono_add_internal_call ("Qt.TableWidgetItem::qt_tablewidgetitem_text_get", reinterpret_cast<void*>(qt_tablewidgetitem_text_get));
	mono_add_internal_call ("Qt.TableWidgetItem::qt_tablewidgetitem_text_set", reinterpret_cast<void*>(qt_tablewidgetitem_text_set));

	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_model_get", reinterpret_cast<void*>(qt_itemview_model_get));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_model_set", reinterpret_cast<void*>(qt_itemview_model_set));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_selectctionbehavior_get", reinterpret_cast<void*>(qt_itemview_selectctionbehavior_get));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_selectctionbehavior_set", reinterpret_cast<void*>(qt_itemview_selectctionbehavior_set));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_selectctionmode_get", reinterpret_cast<void*>(qt_itemview_selectctionmode_get));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_selectctionmode_set", reinterpret_cast<void*>(qt_itemview_selectctionmode_set));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_autoscrollmargin_get", reinterpret_cast<void*>(qt_itemview_autoscrollmargin_get));
	mono_add_internal_call ("Qt.AbstractItemView::qt_itemview_autoscrollmargin_set", reinterpret_cast<void*>(qt_itemview_autoscrollmargin_set));

	mono_add_internal_call ("Qt.AbstractButton::qt_abstractbutton_text_get", reinterpret_cast<void*>(qt_abstractbutton_text_get));
	mono_add_internal_call ("Qt.AbstractButton::qt_abstractbutton_text_set", reinterpret_cast<void*>(qt_abstractbutton_text_set));
	mono_add_internal_call ("Qt.AbstractButton::qt_abstractbutton_icon_get", reinterpret_cast<void*>(qt_abstractbutton_icon_get));
	mono_add_internal_call ("Qt.AbstractButton::qt_abstractbutton_icon_set", reinterpret_cast<void*>(qt_abstractbutton_icon_set));
	mono_add_internal_call ("Qt.AbstractButton::qt_abstractbutton_iconsize_get", reinterpret_cast<void*>(qt_abstractbutton_iconsize_get));
	mono_add_internal_call ("Qt.AbstractButton::qt_abstractbutton_iconsize_set", reinterpret_cast<void*>(qt_abstractbutton_iconsize_set));

	mono_add_internal_call ("Qt.StandardItem::qt_standarditem_new", reinterpret_cast<void*>(qt_standarditem_new));

	mono_add_internal_call ("Qt.Label::qt_label_new", reinterpret_cast<void*>(qt_label_new));
	mono_add_internal_call ("Qt.Label::qt_label_new_with_text", reinterpret_cast<void*>(qt_label_new_with_text));
	mono_add_internal_call ("Qt.Label::qt_label_text_get", reinterpret_cast<void*>(qt_label_text_get));
	mono_add_internal_call ("Qt.Label::qt_label_text_set", reinterpret_cast<void*>(qt_label_text_set));
	mono_add_internal_call ("Qt.Label::qt_label_clear", reinterpret_cast<void*>(qt_label_clear));
	mono_add_internal_call ("Qt.Label::qt_label_pixmap_get", reinterpret_cast<void*>(qt_label_pixmap_get));
	mono_add_internal_call ("Qt.Label::qt_label_pixmap_set", reinterpret_cast<void*>(qt_label_pixmap_set));
	mono_add_internal_call ("Qt.Label::qt_label_alignment_get", reinterpret_cast<void*>(qt_label_alignment_get));
	mono_add_internal_call ("Qt.Label::qt_label_alignment_set", reinterpret_cast<void*>(qt_label_alignment_set));
	mono_add_internal_call ("Qt.Label::qt_label_indent_get", reinterpret_cast<void*>(qt_label_indent_get));
	mono_add_internal_call ("Qt.Label::qt_label_indent_set", reinterpret_cast<void*>(qt_label_indent_set));
	mono_add_internal_call ("Qt.Label::qt_label_textinteractionflags_get", reinterpret_cast<void*>(qt_label_textinteractionflags_get));
	mono_add_internal_call ("Qt.Label::qt_label_textinteractionflags_set", reinterpret_cast<void*>(qt_label_textinteractionflags_set));

	mono_add_internal_call ("Qt.Label::qt_label_textformat_get", reinterpret_cast<void*>(qt_label_textformat_get));
	mono_add_internal_call ("Qt.Label::qt_label_textformat_set", reinterpret_cast<void*>(qt_label_textformat_set));
	mono_add_internal_call ("Qt.Label::qt_label_scaledcontents_get", reinterpret_cast<void*>(qt_label_scaledcontents_get));
	mono_add_internal_call ("Qt.Label::qt_label_scaledcontents_set", reinterpret_cast<void*>(qt_label_scaledcontents_set));
	mono_add_internal_call ("Qt.Label::qt_label_wordwrap_get", reinterpret_cast<void*>(qt_label_wordwrap_get));
	mono_add_internal_call ("Qt.Label::qt_label_wordwrap_set", reinterpret_cast<void*>(qt_label_wordwrap_set));
	mono_add_internal_call ("Qt.Label::qt_label_margin_get", reinterpret_cast<void*>(qt_label_margin_get));
	mono_add_internal_call ("Qt.Label::qt_label_margin_set", reinterpret_cast<void*>(qt_label_margin_set));

	mono_add_internal_call ("Qt.CheckBox::qt_checkbox_new", reinterpret_cast<void*>(qt_checkbox_new));
	mono_add_internal_call ("Qt.CheckBox::qt_checkbox_new_with_text", reinterpret_cast<void*>(qt_checkbox_new_with_text));
	mono_add_internal_call ("Qt.CheckBox::qt_checkbox_sizehint_get", reinterpret_cast<void*>(qt_checkbox_sizehint_get));
	mono_add_internal_call ("Qt.CheckBox::qt_checkbox_tristate_get", reinterpret_cast<void*>(qt_checkbox_tristate_get));
	mono_add_internal_call ("Qt.CheckBox::qt_checkbox_tristate_set", reinterpret_cast<void*>(qt_checkbox_tristate_set));

	mono_add_internal_call ("Qt.PushButton::qt_pushbutton_new", reinterpret_cast<void*>(qt_pushbutton_new));
	mono_add_internal_call ("Qt.PushButton::qt_pushbutton_new_with_text", reinterpret_cast<void*>(qt_pushbutton_new_with_text));
	mono_add_internal_call ("Qt.PushButton::qt_pushbutton_sizehint_get", reinterpret_cast<void*>(qt_pushbutton_sizehint_get));

	mono_add_internal_call ("Qt.CommandLinkButton::qt_commandlinkbutton_new", reinterpret_cast<void*>(qt_commandlinkbutton_new));
	mono_add_internal_call ("Qt.CommandLinkButton::qt_commandlinkbutton_new_with_text", reinterpret_cast<void*>(qt_commandlinkbutton_new_with_text));
	mono_add_internal_call ("Qt.CommandLinkButton::qt_commandlinkbutton_sizehint_get", reinterpret_cast<void*>(qt_commandlinkbutton_sizehint_get));

	mono_add_internal_call ("Qt.ToolButton::qt_toolbutton_new", reinterpret_cast<void*>(qt_toolbutton_new));
	mono_add_internal_call ("Qt.ToolButton::qt_toolbutton_sizehint_get", reinterpret_cast<void*>(qt_toolbutton_sizehint_get));

	mono_add_internal_call ("Qt.Frame::qt_frame_new", reinterpret_cast<void*>(qt_frame_new));
	mono_add_internal_call ("Qt.Frame::qt_frame_shape_get", reinterpret_cast<void*>(qt_frame_shape_get));
	mono_add_internal_call ("Qt.Frame::qt_frame_shape_set", reinterpret_cast<void*>(qt_frame_shape_set));
	mono_add_internal_call ("Qt.Frame::qt_frame_shadow_get", reinterpret_cast<void*>(qt_frame_shadow_get));
	mono_add_internal_call ("Qt.Frame::qt_frame_shadow_set", reinterpret_cast<void*>(qt_frame_shadow_set));
	mono_add_internal_call ("Qt.Frame::qt_frame_linewidth_get", reinterpret_cast<void*>(qt_frame_linewidth_get));
	mono_add_internal_call ("Qt.Frame::qt_frame_linewidth_set", reinterpret_cast<void*>(qt_frame_linewidth_set));
	mono_add_internal_call ("Qt.Frame::qt_frame_width_get", reinterpret_cast<void*>(qt_frame_width_get));

	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_new", reinterpret_cast<void*>(qt_progressbar_new));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_value_get", reinterpret_cast<void*>(qt_progressbar_value_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_value_set", reinterpret_cast<void*>(qt_progressbar_value_set));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_format_get", reinterpret_cast<void*>(qt_progressbar_format_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_format_set", reinterpret_cast<void*>(qt_progressbar_format_set));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_minimum_get", reinterpret_cast<void*>(qt_progressbar_minimum_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_minimum_set", reinterpret_cast<void*>(qt_progressbar_minimum_set));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_maximum_get", reinterpret_cast<void*>(qt_progressbar_maximum_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_maximum_set", reinterpret_cast<void*>(qt_progressbar_maximum_set));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_range_set", reinterpret_cast<void*>(qt_progressbar_range_set));

	mono_add_internal_call ("Qt.Size::qt_size_new", reinterpret_cast<void*>(qt_size_new));
	mono_add_internal_call ("Qt.Size::qt_size_width_get", reinterpret_cast<void*>(qt_size_width_get));
	mono_add_internal_call ("Qt.Size::qt_size_width_set", reinterpret_cast<void*>(qt_size_width_set));
	mono_add_internal_call ("Qt.Size::qt_size_height_get", reinterpret_cast<void*>(qt_size_height_get));
	mono_add_internal_call ("Qt.Size::qt_size_height_set", reinterpret_cast<void*>(qt_size_height_set));

	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_x_get", reinterpret_cast<void*>(qt_rectangle_x_get));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_x_set", reinterpret_cast<void*>(qt_rectangle_x_set));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_y_get", reinterpret_cast<void*>(qt_rectangle_y_get));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_y_set", reinterpret_cast<void*>(qt_rectangle_y_set));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_width_get", reinterpret_cast<void*>(qt_rectangle_width_get));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_width_set", reinterpret_cast<void*>(qt_rectangle_width_set));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_height_get", reinterpret_cast<void*>(qt_rectangle_height_get));
	mono_add_internal_call ("Qt.Rectangle::qt_rectangle_height_set", reinterpret_cast<void*>(qt_rectangle_height_set));

	mono_add_internal_call ("Qt.Point::qt_point_new", reinterpret_cast<void*>(qt_point_new));
	mono_add_internal_call ("Qt.Point::qt_point_x_get", reinterpret_cast<void*>(qt_point_x_get));
	mono_add_internal_call ("Qt.Point::qt_point_x_set", reinterpret_cast<void*>(qt_point_x_set));
	mono_add_internal_call ("Qt.Point::qt_point_y_get", reinterpret_cast<void*>(qt_point_y_get));
	mono_add_internal_call ("Qt.Point::qt_point_y_set", reinterpret_cast<void*>(qt_point_y_set));

	mono_add_internal_call ("Qt.PointF::qt_pointf_x_get", reinterpret_cast<void*>(qt_pointf_x_get));
	mono_add_internal_call ("Qt.PointF::qt_pointf_x_set", reinterpret_cast<void*>(qt_pointf_x_set));
	mono_add_internal_call ("Qt.PointF::qt_pointf_y_get", reinterpret_cast<void*>(qt_pointf_y_get));
	mono_add_internal_call ("Qt.PointF::qt_pointf_y_set", reinterpret_cast<void*>(qt_pointf_y_set));

	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_new", reinterpret_cast<void*>(qt_sizepolicy_new));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_new_with_policy", reinterpret_cast<void*>(qt_sizepolicy_new_with_policy));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_new_with_controltype", reinterpret_cast<void*>(qt_sizepolicy_new_with_controltype));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_horizontal_get", reinterpret_cast<void*>(qt_sizepolicy_horizontal_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_horizontal_set", reinterpret_cast<void*>(qt_sizepolicy_horizontal_set));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_vertical_get", reinterpret_cast<void*>(qt_sizepolicy_vertical_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_vertical_set", reinterpret_cast<void*>(qt_sizepolicy_vertical_set));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_controltype_get", reinterpret_cast<void*>(qt_sizepolicy_controltype_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_controltype_set", reinterpret_cast<void*>(qt_sizepolicy_controltype_set));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_expanding_directions", reinterpret_cast<void*>(qt_sizepolicy_expanding_directions));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_heightforwidth_get", reinterpret_cast<void*>(qt_sizepolicy_heightforwidth_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_heightforwidth_set", reinterpret_cast<void*>(qt_sizepolicy_heightforwidth_set));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_widthforheight_get", reinterpret_cast<void*>(qt_sizepolicy_widthforheight_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_widthforheight_set", reinterpret_cast<void*>(qt_sizepolicy_widthforheight_set));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_horizontalstretch_get", reinterpret_cast<void*>(qt_sizepolicy_horizontalstretch_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_horizontalstretch_set", reinterpret_cast<void*>(qt_sizepolicy_horizontalstretch_set));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_verticalstretch_get", reinterpret_cast<void*>(qt_sizepolicy_verticalstretch_get));
	mono_add_internal_call ("Qt.SizePolicy::qt_sizepolicy_verticalstretch_set", reinterpret_cast<void*>(qt_sizepolicy_verticalstretch_set));

	mono_add_internal_call ("Qt.BoxLayout::qt_boxlayout_new", reinterpret_cast<void*>(qt_boxlayout_new));
	mono_add_internal_call ("Qt.BoxLayout::qt_boxlayout_widget_add", reinterpret_cast<void*>(qt_boxlayout_widget_add));
	mono_add_internal_call ("Qt.BoxLayout::qt_boxlayout_layout_add", reinterpret_cast<void*>(qt_boxlayout_layout_add));
	mono_add_internal_call ("Qt.BoxLayout::qt_boxlayout_direction_get", reinterpret_cast<void*>(qt_boxlayout_direction_get));
	mono_add_internal_call ("Qt.BoxLayout::qt_boxlayout_direction_set", reinterpret_cast<void*>(qt_boxlayout_direction_set));

	mono_add_internal_call ("Qt.GridLayout::qt_gridlayout_new", reinterpret_cast<void*>(qt_gridlayout_new));
	mono_add_internal_call ("Qt.GridLayout::qt_gridlayout_widget_add", reinterpret_cast<void*>(qt_gridlayout_widget_add));
	mono_add_internal_call ("Qt.GridLayout::qt_gridlayout_widget_alignment_add", reinterpret_cast<void*>(qt_gridlayout_widget_alignment_add));
	mono_add_internal_call ("Qt.GridLayout::qt_gridlayout_widget_span_add", reinterpret_cast<void*>(qt_gridlayout_widget_span_add));

	mono_add_internal_call ("Qt.VBoxLayout::qt_vboxlayout_new", reinterpret_cast<void*>(qt_vboxlayout_new));
	mono_add_internal_call ("Qt.HBoxLayout::qt_hboxlayout_new", reinterpret_cast<void*>(qt_hboxlayout_new));

	mono_add_internal_call ("Qt.Event::qt_event_type_get", reinterpret_cast<void*>(qt_event_type_get));
	mono_add_internal_call ("Qt.Event::qt_event_spontaneous_get", reinterpret_cast<void*>(qt_event_spontaneous_get));
	mono_add_internal_call ("Qt.Event::qt_event_accepted_get", reinterpret_cast<void*>(qt_event_accepted_get));
	mono_add_internal_call ("Qt.Event::qt_event_accepted_set", reinterpret_cast<void*>(qt_event_accepted_set));

	mono_add_internal_call ("Qt.InputEvent::qt_inputevent_timestamp_get", reinterpret_cast<void*>(qt_inputevent_timestamp_get));
	mono_add_internal_call ("Qt.InputEvent::qt_inputevent_timestamp_set", reinterpret_cast<void*>(qt_inputevent_timestamp_set));
	mono_add_internal_call ("Qt.InputEvent::qt_inputevent_modifiers_get", reinterpret_cast<void*>(qt_inputevent_modifiers_get));
	mono_add_internal_call ("Qt.InputEvent::qt_inputevent_modifiers_set", reinterpret_cast<void*>(qt_inputevent_modifiers_set));

	mono_add_internal_call ("Qt.ContextMenuEvent::qt_contextmenuevent_reason_get", reinterpret_cast<void*>(qt_contextmenuevent_reason_get));
	mono_add_internal_call ("Qt.ContextMenuEvent::qt_contextmenuevent_pos_get", reinterpret_cast<void*>(qt_contextmenuevent_pos_get));
	mono_add_internal_call ("Qt.ContextMenuEvent::qt_contextmenuevent_globalpos_get", reinterpret_cast<void*>(qt_contextmenuevent_globalpos_get));

	mono_add_internal_call ("Qt.MoveEvent::qt_moveevent_pos_get", reinterpret_cast<void*>(qt_moveevent_pos_get));
	mono_add_internal_call ("Qt.MoveEvent::qt_moveevent_oldpos_get", reinterpret_cast<void*>(qt_moveevent_oldpos_get));

	mono_add_internal_call ("Qt.ResizeEvent::qt_resizeevent_size_get", reinterpret_cast<void*>(qt_resizeevent_size_get));
	mono_add_internal_call ("Qt.ResizeEvent::qt_resizeevent_oldsize_get", reinterpret_cast<void*>(qt_resizeevent_oldsize_get));

	mono_add_internal_call ("Qt.PaintEvent::qt_paintevent_rect_get", reinterpret_cast<void*>(qt_paintevent_rect_get));

	mono_add_internal_call ("Qt.FocusEvent::qt_focusevent_reason_get", reinterpret_cast<void*>(qt_focusevent_reason_get));

	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_inverted_get", reinterpret_cast<void*>(qt_wheelevent_inverted_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_phase_get", reinterpret_cast<void*>(qt_wheelevent_phase_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_delta_get", reinterpret_cast<void*>(qt_wheelevent_delta_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_orientation_get", reinterpret_cast<void*>(qt_wheelevent_orientation_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_source_get", reinterpret_cast<void*>(qt_wheelevent_source_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_pixeldelta_get", reinterpret_cast<void*>(qt_wheelevent_pixeldelta_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_angledelta_get", reinterpret_cast<void*>(qt_wheelevent_angledelta_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_posf_get", reinterpret_cast<void*>(qt_wheelevent_posf_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_globalposf_get", reinterpret_cast<void*>(qt_wheelevent_globalposf_get));
	mono_add_internal_call ("Qt.WheelEvent::qt_wheelevent_buttons_get", reinterpret_cast<void*>(qt_wheelevent_buttons_get));

	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_source_get", reinterpret_cast<void*>(qt_mouseevent_source_get));
	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_flags_get", reinterpret_cast<void*>(qt_mouseevent_flags_get));
	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_button_get", reinterpret_cast<void*>(qt_mouseevent_button_get));
	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_buttons_get", reinterpret_cast<void*>(qt_mouseevent_buttons_get));
	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_localpos_get", reinterpret_cast<void*>(qt_mouseevent_localpos_get));
	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_windowpos_get", reinterpret_cast<void*>(qt_mouseevent_windowpos_get));
	mono_add_internal_call ("Qt.MouseEvent::qt_mouseevent_screenpos_get", reinterpret_cast<void*>(qt_mouseevent_screenpos_get));

	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_new", reinterpret_cast<void*>(qt_keyevent_new));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_native_new", reinterpret_cast<void*>(qt_keyevent_native_new));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_nativescancode_get", reinterpret_cast<void*>(qt_keyevent_nativescancode_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_nativevirtualkey_get", reinterpret_cast<void*>(qt_keyevent_nativevirtualkey_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_nativemodifiers_get", reinterpret_cast<void*>(qt_keyevent_nativemodifiers_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_text_get", reinterpret_cast<void*>(qt_keyevent_text_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_key_get", reinterpret_cast<void*>(qt_keyevent_key_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_autorepeat_get", reinterpret_cast<void*>(qt_keyevent_autorepeat_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_modifiers_get", reinterpret_cast<void*>(qt_keyevent_modifiers_get));
	mono_add_internal_call ("Qt.KeyEvent::qt_keyevent_count_get", reinterpret_cast<void*>(qt_keyevent_count_get));

	mono_add_internal_call ("Qt.Layout::qt_layout_parent_get", reinterpret_cast<void*>(qt_layout_parent_get));
	mono_add_internal_call ("Qt.Layout::qt_layout_widget_add", reinterpret_cast<void*>(qt_layout_widget_add));
	mono_add_internal_call ("Qt.Layout::qt_layout_contentsmargins_get", reinterpret_cast<void*>(qt_layout_contentsmargins_get));
	mono_add_internal_call ("Qt.Layout::qt_layout_contentsmargins_set", reinterpret_cast<void*>(qt_layout_contentsmargins_set));
	mono_add_internal_call ("Qt.Layout::qt_layout_spacing_get", reinterpret_cast<void*>(qt_layout_spacing_get));
	mono_add_internal_call ("Qt.Layout::qt_layout_spacing_set", reinterpret_cast<void*>(qt_layout_spacing_set));
	mono_add_internal_call ("Qt.Layout::qt_layout_margin_get", reinterpret_cast<void*>(qt_layout_margin_get));
	mono_add_internal_call ("Qt.Layout::qt_layout_margin_set", reinterpret_cast<void*>(qt_layout_margin_set));
	mono_add_internal_call ("Qt.Layout::qt_layout_sizeconstraint_get", reinterpret_cast<void*>(qt_layout_sizeconstraint_get));
	mono_add_internal_call ("Qt.Layout::qt_layout_sizeconstraint_set", reinterpret_cast<void*>(qt_layout_sizeconstraint_set));
	mono_add_internal_call ("Qt.Layout::qt_layout_geometry_get", reinterpret_cast<void*>(qt_layout_geometry_get));
	mono_add_internal_call ("Qt.Layout::qt_layout_geometry_set", reinterpret_cast<void*>(qt_layout_geometry_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_new", reinterpret_cast<void*>(qt_widget_new));
	mono_add_internal_call ("Qt.Widget::qt_widget_delete", reinterpret_cast<void*>(qt_widget_delete));
	mono_add_internal_call ("Qt.Widget::qt_widget_parent_get", reinterpret_cast<void*>(qt_widget_parent_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_parent_set", reinterpret_cast<void*>(qt_widget_parent_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_updategeometry", reinterpret_cast<void*>(qt_widget_updategeometry));
	mono_add_internal_call ("Qt.Widget::qt_widget_geometry_get", reinterpret_cast<void*>(qt_widget_geometry_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_geometry_set", reinterpret_cast<void*>(qt_widget_geometry_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_enabled_get", reinterpret_cast<void*>(qt_widget_enabled_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_enabled_set", reinterpret_cast<void*>(qt_widget_enabled_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_stylesheet_set", reinterpret_cast<void*>(qt_widget_stylesheet_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_fixedsize_set", reinterpret_cast<void*>(qt_widget_fixedsize_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_show", reinterpret_cast<void*>(qt_widget_show));
	mono_add_internal_call ("Qt.Widget::qt_widget_fullscreen_show", reinterpret_cast<void*>(qt_widget_fullscreen_show));
	mono_add_internal_call ("Qt.Widget::qt_widget_hide", reinterpret_cast<void*>(qt_widget_hide));
	mono_add_internal_call ("Qt.Widget::qt_widget_move", reinterpret_cast<void*>(qt_widget_move));
	mono_add_internal_call ("Qt.Widget::qt_widget_resize", reinterpret_cast<void*>(qt_widget_resize));
	mono_add_internal_call ("Qt.Widget::qt_widget_size_get", reinterpret_cast<void*>(qt_widget_size_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_size_set", reinterpret_cast<void*>(qt_widget_size_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_sizehint_get", reinterpret_cast<void*>(qt_widget_sizehint_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_width_get", reinterpret_cast<void*>(qt_widget_width_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_height_get", reinterpret_cast<void*>(qt_widget_height_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_update", reinterpret_cast<void*>(qt_widget_update));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowtitle_get", reinterpret_cast<void*>(qt_widget_windowtitle_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowtitle_set", reinterpret_cast<void*>(qt_widget_windowtitle_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowopacity_get", reinterpret_cast<void*>(qt_widget_windowopacity_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowopacity_set", reinterpret_cast<void*>(qt_widget_windowopacity_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_font_get", reinterpret_cast<void*>(qt_widget_font_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_font_set", reinterpret_cast<void*>(qt_widget_font_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowflags_get", reinterpret_cast<void*>(qt_widget_windowflags_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowflags_set", reinterpret_cast<void*>(qt_widget_windowflags_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_attribute_set", reinterpret_cast<void*>(qt_widget_attribute_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_sizepolicyhv_set", reinterpret_cast<void*>(qt_widget_sizepolicyhv_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_sizepolicy_get", reinterpret_cast<void*>(qt_widget_sizepolicy_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_sizepolicy_set", reinterpret_cast<void*>(qt_widget_sizepolicy_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_adjustsize", reinterpret_cast<void*>(qt_widget_adjustsize));

	mono_add_internal_call ("Qt.Widget::qt_widget_minimumsize_get", reinterpret_cast<void*>(qt_widget_minimumsize_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_minimumsize_set", reinterpret_cast<void*>(qt_widget_minimumsize_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_maximumsize_get", reinterpret_cast<void*>(qt_widget_maximumsize_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_maximumsize_set", reinterpret_cast<void*>(qt_widget_maximumsize_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_minimumheight_get", reinterpret_cast<void*>(qt_widget_minimumheight_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_minimumheight_set", reinterpret_cast<void*>(qt_widget_minimumheight_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_maximumheight_get", reinterpret_cast<void*>(qt_widget_maximumheight_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_maximumheight_set", reinterpret_cast<void*>(qt_widget_maximumheight_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_minimumwidth_get", reinterpret_cast<void*>(qt_widget_minimumwidth_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_minimumwidth_set", reinterpret_cast<void*>(qt_widget_minimumwidth_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_maximumwidth_get", reinterpret_cast<void*>(qt_widget_maximumwidth_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_maximumwidth_set", reinterpret_cast<void*>(qt_widget_maximumwidth_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_focuspolicy_get", reinterpret_cast<void*>(qt_widget_focuspolicy_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_focuspolicy_set", reinterpret_cast<void*>(qt_widget_focuspolicy_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowmodality_get", reinterpret_cast<void*>(qt_widget_windowmodality_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowmodality_set", reinterpret_cast<void*>(qt_widget_windowmodality_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_layoutdirection_get", reinterpret_cast<void*>(qt_widget_layoutdirection_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_layoutdirection_set", reinterpret_cast<void*>(qt_widget_layoutdirection_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_contextmenupolicy_get", reinterpret_cast<void*>(qt_widget_contextmenupolicy_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_contextmenupolicy_set", reinterpret_cast<void*>(qt_widget_contextmenupolicy_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_autofillbackground_get", reinterpret_cast<void*>(qt_widget_autofillbackground_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_autofillbackground_set", reinterpret_cast<void*>(qt_widget_autofillbackground_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_action_add", reinterpret_cast<void*>(qt_widget_action_add));

	mono_add_internal_call ("Qt.Widget::qt_widget_layout_get", reinterpret_cast<void*>(qt_widget_layout_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_layout_set", reinterpret_cast<void*>(qt_widget_layout_set));

	mono_add_internal_call ("Qt.Object::qt_objectname_get", reinterpret_cast<void*>(qt_objectname_get));
	mono_add_internal_call ("Qt.Object::qt_objectname_set", reinterpret_cast<void*>(qt_objectname_set));
	mono_add_internal_call ("Qt.Object::qt_object_find", reinterpret_cast<void*>(qt_object_find));

	mono_add_internal_call ("Qt.Font::qt_font_new", reinterpret_cast<void*>(qt_font_new));
	mono_add_internal_call ("Qt.Font::qt_font_new_with_params", reinterpret_cast<void*>(qt_font_new_with_params));
	mono_add_internal_call ("Qt.Font::qt_font_family_get", reinterpret_cast<void*>(qt_font_family_get));
	mono_add_internal_call ("Qt.Font::qt_font_family_set", reinterpret_cast<void*>(qt_font_family_set));
	mono_add_internal_call ("Qt.Font::qt_font_pointsize_get", reinterpret_cast<void*>(qt_font_pointsize_get));
	mono_add_internal_call ("Qt.Font::qt_font_pointsize_set", reinterpret_cast<void*>(qt_font_pointsize_set));

	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_new", reinterpret_cast<void*>(qt_standarditemmodel_new));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_index_get", reinterpret_cast<void*>(qt_standarditemmodel_index_get));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_item_row_set", reinterpret_cast<void*>(qt_standarditemmodel_item_row_set));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_item_row_col_set", reinterpret_cast<void*>(qt_standarditemmodel_item_row_col_set));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_item_append", reinterpret_cast<void*>(qt_standarditemmodel_item_append));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_rowcount_get", reinterpret_cast<void*>(qt_standarditemmodel_rowcount_get));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_rowcount_set", reinterpret_cast<void*>(qt_standarditemmodel_rowcount_set));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_colcount_get", reinterpret_cast<void*>(qt_standarditemmodel_colcount_get));
	mono_add_internal_call ("Qt.StandardItemModel::qt_standarditemmodel_colcount_set", reinterpret_cast<void*>(qt_standarditemmodel_colcount_set));

	mono_add_internal_call ("Qt.HeaderView::qt_headerview_visible_set", reinterpret_cast<void*>(qt_headerview_visible_set));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_section_resizemode_get", reinterpret_cast<void*>(qt_headerview_section_resizemode_get));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_section_resizemode_set", reinterpret_cast<void*>(qt_headerview_section_resizemode_set));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_section_resizemode_index_set", reinterpret_cast<void*>(qt_headerview_section_resizemode_index_set));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_sectionsize_get", reinterpret_cast<void*>(qt_headerview_sectionsize_get));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_sectionsize_set", reinterpret_cast<void*>(qt_headerview_sectionsize_set));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_defaultalignment_get", reinterpret_cast<void*>(qt_headerview_defaultalignment_get));
	mono_add_internal_call ("Qt.HeaderView::qt_headerview_defaultalignment_set", reinterpret_cast<void*>(qt_headerview_defaultalignment_set));

	mono_add_internal_call ("Qt.ModelIndex::qt_modelindex_new", reinterpret_cast<void*>(qt_modelindex_new));
	mono_add_internal_call ("Qt.ModelIndex::qt_modelindex_row_get", reinterpret_cast<void*>(qt_modelindex_row_get));
	mono_add_internal_call ("Qt.ModelIndex::qt_modelindex_col_get", reinterpret_cast<void*>(qt_modelindex_col_get));
	mono_add_internal_call ("Qt.ModelIndex::qt_modelindex_flags_get", reinterpret_cast<void*>(qt_modelindex_flags_get));

	mono_add_internal_call ("Qt.Icon::qt_icon_new", reinterpret_cast<void*>(qt_icon_new));
	mono_add_internal_call ("Qt.Icon::qt_icon_delete", reinterpret_cast<void*>(qt_icon_delete));
	mono_add_internal_call ("Qt.Icon::qt_icon_from_pixmap_new", reinterpret_cast<void*>(qt_icon_from_pixmap_new));

	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_new", reinterpret_cast<void*>(qt_pixmap_new));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_data_new", reinterpret_cast<void*>(qt_pixmap_data_new));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_delete", reinterpret_cast<void*>(qt_pixmap_delete));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_save", reinterpret_cast<void*>(qt_pixmap_save));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_scaled", reinterpret_cast<void*>(qt_pixmap_scaled));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_rotate", reinterpret_cast<void*>(qt_pixmap_rotate));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_width_get", reinterpret_cast<void*>(qt_pixmap_width_get));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_height_get", reinterpret_cast<void*>(qt_pixmap_height_get));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_size_get", reinterpret_cast<void*>(qt_pixmap_size_get));
	mono_add_internal_call ("Qt.Pixmap::qt_pixmap_depth_get", reinterpret_cast<void*>(qt_pixmap_depth_get));

	mono_add_internal_call ("Qt.Painter::qt_painter_new", reinterpret_cast<void*>(qt_painter_new));
	mono_add_internal_call ("Qt.Painter::qt_painter_pixmap_draw", reinterpret_cast<void*>(qt_painter_pixmap_draw));

	mono_add_internal_call ("Qt.Screen::qt_screen_window_grab", reinterpret_cast<void*>(qt_screen_window_grab));

	mono_add_internal_call ("Qt.Style::qt_style_alignrect_get", reinterpret_cast<void*>(qt_style_alignrect_get));

	mono_add_internal_call ("Qt.Menu::qt_menu_new", reinterpret_cast<void*>(qt_menu_new));
	mono_add_internal_call ("Qt.Menu::qt_menu_title_new", reinterpret_cast<void*>(qt_menu_title_new));
	mono_add_internal_call ("Qt.Menu::qt_menu_delete", reinterpret_cast<void*>(qt_menu_delete));
	mono_add_internal_call ("Qt.Menu::qt_menu_exec", reinterpret_cast<void*>(qt_menu_exec));
	mono_add_internal_call ("Qt.Menu::qt_menu_seperator_add", reinterpret_cast<void*>(qt_menu_seperator_add));
	mono_add_internal_call ("Qt.Menu::qt_menu_action_text_add", reinterpret_cast<void*>(qt_menu_action_text_add));
	mono_add_internal_call ("Qt.Menu::qt_menu_action_icon_text_add", reinterpret_cast<void*>(qt_menu_action_icon_text_add));
	mono_add_internal_call ("Qt.Menu::qt_menu_activeaction_get", reinterpret_cast<void*>(qt_menu_activeaction_get));
	mono_add_internal_call ("Qt.Menu::qt_menu_activeaction_set", reinterpret_cast<void*>(qt_menu_activeaction_set));

	mono_add_internal_call ("Qt.MenuBar::qt_menubar_new", reinterpret_cast<void*>(qt_menubar_new));
	mono_add_internal_call ("Qt.MenuBar::qt_menubar_delete", reinterpret_cast<void*>(qt_menubar_delete));
	mono_add_internal_call ("Qt.MenuBar::qt_menubar_action_text_add", reinterpret_cast<void*>(qt_menubar_action_text_add));
	mono_add_internal_call ("Qt.MenuBar::qt_menubar_activeaction_get", reinterpret_cast<void*>(qt_menubar_activeaction_get));
	mono_add_internal_call ("Qt.MenuBar::qt_menubar_activeaction_set", reinterpret_cast<void*>(qt_menubar_activeaction_set));

	mono_add_internal_call ("Qt.ToolBar::qt_toolbar_new", reinterpret_cast<void*>(qt_toolbar_new));

	mono_add_internal_call ("Qt.Action::qt_action_new", reinterpret_cast<void*>(qt_action_new));
	mono_add_internal_call ("Qt.Action::qt_action_delete", reinterpret_cast<void*>(qt_action_delete));
	mono_add_internal_call ("Qt.Action::qt_action_text_new", reinterpret_cast<void*>(qt_action_text_new));
	mono_add_internal_call ("Qt.Action::qt_action_text_get", reinterpret_cast<void*>(qt_action_text_get));
	mono_add_internal_call ("Qt.Action::qt_action_text_set", reinterpret_cast<void*>(qt_action_text_set));
}
