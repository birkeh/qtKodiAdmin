#include "ckodivideolibrary.h"

#include <QFile>
#include <QVariant>
#include <QStringList>

#include <QSqlQuery>


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
	QStringList	movies;

	QSqlQuery	query(m_db);

	query.exec("SELECT idMovie, idFile, c00 FROM movie_view ORDER BY c00;");
	while(query.next())
	{
		movies.append(query.value("c00").toString());
	}

	return(movies.count());
}
