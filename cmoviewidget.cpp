#include "cmoviewidget.h"
#include "ui_cmoviewidget.h"


cMovieWidget::cMovieWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cMovieWidget),
	m_lpMovieModel(0)
{
	initUI();
}

cMovieWidget::~cMovieWidget()
{
	if(m_lpMovieModel)
		delete m_lpMovieModel;

	delete ui;
}

void cMovieWidget::initUI()
{
	ui->setupUi(this);

	m_lpMovieModel				= new QStandardItemModel(0, 2);
	QStringList	headerLabels	= QStringList() << tr("Movie") << tr("Year");
	m_lpMovieModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpMovieView->setModel(m_lpMovieModel);
}

void cMovieWidget::setLibrary(cKodiVideoLibrary* lpLibrary)
{
	m_lpLibrary	= lpLibrary;
	showList();
}

void cMovieWidget::showList()
{
	m_lpMovieModel->clear();

	m_lpLibrary->fillVideoList(m_lpMovieModel);
}
