#include "cmoviewidget.h"
#include "ui_cmoviewidget.h"

cMovieWidget::cMovieWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cMovieWidget)
{
	ui->setupUi(this);
}

cMovieWidget::~cMovieWidget()
{
	delete ui;
}
