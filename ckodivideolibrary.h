#ifndef CKODIVIDEOLIBRARY_H
#define CKODIVIDEOLIBRARY_H

#include <QSqlDatabase>
#include <QSqlQuery>


class cKodiVideoLibrary
{
public:
	cKodiVideoLibrary();
	~cKodiVideoLibrary();

	qint16			init(const QString& szFileName);
	qint16			version();
private:
	QSqlDatabase	m_db;
	bool			m_bConnected;
	QString			m_szFileName;
	qint16			m_iVersion;
};

#endif // CKODIVIDEOLIBRARY_H
