#include "cmaintabwidget.h"
#include "cmaintabbar.h"


cMainTabWidget::cMainTabWidget(QWidget *parent) :
	QTabWidget(parent)
{
	setTabBar(new cMainTabBar());
}
