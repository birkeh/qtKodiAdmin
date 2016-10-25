#ifndef CKODITEXTURESLIBRARY_H
#define CKODITEXTURESLIBRARY_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStatusBar>


class cKodiTexturesLibrary
{
public:
	cKodiTexturesLibrary(const QString& szFileName);
	~cKodiTexturesLibrary();

	qint16			init();
	qint16			version();

	bool			texture(const QString& szURL, qint32& id, QString& szCachedURL);
private:
	QSqlDatabase	m_db;
	QString			m_szFileName;
	bool			m_bConnected;
	qint16			m_iVersion;
};

#endif // CKODITEXTURESLIBRARY_H
