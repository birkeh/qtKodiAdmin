#include "ckodivideolibrary.h"

#include <QFile>
#include <QVariant>


cKodiVideoLibrary::cKodiVideoLibrary() :
	m_bConnected(false),
	m_szFileName(""),
	m_iVersion(-1)
{
}

cKodiVideoLibrary::~cKodiVideoLibrary()
{
	if(m_bConnected && m_db.isOpen())
		m_db.close();
}

qint16 cKodiVideoLibrary::connect(const QString& szFileName)
{
	if(m_bConnected)
		return(true);

	if(!QFile(szFileName).exists())
		return(-1);

	m_db			= QSqlDatabase::addDatabase("QSQLITE", "VideoLibrary");
	m_szFileName	= szFileName;
	m_db.setDatabaseName(m_szFileName);
	if(!m_db.open())
	{
		m_szFileName = "";
		return(-1);
	}

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
