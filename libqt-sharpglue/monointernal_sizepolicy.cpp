#include "QGlueSizePolicy.h"

static GlueSizePolicy* qt_sizepolicy_new ()
{
	return new GlueSizePolicy();
}

static GlueSizePolicy* qt_sizepolicy_new_with_policy (QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical)
{
	return new GlueSizePolicy(horizontal, vertical);
}

static GlueSizePolicy* qt_sizepolicy_new_with_controltype (QSizePolicy::Policy horizontal, QSizePolicy::Policy vertical, QSizePolicy::ControlType type)
{
	return new GlueSizePolicy(horizontal, vertical, type);
}

static QSizePolicy::Policy qt_sizepolicy_horizontal_get(QSizePolicy* policy)
{
	return policy->horizontalPolicy();
}

static void qt_sizepolicy_horizontal_set(GlueSizePolicy* policy, QSizePolicy::Policy horizontal)
{
	policy->setHorizontalPolicy(horizontal);
}

static QSizePolicy::Policy qt_sizepolicy_vertical_get(GlueSizePolicy* policy)
{
	return policy->verticalPolicy();
}

static void qt_sizepolicy_vertical_set(GlueSizePolicy* policy, QSizePolicy::Policy vertical)
{
	policy->setVerticalPolicy(vertical);
}

static QSizePolicy::ControlType qt_sizepolicy_controltype_get(GlueSizePolicy* policy)
{
	return policy->controlType();
}

static void qt_sizepolicy_controltype_set(GlueSizePolicy* policy, QSizePolicy::ControlType controlType)
{
	policy->setControlType(controlType);
}

static Qt::Orientations qt_sizepolicy_expanding_directions(GlueSizePolicy* policy)
{
	return policy->expandingDirections();
}

static bool qt_sizepolicy_heightforwidth_get(GlueSizePolicy* policy)
{
	return policy->hasHeightForWidth();
}

static void qt_sizepolicy_heightforwidth_set(GlueSizePolicy* policy, bool heightForWidth)
{
	policy->setHeightForWidth(heightForWidth);
}

static bool qt_sizepolicy_widthforheight_get(GlueSizePolicy* policy)
{
	return policy->hasHeightForWidth();
}

static void qt_sizepolicy_widthforheight_set(GlueSizePolicy* policy, bool widthForHeight)
{
	policy->setHeightForWidth(widthForHeight);
}

static int qt_sizepolicy_horizontalstretch_get(GlueSizePolicy* policy)
{
	return policy->horizontalStretch();
}

static void qt_sizepolicy_horizontalstretch_set(GlueSizePolicy* policy, int horizontalStretch)
{
	policy->setHorizontalStretch((unsigned char)horizontalStretch);
}

static bool qt_sizepolicy_verticalstretch_get(GlueSizePolicy* policy)
{
	return policy->verticalStretch();
}

static void qt_sizepolicy_verticalstretch_set(GlueSizePolicy* policy, int verticalStretch)
{
	policy->setVerticalStretch((unsigned char)verticalStretch);
}
