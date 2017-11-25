#include "QGlueSizePolicy.h"

GlueSizePolicy::GlueSizePolicy() : QSizePolicy()
{
}

GlueSizePolicy::GlueSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical) : QSizePolicy(horizontal, vertical)
{
}

GlueSizePolicy::GlueSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical, QSizePolicy::ControlType type) : QSizePolicy(horizontal, vertical, type)
{
}
