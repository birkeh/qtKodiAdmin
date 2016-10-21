#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include <QDir>
#include <QIcon>


cMainWindow::cMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow),
	m_lpMovieWidget(0),
	m_lpTVShowWidget(0),
	m_lpMusicWidget(0),
	m_lpMusicVideoWidget(0),
	m_lpKodiLibrary(0)
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

	if(m_lpKodiLibrary)
	{
		m_lpKodiLibrary->stop();
		while(!m_lpKodiLibrary->isFinished())
			QThread::msleep(100);
		delete m_lpKodiLibrary;
	}

	delete ui;
}

void cMainWindow::initUI()
{
	ui->setupUi(this);

	m_lpMovieWidget			= new cMovieWidget(this);
	m_lpTVShowWidget		= new cTVShowWidget(this);
	m_lpMusicWidget			= new cMusicWidget(this);
	m_lpMusicVideoWidget	= new cMusicVideosWidget(this);

//	ui->m_lpMainTab->addTab(m_lpMovieWidget, QIcon(":/icons/Videos.ico"), "Movies");
//	ui->m_lpMainTab->addTab(m_lpTVShowWidget, QIcon(":/icons/TV Shows.ico"), "TV Shows");
//	ui->m_lpMainTab->addTab(m_lpMusicWidget, QIcon(":/icons/Musics.ico"), "Music");
//	ui->m_lpMainTab->addTab(m_lpMusicVideoWidget, QIcon(":/icons/Videos.ico"), "Music Videos");
	ui->m_lpMainTab->addTab(m_lpMovieWidget, QIcon(":/icons/empty.ico"), "Movies");
	ui->m_lpMainTab->addTab(m_lpTVShowWidget, QIcon(":/icons/empty.ico"), "TV Shows");
	ui->m_lpMainTab->addTab(m_lpMusicWidget, QIcon(":/icons/empty.ico"), "Music");
	ui->m_lpMainTab->addTab(m_lpMusicVideoWidget, QIcon(":/icons/empty.ico"), "Music Videos");

	ui->m_lpMainTab->setCurrentIndex(0);

	setWindowTitle("qtKodiAdmin");
}

QString cMainWindow::findFile(const QString& szPath, const QString& szFile)
{
	QDir		fileList(szPath + QDir::separator() + QString("Userdata") + QDir::separator() + QString("Database"), szFile + QString("*.*"));
	QString		fileName("");
	QStringList	files		= fileList.entryList(QDir::Files);
	qint16		iVersion	= -1;

	for(int x = 0;x < files.count();x++)
	{
		QString	tmp	= files.at(x);
		tmp			= tmp.left(tmp.lastIndexOf("."));
		tmp			= tmp.mid(szFile.length());
		if(iVersion < tmp.toInt())
		{
			fileName	= files.at(x);
			iVersion	= tmp.toInt();
		}
	}
	if(fileName.length())
		return(fileList.cleanPath(fileList.absoluteFilePath(fileName)));
	return(fileName);
}

void cMainWindow::initDB()
{
	ui->m_lpStatusBar->showMessage("Initializing ...");

	m_szPath		= QDir::homePath() + QDir::separator() + QString(".kodi");

	m_szAddons		= findFile(m_szPath, "Addons");
	m_szADSP		= findFile(m_szPath, "ADSP");
	m_szEpg			= findFile(m_szPath, "Epg");
	m_szMyMusic		= findFile(m_szPath, "MyMusic");
	m_szMyVideos	= findFile(m_szPath, "MyVideos");
	m_szTextures	= findFile(m_szPath, "Textures");
	m_szTV			= findFile(m_szPath, "TV");
	m_szViewModes	= findFile(m_szPath, "ViewModes");

	m_dbVideos		= QSqlDatabase::addDatabase("QSQLITE", "VideoLibrary");
	m_dbVideos.setDatabaseName(m_szMyVideos);
	if(!m_dbVideos.open())
		return;

	m_lpKodiLibrary	= new cKodiLibrary(ui->m_lpStatusBar, m_dbVideos);
	connect(m_lpKodiLibrary, SIGNAL(initDone(qint32)), this, SLOT(onInitDone(qint32)));
	m_lpKodiLibrary->start();
	m_lpKodiLibrary->init();
}

void cMainWindow::onInitDone(qint32 iMovieCount)
{
	iMovieCount = 0;
}
