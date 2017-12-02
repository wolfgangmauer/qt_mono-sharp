﻿#include "QGlueApplication.h"
#include "QGlueLabel.h"
#include "QGlueFrame.h"
#include "QGlueSizePolicy.h"
#include "QGlueBoxLayout.h"
#include "QGlueGridLayout.h"
#include "QGlueHBoxLayout.h"
#include "QGlueVBoxLayout.h"
#include "QGlueLayout.h"
#include "QGlueUiLoader.h"
#include "QGlueProgressBar.h"
#include "QGlueTableView.h"

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

void qt_application_attribute_set(Qt::ApplicationAttribute attribute)
{
	GlueApplication::setAttribute(attribute);
}

MonoString* qt_objectname_get(GlueObject* obj)
{
	return mono_string_new(mono_domain_get (), obj->objectName().toLatin1().data());
}

void qt_objectname_set(GlueObject* obj, MonoString* name)
{
	obj->setObjectName(name);
}

GlueUiLoader* qt_uiloader_new(MonoObject* obj, GlueObject* parent)
{
	return new GlueUiLoader(obj, parent);
}

QWidget* qt_uiloader_load(GlueUiLoader* loader, MonoString* uiFile, GlueWidget* parentWidget)
{
	char* p = mono_string_to_utf8(uiFile);
	QFile file(p);
	g_free(p);
	return loader->loadFile(&file, parentWidget);
}

QWidget* qt_object_find(QWidget* startFrom, MonoString* name)
{
	QWidget* retVal = NULL;
	char* p = mono_string_to_utf8(name);
	retVal = startFrom->findChild<QWidget*>(QLatin1String(p));
	g_free(p);
	return retVal;
}

GlueWidget* qt_widget_new(MonoObject* obj, GlueWidget* parent, Qt::WindowFlags f)
{
	return new GlueWidget(obj, parent, f);
}

MonoString* qt_widget_windowtitle_get(GlueWidget* widget)
{
	return mono_string_new(mono_domain_get (), widget->windowTitle().toLatin1().data());
}

void qt_widget_windowtitle_set(GlueWidget* widget, MonoString* windowtitle)
{
	char* p = mono_string_to_utf8(windowtitle);
	widget->setWindowTitle(p);
	g_free(p);
}

GlueWidget* qt_widget_parent_get(GlueWidget* widget)
{
	return reinterpret_cast<GlueWidget*>(widget->parentWidget());
}

void qt_widget_parent_set(GlueWidget* widget, GlueWidget* parent)
{
	widget->setParent(parent);
}

void qt_widget_show(GlueWidget* widget)
{
	widget->show();
}

void qt_widget_hide(GlueWidget* widget)
{
	widget->hide();
}

void qt_widget_attribute_set(GlueWidget* widget, Qt::WidgetAttribute attribute)
{
	widget->setAttribute(attribute);
}

Qt::WindowFlags qt_widget_windowflags_get(GlueWidget* widget)
{
	return widget->windowFlags();
}

void qt_widget_windowflags_set(GlueWidget* widget, Qt::WindowFlags type)
{
	widget->setWindowFlags(type);
}

void qt_widget_stylesheet_set(GlueWidget* widget, MonoString* stylesheet)
{
	char* p = mono_string_to_utf8(stylesheet);
	widget->setStyleSheet(p);
	g_free(p);
}

void qt_widget_fixedsize_set(GlueWidget* widget, uint32_t w, uint32_t h)
{
	widget->setFixedSize(w, h);
}

void qt_widget_resize(GlueWidget* widget, uint32_t w, uint32_t h)
{
	widget->resize(w, h);
}

void qt_widget_font_set(GlueWidget* widget, GlueFont* font)
{
	widget->setFont(*font);
}

GlueFont* qt_widget_font_get(GlueWidget* widget)
{
	return widget->font();
}

double qt_widget_windowopacity_get(GlueWidget* widget)
{
	return widget->windowOpacity();
}

