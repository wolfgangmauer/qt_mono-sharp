#include "QGlueFont.h"

GlueFont::GlueFont() : QFont()
{
}

GlueFont::GlueFont(char* family, int pointSize, int weight, bool italic) : QFont(family, pointSize, weight, italic)
{
}
