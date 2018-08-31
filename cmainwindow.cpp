#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include <QDir>
#include <QIcon>

#include <QSettings>


cMainWindow::cMainWindow(QWidget *parent, QSplashScreen *lpSplashScreen) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow),
	m_lpVideoWidget(0),
	m_lpTVShowWidget(0),
	m_lpMusicWidget(0),
	m_lpMusicVideoWidget(0),
	m_lpKodiLibrary(0)
{
	initUI(lpSplashScreen);
	initDB(lpSplashScreen);
}

cMainWindow::~cMainWindow()
{
	if(m_lpVideoWidget)
		delete m_lpVideoWidget;

	if(m_lpTVShowWidget)
		delete m_lpTVShowWidget;

	if(m_lpMusicWidget)
		delete m_lpMusicWidget;

	if(m_lpMusicVideoWidget)
		delete m_lpMusicVideoWidget;

	if(m_lpKodiLibrary)
		delete m_lpKodiLibrary;

	delete ui;
}

void cMainWindow::initUI(QSplashScreen* lpSplashScreen)
{
	QSettings	settings;

	ui->setupUi(this);

	lpSplashScreen->showMessage("initializing UI ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
	QApplication::processEvents();

	m_lpVideoWidget			= new cVideoWidget(this);
	m_lpTVShowWidget		= new cTVShowWidget(this);
	m_lpMusicWidget			= new cMusicWidget(this);
	m_lpMusicVideoWidget	= new cMusicVideosWidget(this);

	if(settings.value("icons").toBool())
	{
		ui->m_lpMainTab->addTab(m_lpVideoWidget, QIcon(":/icons/Videos.ico"), "Movies");
		ui->m_lpMainTab->addTab(m_lpTVShowWidget, QIcon(":/icons/TV Shows.ico"), "TV Shows");
		ui->m_lpMainTab->addTab(m_lpMusicWidget, QIcon(":/icons/Musics.ico"), "Music");
		ui->m_lpMainTab->addTab(m_lpMusicVideoWidget, QIcon(":/icons/Videos.ico"), "Music Videos");
	}
	else
	{
		ui->m_lpMainTab->addTab(m_lpVideoWidget, QIcon(":/icons/empty.ico"), tr("Movies"));
		ui->m_lpMainTab->addTab(m_lpTVShowWidget, QIcon(":/icons/empty.ico"), tr("TV Shows"));
		ui->m_lpMainTab->addTab(m_lpMusicWidget, QIcon(":/icons/empty.ico"), tr("Music"));
		ui->m_lpMainTab->addTab(m_lpMusicVideoWidget, QIcon(":/icons/empty.ico"), tr("Music Videos"));
	}

	ui->m_lpMainTab->setCurrentIndex(0);

	setWindowTitle(tr("qtKodiAdmin"));
}

void cMainWindow::initDB(QSplashScreen* lpSplashScreen)
{
	QSettings	settings;
	QString		szKodiRoot	= settings.value("kodiRoot", "").toString();
	if(szKodiRoot.isEmpty())
		return;

	m_lpKodiLibrary	= new cKodiLibrary(lpSplashScreen, szKodiRoot);
	m_lpKodiLibrary->init();

	lpSplashScreen->showMessage("filling video list ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
	QApplication::processEvents();
	m_lpVideoWidget->setLibrary(m_lpKodiLibrary->videoLibrary(), m_lpKodiLibrary->imageList());

	lpSplashScreen->showMessage("filling tv show list ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);
	QApplication::processEvents();
	m_lpTVShowWidget->setLibrary(m_lpKodiLibrary->videoLibrary(), m_lpKodiLibrary->imageList());
}