void qt_widget_windowopacity_set(GlueWidget* widget, double windowopacity)
{
	widget->setWindowOpacity(windowopacity);
}

QSizePolicy* qt_widget_sizepolicy_get(GlueWidget* widget)
{
	return widget->sizePolicy();
}

void qt_widget_sizepolicy_set(GlueWidget* widget, QSizePolicy* sizePolicy)
{
	widget->setSizePolicy(*sizePolicy);
}

void qt_widget_sizepolicyhv_set(GlueWidget* widget, uint32_t horizontal, uint32_t vertical)
{
	widget->setSizePolicy((QSizePolicy::Policy)horizontal, (QSizePolicy::Policy)vertical);
}

void qt_widget_minimumsize_get(GlueWidget* widget, uint32_t* w, uint32_t* h)
{
	QSize s = widget->minimumSize();
	*w = s.width();
	*h = s.height();
}

void qt_widget_minimumsize_set(GlueWidget* widget, uint32_t w, uint32_t h)
{
	QSize s(w, h);
	widget->setMinimumSize(s);
}

void qt_widget_maximumsize_get(GlueWidget* widget, uint32_t* w, uint32_t* h)
{
	QSize s = widget->maximumSize();
	*w = s.width();
	*h = s.height();
}

void qt_widget_maximumsize_set(GlueWidget* widget, uint32_t w, uint32_t h)
{
	QSize s(w, h);
	widget->setMaximumSize(s);
}

uint32_t qt_widget_windowmodality_get(GlueWidget* widget)
{
	return (uint32_t)widget->windowModality();
}

void qt_widget_windowmodality_set(GlueWidget* widget, uint32_t windowModality)
{
	widget->setWindowModality((Qt::WindowModality)windowModality);
}

uint32_t qt_widget_focuspolicy_get(GlueWidget* widget)
{
	return (uint32_t)widget->focusPolicy();
}

void qt_widget_focuspolicy_set(GlueWidget* widget, uint32_t focusPolicy)
{
	widget->setFocusPolicy((Qt::FocusPolicy)focusPolicy);
}

uint qt_widget_contextmenupolicy_get(GlueWidget* widget)
{
	return (uint32_t)widget->contextMenuPolicy();
}

void qt_widget_contextmenupolicy_set(GlueWidget* widget, uint32_t contextMenuPolicy)
{
	widget->setContextMenuPolicy((Qt::ContextMenuPolicy)contextMenuPolicy);
}

bool qt_widget_autofillbackground_get(GlueWidget* widget)
{
	return widget->autoFillBackground();
}

void qt_widget_autofillbackground_set(GlueWidget* widget, bool autofillbackground)
{
	widget->setAutoFillBackground(autofillbackground);
}

void qt_widget_adjustsize(GlueWidget* widget)
{
	widget->adjustSize();
}

void qt_widget_geometry_get(GlueWidget* widget, int* x, int* y, int* width, int* height)
{
	widget->geometry(x, y, width, height);
}

void qt_widget_geometry_set(GlueWidget* widget, int x, int y, int width, int height)
{
	widget->setGeometry(x, y, width, height);
}

void qt_widget_updategeometry(GlueWidget* widget)
{
	widget->updateGeometry();
}

GlueBoxLayout* qt_boxlayout_new(MonoObject* thisObject, QBoxLayout::Direction dir, GlueWidget* parent)
{
	return new GlueBoxLayout(thisObject, dir, parent);
}

void qt_boxlayout_widget_add(GlueBoxLayout* boxlayout, GlueWidget* widget, int stretch, Qt::Alignment alignment)
{
	boxlayout->addWidget(widget, stretch, alignment);
}

void qt_boxlayout_layout_add(GlueBoxLayout* boxlayout, GlueLayout* layout, int stretch)
{
	boxlayout->addLayout(layout, stretch);
}

QBoxLayout::Direction qt_boxlayout_direction_get(GlueBoxLayout* boxlayout)
{
	return boxlayout->direction();
}

