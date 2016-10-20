#include "cmusicvideoswidget.h"
#include "ui_cmusicvideoswidget.h"

cMusicVideosWidget::cMusicVideosWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cMusicVideosWidget)
{
	ui->setupUi(this);
}

cMusicVideosWidget::~cMusicVideosWidget()
{
	delete ui;
}
