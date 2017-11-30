#pragma once
#include <QSizePolicy>

class GlueSizePolicy : public QSizePolicy
{
    //Q_GADGET
public:
    GlueSizePolicy();
    GlueSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical);
    GlueSizePolicy(QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical, QSizePolicy::ControlType type);
};