void qt_boxlayout_direction_set(GlueBoxLayout* boxlayout, QBoxLayout::Direction direction)
{
	return boxlayout->setDirection(direction);
}

GlueGridLayout* qt_gridlayout_new(MonoObject* thisObject, GlueWidget* parent)
{
	return new GlueGridLayout(thisObject, parent);
}

void qt_gridlayout_widget_add(GlueGridLayout* gridlayout, GlueWidget* widget)
{
	gridlayout->addWidget(widget);
}

void qt_gridlayout_widget_alignment_add(GlueGridLayout* gridlayout, GlueWidget* widget, int row, int column, Qt::Alignment alignment)
{
	gridlayout->addWidget(widget, row, column, alignment);
}

void qt_gridlayout_widget_span_add(GlueGridLayout* gridlayout, GlueWidget* widget, int row, int column, int rowSpan, int columnSpan, Qt::Alignment alignment)
{
	gridlayout->addWidget(widget, row, column, rowSpan, columnSpan, alignment);
}

GlueDialog* qt_dialog_new(MonoObject* thisObject, GlueWidget* parent, uint32_t f)
{
	return new GlueDialog(thisObject, parent, (Qt::WindowFlags)f);
}

int qt_dialog_exec(GlueDialog* dialog)
{
	return dialog->exec();
}

bool qt_dialog_modal_get(GlueDialog* dialog)
{
	return dialog->isModal();
}

void qt_dialog_modal_set(GlueDialog* dialog, bool modal)
{
	dialog->setModal(modal);
}

GlueVBoxLayout* qt_vboxlayout_new(MonoObject* thisObject, GlueWidget* parent)
{
	return new GlueVBoxLayout(thisObject, parent);
}

GlueHBoxLayout* qt_hboxlayout_new(MonoObject* thisObject, GlueWidget* parent)
{
	return new GlueHBoxLayout(thisObject, parent);
}

GlueFrame* qt_frame_new(MonoObject* thisObject, GlueWidget* parent)
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

GlueLabel* qt_label_new(MonoObject* thisObject, GlueWidget* parent, Qt::WindowFlags f)
{
	return new GlueLabel(thisObject, parent, f);
}

GlueLabel* qt_label_new_with_text(MonoObject* thisObject, MonoString* text, GlueWidget* parent, Qt::WindowFlags f)
{
	GlueLabel* retVal;
	char* p = mono_string_to_utf8(text);
	retVal = new GlueLabel(thisObject, p, parent, f);
	g_free(p);
	return retVal;
}

MonoString* qt_label_text_get(GlueLabel* label)
{
	return mono_string_new(mono_domain_get (), label->text().toLatin1().data());
}

