#include "QGlueApplication.h"
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
#include "QGlueStandardItemModel.h"
#include "QGlueTableView.h"
#include "QGlueTableWidget.h"
#include "QGlueModelIndex.h"

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
	return mono_string_new(mono_domain_get (), obj->objectName().toStdString().c_str());
}

void qt_objectname_set(GlueObject* obj, MonoString* name)
{
	obj->setObjectName(name);
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

void qt_widget_parent_set(GlueWidget* widget, QWidget* parent)
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

void qt_widget_font_set(QWidget* widget, const QFont& font)
{
	widget->setFont(font);
}

QFont qt_widget_font_get(GlueWidget* widget)
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

QLayout* qt_widget_layout_get(GlueWidget* widget)
{
	return widget->layout();
}

void qt_widget_layout_set(GlueWidget* widget, QLayout* layout)
{
	return widget->setLayout(layout);
}

void qt_widget_adjustsize(GlueWidget* widget)
{
	widget->adjustSize();
}

const QRect qt_widget_geometry_get(GlueWidget* widget)
{
	return widget->geometry();
}

void qt_widget_geometry_set(GlueWidget* widget, const QRect& rect)
{
	widget->setGeometry(rect);
}

void qt_widget_updategeometry(GlueWidget* widget)
{
	widget->updateGeometry();
}

GlueBoxLayout* qt_boxlayout_new(MonoObject* thisObject, QBoxLayout::Direction dir, QWidget* parent)
{
	return new GlueBoxLayout(thisObject, dir, parent);
}

void qt_boxlayout_widget_add(GlueBoxLayout* layout, GlueWidget* widget, int stretch, Qt::Alignment alignment)
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

void qt_gridlayout_widget_add(GlueGridLayout* gridlayout, GlueWidget* widget)
{
	gridlayout->addWidget(widget);
}

void qt_gridlayout_widget_alignment_add(GlueGridLayout* gridlayout, GlueWidget* widget, int row, int col, Qt::Alignment alignment)
{
	gridlayout->addWidget(widget, row, col, alignment);
}

void qt_gridlayout_widget_span_add(GlueGridLayout* gridlayout, GlueWidget* widget, int row, int col, int rowSpan, int colSpan, Qt::Alignment alignment)
{
	gridlayout->addWidget(widget, row, col, rowSpan, colSpan, alignment);
}

GlueDialog* qt_dialog_new(MonoObject* thisObject, QWidget* parent, uint32_t f)
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

GlueProgressBar* qt_progressbar_new(MonoObject* thisObject, QWidget* parent)
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

const QRect qt_layout_geometry_get(QLayout* layout)
{
	return layout->geometry();
}

void qt_layout_geometry_set(GlueLayout* layout, const QRect& rect)
{
	layout->setGeometry(rect);
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

GlueMainWindow* qt_mainwindow_new(MonoObject* obj, QWidget* parent, Qt::WindowFlags f)
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

const QPoint qt_contextmenuevent_pos_get(QContextMenuEvent* event)
{
	return event->pos();
}

const QPoint qt_contextmenuevent_globalpos_get(QContextMenuEvent* event)
{
	return event->globalPos();
}

const QRect qt_paintevent_rect_get(QPaintEvent* event)
{
	return event->rect();
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

QPointF qt_wheelevent_globalposf_get(QWheelEvent* event)
{
	return event->globalPosF();
}

QPointF qt_wheelevent_posf_get(QWheelEvent* event)
{
	return event->posF();
}

Qt::Orientation qt_wheelevent_orientation_get(QWheelEvent* event)
{
	return event->orientation();
}

int qt_wheelevent_delta_get(QWheelEvent* event)
{
	return event->delta();
}

QPoint qt_wheelevent_angledelta_get(QWheelEvent* event)
{
	return event->angleDelta();
}

QPoint qt_wheelevent_pixeldelta_get(QWheelEvent* event)
{
	return event->pixelDelta();
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

QPointF qt_mouseevent_localpos_get(QMouseEvent* event)
{
	return event->localPos();
}

QPointF qt_mouseevent_windowpos_get(QMouseEvent* event)
{
	return event->windowPos();
}

QPointF qt_mouseevent_screenpos_get(QMouseEvent* event)
{
	return event->screenPos();
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

const QPoint qt_moveevent_pos_get(QMoveEvent* event)
{
	return event->pos();
}

const QPoint qt_moveevent_oldpos_get(QMoveEvent* event)
{
	return event->oldPos();
}

const QSize qt_resizeevent_size_get(QResizeEvent* event)
{
	return event->size();
}

const QSize qt_resizeevent_oldsize_get(QResizeEvent* event)
{
	return event->oldSize();
}

int qt_size_width_get(QSize size)
{
	return size.width();
}

void qt_size_width_set(QSize size, int width)
{
	return size.setWidth(width);
}

int qt_size_height_get(QSize size)
{
	return size.height();
}

void qt_size_height_set(QSize size, int height)
{
	return size.setHeight(height);
}

int qt_rectangle_x_get(QRect rect)
{
	return rect.x();
}

void qt_rectangle_x_set(QRect rect, int x)
{
	return rect.setX(x);
}

int qt_rectangle_y_get(QRect rect)
{
	return rect.y();
}

void qt_rectangle_y_set(QRect rect, int y)
{
	return rect.setY(y);
}

int qt_rectangle_width_get(QRect rect)
{
	return rect.width();
}

void qt_rectangle_width_set(QRect rect, int width)
{
	return rect.setWidth(width);
}

int qt_rectangle_height_get(QRect rect)
{
	return rect.height();
}

void qt_rectangle_height_set(QRect rect, int height)
{
	return rect.setHeight(height);
}

int qt_point_x_get(QPoint point)
{
	return point.x();
}

void qt_point_x_set(QPoint point, int x)
{
	return point.setX(x);
}

int qt_point_y_get(QPoint point)
{
	return point.y();
}

void qt_point_y_set(QPoint point, int y)
{
	return point.setY(y);
}

double qt_pointf_x_get(QPointF point)
{
	return point.x();
}

void qt_pointf_x_set(QPointF point, double x)
{
	return point.setX(x);
}

double qt_pointf_y_get(QPointF point)
{
	return point.y();
}

void qt_pointf_y_set(QPointF point, double y)
{
	return point.setY(y);
}

GlueStandardItemModel* qt_standarditemmodel_new(MonoObject* thisObject, GlueObject* parent)
{
	return new GlueStandardItemModel(thisObject, parent);
}

void qt_standarditemmodel_index_get(QStandardItemModel* standardItemModel, int row, int col, QModelIndex* modelIndex)
{
	QModelIndex i = standardItemModel->index(row, col);
	modelIndex = &i;
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

GlueStandardItemModel* qt_itemview_model_get(GlueTableView* abstractItemView)
{
	return (GlueStandardItemModel*)abstractItemView->model();
}

void qt_itemview_model_set(GlueTableView* abstractItemView, GlueStandardItemModel* itemModel)
{
	abstractItemView->setModel(itemModel);
}

QAbstractItemView::SelectionBehavior qt_itemview_selectctionbehavior_get(GlueTableView* abstractItemView)
{
	return abstractItemView->selectionBehavior();
}

void qt_itemview_selectctionbehavior_set(GlueTableView* abstractItemView, QAbstractItemView::SelectionBehavior selectionBehavior)
{
	abstractItemView->setSelectionBehavior(selectionBehavior);
}

QAbstractItemView::SelectionMode qt_itemview_selectctionmode_get(GlueTableView* abstractItemView)
{
	return abstractItemView->selectionMode();
}

void qt_itemview_selectctionmode_set(GlueTableView* abstractItemView, QAbstractItemView::SelectionMode mode)
{
	abstractItemView->setSelectionMode(mode);
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

QTableWidgetItem* qt_tablewidgetitem_new(MonoString* text)
{
	QTableWidgetItem* retVal = NULL;
	char* p = mono_string_to_utf8(text);
	retVal = new QTableWidgetItem(p);
	g_free(p);
	return retVal;
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

int qt_tablewidget_rowcount_get(QTableWidget* tableWidget)
{
	return tableWidget->rowCount();
}

void qt_tablewidget_rowcount_set(QTableWidget* tableWidget, int rows)
{
	return tableWidget->setRowCount(rows);
}

int qt_tablewidget_colcount_get(QTableWidget* tableWidget)
{
	return tableWidget->columnCount();
}

void qt_tablewidget_colcount_set(QTableWidget* tableWidget, int cols)
{
	return tableWidget->setColumnCount(cols);
}

void qt_tablewidget_row_col_set(QTableWidget* tableWidget, int row, int col, QTableWidgetItem* item)
{
	tableWidget->setItem(row, col, item);
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

	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_new", reinterpret_cast<void*>(qt_tablewidget_new));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_rowcount_get", reinterpret_cast<void*>(qt_tablewidget_rowcount_get));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_rowcount_set", reinterpret_cast<void*>(qt_tablewidget_rowcount_set));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_colcount_get", reinterpret_cast<void*>(qt_tablewidget_colcount_get));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_colcount_set", reinterpret_cast<void*>(qt_tablewidget_colcount_set));
	mono_add_internal_call ("Qt.TableWidget::qt_tablewidget_row_col_set", reinterpret_cast<void*>(qt_tablewidget_row_col_set));

	mono_add_internal_call ("Qt.ItemView::qt_itemview_model_get", reinterpret_cast<void*>(qt_itemview_model_get));
	mono_add_internal_call ("Qt.ItemView::qt_itemview_model_set", reinterpret_cast<void*>(qt_itemview_model_set));
	mono_add_internal_call ("Qt.ItemView::qt_itemview_selectctionbehavior_get", reinterpret_cast<void*>(qt_itemview_selectctionbehavior_get));
	mono_add_internal_call ("Qt.ItemView::qt_itemview_selectctionbehavior_set", reinterpret_cast<void*>(qt_itemview_selectctionbehavior_set));
	mono_add_internal_call ("Qt.ItemView::qt_itemview_selectctionmode_get", reinterpret_cast<void*>(qt_itemview_selectctionmode_get));
	mono_add_internal_call ("Qt.ItemView::qt_itemview_selectctionmode_set", reinterpret_cast<void*>(qt_itemview_selectctionmode_set));

	mono_add_internal_call ("Qt.StandardItem::qt_standarditem_new", reinterpret_cast<void*>(qt_standarditem_new));

	mono_add_internal_call ("Qt.TableWidgetItem::qt_tablewidgetitem_new", reinterpret_cast<void*>(qt_tablewidgetitem_new));

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
}
