#pragma once
#include <QFont>

class GlueFont : public QFont
{
    //Q_GADGET
public:
    GlueFont();
    GlueFont(char* family, int pointSize, int weight, bool italic);
};
