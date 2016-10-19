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
	m_szPath		= szPath;
	m_szAddons		= findFile(m_szPath, "Addons");
	m_szADSP		= findFile(m_szPath, "ADSP");
	m_szEpg			= findFile(m_szPath, "Epg");
	m_szMyMusic		= findFile(m_szPath, "MyMusic");
	m_szMyVideos	= findFile(m_szPath, "MyVideos");
	m_szTextures	= findFile(m_szPath, "Textures");
	m_szTV			= findFile(m_szPath, "TV");
	m_szViewModes	= findFile(m_szPath, "ViewModes");

	if(m_kodiVideoLibrary.init(m_szMyVideos) != -1)
		return(true);

	return(false);
}
