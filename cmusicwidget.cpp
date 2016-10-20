#include "cmusicwidget.h"
#include "ui_cmusicwidget.h"

cMusicWidget::cMusicWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cMusicWidget)
{
	ui->setupUi(this);
}

cMusicWidget::~cMusicWidget()
{
	delete ui;
}
