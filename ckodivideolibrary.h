#ifndef CKODIVIDEOLIBRARY_H
#define CKODIVIDEOLIBRARY_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStatusBar>


class cKodiVideoLibrary
{
public:
	cKodiVideoLibrary(QSqlDatabase& db);
	~cKodiVideoLibrary();

	qint16			init();
	qint16			version();

	qint32			load();
private:
	QSqlDatabase	m_db;
	bool			m_bConnected;
	qint16			m_iVersion;
};

#endif // CKODIVIDEOLIBRARY_H
