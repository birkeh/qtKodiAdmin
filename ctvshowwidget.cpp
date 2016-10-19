#include "ctvshowwidget.h"
#include "ui_ctvshowwidget.h"

cTVShowWidget::cTVShowWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cTVShowWidget)
{
	ui->setupUi(this);
}

cTVShowWidget::~cTVShowWidget()
{
	delete ui;
}