void qt_label_text_set(GlueLabel* label, MonoString* text)
{
	label->setText(text);
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

GlueProgressBar* qt_progressbar_new(MonoObject* thisObject, GlueWidget* parent)
{
	return new GlueProgressBar(thisObject, parent);
}

void qt_layout_widget_add(GlueLayout* layout, GlueWidget* widget)
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

void qt_layout_geometry_get(QLayout* layout, int* x, int* y, int* width, int* height)
{
	QRect r = layout->geometry();
	r.getRect(x, y, width, height);
}

void qt_layout_geometry_set(GlueLayout* layout, int x, int y, int width, int height)
{
	QRect r;
	r.setRect(x, y, width, height);
	layout->setGeometry(r);
}

GlueFont* qt_font_new()
{
	return new GlueFont();
}

GlueFont* qt_font_new_with_params(MonoString* fontfamily, int pointSize, int weight, bool italic)
{
	GlueFont* retVal;
	char* p = mono_string_to_utf8(fontfamily);
	retVal = new GlueFont(p, pointSize, weight, italic);
	g_free(p);
	return retVal;
}

MonoString* qt_font_family_get(GlueFont* font)
{
	return mono_string_new(mono_domain_get (), font->family().toLatin1().data());
}

void qt_font_family_set(GlueFont* obj, MonoString* fontfamily)
{
	char* p = mono_string_to_utf8(fontfamily);
	obj->setFamily(p);
	g_free(p);
}

int qt_font_pointsize_get(GlueFont* obj)
{
	return obj->pointSize();
}

void qt_font_pointsize_set(GlueFont* obj, int pointsize)
{
	obj->setPointSize(pointsize);
}

GlueMainWindow* qt_mainwindow_new(MonoObject* obj, GlueWidget* parent, Qt::WindowFlags f)
{
	return new GlueMainWindow(obj, parent, f);
}

GlueSizePolicy* qt_sizepolicy_new ()
{
	return new GlueSizePolicy();
}

GlueSizePolicy* qt_sizepolicy_new_with_policy (QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical)
{
	return new GlueSizePolicy(horizontal, vertical);
}

GlueSizePolicy* qt_sizepolicy_new_with_controltype (QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical, QSizePolicy::ControlType type)
{
	return new GlueSizePolicy(horizontal, vertical, type);
}

QSizePolicy::Policy qt_sizepolicy_horizontal_get(QSizePolicy* policy)
{
	return policy->horizontalPolicy();
}

void qt_sizepolicy_horizontal_set(GlueSizePolicy* policy, QSizePolicy::Policy horizontal)
{
	policy->setHorizontalPolicy(horizontal);
}

QSizePolicy::Policy qt_sizepolicy_vertical_get(GlueSizePolicy* policy)
{
	return policy->verticalPolicy();
}

void qt_sizepolicy_vertical_set(GlueSizePolicy* policy, QSizePolicy::Policy vertical)
{
	policy->setVerticalPolicy(vertical);
}

QSizePolicy::ControlType qt_sizepolicy_controltype_get(GlueSizePolicy* policy)
{
	return policy->controlType();
}

void qt_sizepolicy_controltype_set(GlueSizePolicy* policy, QSizePolicy::ControlType controlType)
{
	policy->setControlType(controlType);
}

Qt::Orientations qt_sizepolicy_expanding_directions(GlueSizePolicy* policy)
{
	return policy->expandingDirections();
}

bool qt_sizepolicy_heightforwidth_get(GlueSizePolicy* policy)
{
	return policy->hasHeightForWidth();
}

void qt_sizepolicy_heightforwidth_set(GlueSizePolicy* policy, bool heightForWidth)
{
	policy->setHeightForWidth(heightForWidth);
}

bool qt_sizepolicy_widthforheight_get(GlueSizePolicy* policy)
{
	return policy->hasHeightForWidth();
}

void qt_sizepolicy_widthforheight_set(GlueSizePolicy* policy, bool widthForHeight)
{
	policy->setHeightForWidth(widthForHeight);
}

int qt_sizepolicy_horizontalstretch_get(GlueSizePolicy* policy)
{
	return policy->horizontalStretch();
}

void qt_sizepolicy_horizontalstretch_set(GlueSizePolicy* policy, int horizontalStretch)
{
	policy->setHorizontalStretch((unsigned char)horizontalStretch);
}

bool qt_sizepolicy_verticalstretch_get(GlueSizePolicy* policy)
{
	return policy->verticalStretch();
}

void qt_sizepolicy_verticalstretch_set(GlueSizePolicy* policy, int verticalStretch)
{
	policy->setVerticalStretch((unsigned char)verticalStretch);
}

GlueTableView* qt_tableview_new(MonoObject* thisObject, GlueWidget* parent)
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

extern "C" void qt_application_monointernal_init()
{
	mono_add_internal_call ("Qt.Application::qt_application_new", reinterpret_cast<void*>(qt_application_new));
	mono_add_internal_call ("Qt.Application::qt_application_exec", reinterpret_cast<void*>(qt_application_exec));
	mono_add_internal_call ("Qt.CoreApplication::qt_application_attribute_set", reinterpret_cast<void*>(qt_application_attribute_set));

	mono_add_internal_call ("Qt.UiLoader::qt_uiloader_new", reinterpret_cast<void*>(qt_uiloader_new));
	mono_add_internal_call ("Qt.UiLoader::qt_uiloader_load", reinterpret_cast<void*>(qt_uiloader_load));

	mono_add_internal_call ("Qt.MainWindow::qt_mainwindow_new", reinterpret_cast<void*>(qt_mainwindow_new));

	mono_add_internal_call ("Qt.Dialog::qt_dialog_new", reinterpret_cast<void*>(qt_dialog_new));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_modal_get", reinterpret_cast<void*>(qt_dialog_modal_get));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_modal_set", reinterpret_cast<void*>(qt_dialog_modal_set));
	mono_add_internal_call ("Qt.Dialog::qt_dialog_exec", reinterpret_cast<void*>(qt_dialog_exec));

	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_new", reinterpret_cast<void*>(qt_progressbar_new));

	mono_add_internal_call ("Qt.TableView::qt_tableview_new", reinterpret_cast<void*>(qt_tableview_new));
	mono_add_internal_call ("Qt.TableView::qt_widget_horizontalheader_get", reinterpret_cast<void*>(qt_widget_horizontalheader_get));
	mono_add_internal_call ("Qt.TableView::qt_widget_verticalheader_get", reinterpret_cast<void*>(qt_widget_verticalheader_get));


	mono_add_internal_call ("Qt.Label::qt_label_new", reinterpret_cast<void*>(qt_label_new));
	mono_add_internal_call ("Qt.Label::qt_label_new_with_text", reinterpret_cast<void*>(qt_label_new_with_text));
	mono_add_internal_call ("Qt.Label::qt_label_text_get", reinterpret_cast<void*>(qt_label_text_get));
	mono_add_internal_call ("Qt.Label::qt_label_text_set", reinterpret_cast<void*>(qt_label_text_set));
	mono_add_internal_call ("Qt.Label::qt_label_alignment_get", reinterpret_cast<void*>(qt_label_alignment_get));
	mono_add_internal_call ("Qt.Label::qt_label_alignment_set", reinterpret_cast<void*>(qt_label_alignment_set));
	mono_add_internal_call ("Qt.Label::qt_label_indent_get", reinterpret_cast<void*>(qt_label_indent_get));
	mono_add_internal_call ("Qt.Label::qt_label_indent_set", reinterpret_cast<void*>(qt_label_indent_set));
	mono_add_internal_call ("Qt.Label::qt_label_textinteractionflags_get", reinterpret_cast<void*>(qt_label_textinteractionflags_get));
	mono_add_internal_call ("Qt.Label::qt_label_textinteractionflags_set", reinterpret_cast<void*>(qt_label_textinteractionflags_set));

	mono_add_internal_call ("Qt.Label::qt_label_textformat_get", reinterpret_cast<void*>(qt_label_textformat_get));
	mono_add_internal_call ("Qt.Label::qt_label_textformat_set", reinterpret_cast<void*>(qt_label_textformat_set));

	mono_add_internal_call ("Qt.Frame::qt_frame_new", reinterpret_cast<void*>(qt_frame_new));
	mono_add_internal_call ("Qt.Frame::qt_frame_shape_get", reinterpret_cast<void*>(qt_frame_shape_get));
	mono_add_internal_call ("Qt.Frame::qt_frame_shape_set", reinterpret_cast<void*>(qt_frame_shape_set));
	mono_add_internal_call ("Qt.Frame::qt_frame_shadow_get", reinterpret_cast<void*>(qt_frame_shadow_get));
	mono_add_internal_call ("Qt.Frame::qt_frame_shadow_set", reinterpret_cast<void*>(qt_frame_shadow_set));
	mono_add_internal_call ("Qt.Frame::qt_frame_linewidth_get", reinterpret_cast<void*>(qt_frame_linewidth_get));
	mono_add_internal_call ("Qt.Frame::qt_frame_linewidth_set", reinterpret_cast<void*>(qt_frame_linewidth_set));


	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_value_get", reinterpret_cast<void*>(qt_progressbar_value_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_value_set", reinterpret_cast<void*>(qt_progressbar_value_set));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_minimum_get", reinterpret_cast<void*>(qt_progressbar_minimum_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_minimum_set", reinterpret_cast<void*>(qt_progressbar_minimum_set));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_maximum_get", reinterpret_cast<void*>(qt_progressbar_maximum_get));
	mono_add_internal_call ("Qt.ProgressBar::qt_progressbar_maximum_set", reinterpret_cast<void*>(qt_progressbar_maximum_set));


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
	mono_add_internal_call ("Qt.Widget::qt_widget_parent_get", reinterpret_cast<void*>(qt_widget_parent_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_parent_set", reinterpret_cast<void*>(qt_widget_parent_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_updategeometry", reinterpret_cast<void*>(qt_widget_updategeometry));
	mono_add_internal_call ("Qt.Widget::qt_widget_geometry_get", reinterpret_cast<void*>(qt_widget_geometry_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_geometry_set", reinterpret_cast<void*>(qt_widget_geometry_set));

	mono_add_internal_call ("Qt.Widget::qt_widget_stylesheet_set", reinterpret_cast<void*>(qt_widget_stylesheet_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_fixedsize_set", reinterpret_cast<void*>(qt_widget_fixedsize_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_show", reinterpret_cast<void*>(qt_widget_show));
	mono_add_internal_call ("Qt.Widget::qt_widget_hide", reinterpret_cast<void*>(qt_widget_hide));
	mono_add_internal_call ("Qt.Widget::qt_widget_resize", reinterpret_cast<void*>(qt_widget_resize));
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
	mono_add_internal_call ("Qt.Widget::qt_widget_focuspolicy_get", reinterpret_cast<void*>(qt_widget_focuspolicy_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_focuspolicy_set", reinterpret_cast<void*>(qt_widget_focuspolicy_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowmodality_get", reinterpret_cast<void*>(qt_widget_windowmodality_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_windowmodality_set", reinterpret_cast<void*>(qt_widget_windowmodality_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_contextmenupolicy_get", reinterpret_cast<void*>(qt_widget_contextmenupolicy_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_contextmenupolicy_set", reinterpret_cast<void*>(qt_widget_contextmenupolicy_set));
	mono_add_internal_call ("Qt.Widget::qt_widget_autofillbackground_get", reinterpret_cast<void*>(qt_widget_autofillbackground_get));
	mono_add_internal_call ("Qt.Widget::qt_widget_autofillbackground_set", reinterpret_cast<void*>(qt_widget_autofillbackground_set));

	mono_add_internal_call ("Qt.Object::qt_objectname_get", reinterpret_cast<void*>(qt_objectname_get));
	mono_add_internal_call ("Qt.Object::qt_objectname_set", reinterpret_cast<void*>(qt_objectname_set));
	mono_add_internal_call ("Qt.Object::qt_object_find", reinterpret_cast<void*>(qt_object_find));


	mono_add_internal_call ("Qt.Font::qt_font_new", reinterpret_cast<void*>(qt_font_new));
	mono_add_internal_call ("Qt.Font::qt_font_new_with_params", reinterpret_cast<void*>(qt_font_new_with_params));
	mono_add_internal_call ("Qt.Font::qt_font_family_get", reinterpret_cast<void*>(qt_font_family_get));
	mono_add_internal_call ("Qt.Font::qt_font_family_set", reinterpret_cast<void*>(qt_font_family_set));
	mono_add_internal_call ("Qt.Font::qt_font_pointsize_get", reinterpret_cast<void*>(qt_font_pointsize_get));
	mono_add_internal_call ("Qt.Font::qt_font_pointsize_set", reinterpret_cast<void*>(qt_font_pointsize_set));
}
