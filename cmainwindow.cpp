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

	if(m_lpMusicWidget)
		delete m_lpMusicWidget;

	if(m_lpMusicVideoWidget)
		delete m_lpMusicVideoWidget;

	delete ui;
}

void cMainWindow::initUI()
{
	ui->setupUi(this);

	m_lpMovieWidget			= new cMovieWidget(this);
	m_lpTVShowWidget		= new cTVShowWidget(this);
	m_lpMusicWidget			= new cMusicWidget(this);
	m_lpMusicVideoWidget	= new cMusicVideosWidget(this);

	ui->m_lpMainTab->addTab(m_lpMovieWidget, QIcon(":/icons/Videos.ico"), "Movies");
	ui->m_lpMainTab->addTab(m_lpTVShowWidget, QIcon(":/icons/TV Shows.ico"), "TV Shows");
	ui->m_lpMainTab->addTab(m_lpMusicWidget, QIcon(":/icons/Musics.ico"), "Music");
	ui->m_lpMainTab->addTab(m_lpMusicVideoWidget, QIcon(":/icons/Videos.ico"), "Music Videos");

	ui->m_lpMainTab->setCurrentIndex(0);

	setWindowTitle("qtKodiAdmin");
}

void cMainWindow::initDB()
{
	m_kodiLibrary.init(QDir::homePath() + QDir::separator() + QString(".kodi"));
}
