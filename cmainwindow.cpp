#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include <QDir>
#include <QIcon>


cMainWindow::cMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow),
	m_lpMovieWidget(0),
	m_lpTVShowWidget(0)
{
	initUI();
	initDB();
}

cMainWindow::~cMainWindow()
{
	if(m_lpMovieWidget)
		delete m_lpMovieWidget;

	if(m_lpTVShowWidget)
		delete m_lpTVShowWidget;

	delete ui;
}

void cMainWindow::initUI()
{
	ui->setupUi(this);

	m_lpMovieWidget		= new cMovieWidget(this);
	m_lpTVShowWidget	= new cTVShowWidget(this);

	ui->m_lpMainTab->addTab(m_lpMovieWidget, QIcon(":/icons/Videos.ico"), "");
	ui->m_lpMainTab->addTab(m_lpTVShowWidget, QIcon(":/icons/TV Shows.ico"), "");
	ui->m_lpMainTab->setCurrentIndex(0);

	setWindowTitle("qtKodiAdmin");
}

void cMainWindow::initDB()
{
	m_kodiLibrary.init(QDir::homePath() + QDir::separator() + QString(".kodi"));
}
