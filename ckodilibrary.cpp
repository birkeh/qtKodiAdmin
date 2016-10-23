#include "ckodilibrary.h"


#include <QTime>
#include <QDir>
#include <QString>
#include <QStringList>


cKodiLibrary::cKodiLibrary(QStatusBar* lpMainWindowStatusBar, const QString& szPath) :
	m_lpMainWindowStatusBar(lpMainWindowStatusBar),
	m_szPath(szPath)
{
}

cKodiLibrary::~cKodiLibrary()
{
}

QString cKodiLibrary::findFile(const QString& szPath, const QString& szFile)
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

bool cKodiLibrary::init()
{
	qint32	iVideoCount;

	m_lpMainWindowStatusBar->showMessage("Initializing ...");

	m_szAddons		= findFile(m_szPath, "Addons");
	m_szADSP		= findFile(m_szPath, "ADSP");
	m_szEpg			= findFile(m_szPath, "Epg");
	m_szMyMusic		= findFile(m_szPath, "MyMusic");
	m_szMyVideos	= findFile(m_szPath, "MyVideos");
	m_szTextures	= findFile(m_szPath, "Textures");
	m_szTV			= findFile(m_szPath, "TV");
	m_szViewModes	= findFile(m_szPath, "ViewModes");

	m_lpMainWindowStatusBar->showMessage("Initializing Videos ...");

	m_lpKodiVideoLibrary	= new cKodiVideoLibrary(m_szMyVideos);
	if(m_lpKodiVideoLibrary->init() != -1)
		iVideoCount	= m_lpKodiVideoLibrary->load();

	m_lpMainWindowStatusBar->showMessage("Done.", 3000);

	return(iVideoCount != 0);
}

cKodiVideoLibrary* cKodiLibrary::videoLibrary()
{
	return(m_lpKodiVideoLibrary);
}

void cKodiLibrary::fillVideoList(QStandardItemModel* lpModel)
{
	if(m_lpKodiVideoLibrary)
		m_lpKodiVideoLibrary->fillVideoList(lpModel);
}
