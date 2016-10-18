#include "ckodilibrary.h"


#include <QDir>
#include <QString>
#include <QStringList>


cKodiLibrary::cKodiLibrary() :
	m_szPath(""),
	m_szAddons(""),
	m_szADSP(""),
	m_szEpg(""),
	m_szMyMusic(""),
	m_szMyVideos(""),
	m_szTextures(""),
	m_szTV(""),
	m_szViewModes("")
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

bool cKodiLibrary::init(const QString& szPath)
{
	m_szAddons		= findFile(szPath, "Addons");
	m_szADSP		= findFile(szPath, "ADSP");
	m_szEpg			= findFile(szPath, "Epg");
	m_szMyMusic		= findFile(szPath, "MyMusic");
	m_szMyVideos	= findFile(szPath, "MyVideos");
	m_szTextures	= findFile(szPath, "Textures");
	m_szTV			= findFile(szPath, "TV");
	m_szViewModes	= findFile(szPath, "ViewModes");

	m_kodiVideoLibrary.init(m_szMyVideos);
	return(true);
}
