#include "ckoditextureslibrary.h"

#include <QFile>
#include <QVariant>
#include <QStringList>

#include <QSqlQuery>

#include <QDebug>
#include <QTime>


cKodiTexturesLibrary::cKodiTexturesLibrary(const QString &szFileName) :
	m_szFileName(szFileName),
	m_bConnected(false),
	m_iVersion(-1)
{
}

cKodiTexturesLibrary::~cKodiTexturesLibrary()
{
	if(m_bConnected && m_db.isOpen())
		m_db.close();
}

qint16 cKodiTexturesLibrary::init()
{
	if(m_bConnected)
		return(m_iVersion);

	m_db	= QSqlDatabase::addDatabase("QSQLITE", "TexturesLibrary");
	m_db.setDatabaseName(m_szFileName);
	if(!m_db.open())
		return(-1);

	QSqlQuery	query(m_db);
	query.prepare("SELECT idVersion "
				  "FROM   version;");
	if(!query.exec())
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

qint16 cKodiTexturesLibrary::version()
{
	if(!m_bConnected)
		return(-1);
	return(m_iVersion);
}

bool cKodiTexturesLibrary::texture(const QString& szURL, qint32& id, QString& szCachedURL)
{
	QSqlQuery	query(m_db);
	query.prepare("SELECT id, "
				  "       url, "
				  "       cachedurl "
				  "FROM   texture "
				  "WHERE  url=:url;");
	query.bindValue(":url", szURL);
	query.exec();
	if(query.next())
	{
		id			= query.value("id").toInt();
		szCachedURL	= query.value("cachedurl").toString();
		return(true);
	}
	return(false);
}
