#pragma once
#include <QFrame>
#include "QGlueWidget.h"

class GlueFrame : public QFrame
{
    Q_OBJECT
public:
    GlueFrame(MonoObject* thisObject, GlueWidget* parent = 0);
};
//
//QFrame* qt_frame_new(QWidget* parent);
//QFrame::Shape qt_frame_shape_get(QFrame* widget);
//void qt_frame_shape_set(QFrame* widget, QFrame::Shape shape);
