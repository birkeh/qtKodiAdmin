#include "ckodivideolibrary.h"

#include <QFile>
#include <QVariant>
#include <QStringList>

#include <QSqlQuery>

#include <QDebug>
#include <QTime>


cKodiVideoLibrary::cKodiVideoLibrary(const QString& szFileName) :
	m_szFileName(szFileName),
	m_bConnected(false),
	m_iVersion(-1)
{
}

cKodiVideoLibrary::~cKodiVideoLibrary()
{
	if(m_bConnected && m_db.isOpen())
		m_db.close();
}

qint16 cKodiVideoLibrary::init()
{
	if(m_bConnected)
		return(m_iVersion);

	m_db	= QSqlDatabase::addDatabase("QSQLITE", "VideoLibrary");
	m_db.setDatabaseName(m_szFileName);
	if(!m_db.open())
		return(-1);

	QSqlQuery	query(m_db);
	if(!query.exec("SELECT idVersion FROM version;"))
	{
		m_db.close();
		return(-1);
	}

	if(!query.first())
	{
		m_db.close();
		return(-1);
	}

	m_iVersion		= query.value("idVersion").toInt();
	m_bConnected	= true;

	return(m_iVersion);
}

qint16 cKodiVideoLibrary::version()
{
	if(!m_bConnected)
		return(-1);
	return(m_iVersion);
}

qint32 cKodiVideoLibrary::load()
{
	QSqlQuery	query(m_db);

	query.exec("SELECT idMovie, idFile, c00, c01, c02, c03, c04, c05, c06, c07, c08, c09, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, idSet, userrating, strSet, strSetOverview, strFileName, strPath, playCount, lastPlayed, dateAdded, resumeTimeInSeconds, totalTimeInSeconds FROM movie_view ORDER BY c00;");
	while(query.next())
	{
		cMyVideos*	lpNew	= m_videosList.add(
		query.value("idMovie").toInt(),
		query.value("idFile").toInt(),
		query.value("c00").toString(),
		query.value("c01").toString(),
		query.value("c02").toString(),
		query.value("c03").toString(),
		query.value("c04").toInt(),
		query.value("c05").toDouble(),
		query.value("c06").toString(),
		query.value("c07").toInt(),
		query.value("c08").toString(),
		query.value("c09").toString(),
		query.value("c10").toString(),
		query.value("c11").toInt(),
		query.value("c12").toString(),
		query.value("c13").toString(),
		query.value("c14").toString(),
		query.value("c15").toString(),
		query.value("c16").toString(),
		query.value("c18").toString(),
		query.value("c19").toString(),
		query.value("c20").toString(),
		query.value("c21").toString(),
		query.value("c22").toString(),
		query.value("c23").toInt(),
		query.value("idSet").toInt(),
		query.value("userrating").toInt(),
		query.value("strSet").toString(),
		query.value("strSetOverview").toString(),
		query.value("strFileName").toString(),
		query.value("strPath").toString(),
		query.value("playCount").toInt(),
		QDateTime::fromString(query.value("lastPlayed").toString(), "yyyy-MM-dd HH:mm:ss"),
		QDateTime::fromString(query.value("dateAdded").toString(), "yyyy-MM-dd HH:mm:ss"),
		query.value("resumeTimeInSeconds").toDouble(),
		query.value("totalTimeInSeconds").toDouble());

		lpNew = 0;
	}
	return(m_videosList.count());
}
