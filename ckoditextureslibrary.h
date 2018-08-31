#ifndef CKODITEXTURESLIBRARY_H
#define CKODITEXTURESLIBRARY_H


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStatusBar>


/*!
 \brief

 \class cKodiTexturesLibrary ckoditextureslibrary.h "ckoditextureslibrary.h"
*/
class cKodiTexturesLibrary
{
public:
	cKodiTexturesLibrary(const QString& szFileName);
	/*!
	 \brief

	 \fn ~cKodiTexturesLibrary
	*/
	~cKodiTexturesLibrary();

	/*!
	 \brief

	 \fn init
	 \return qint16
	*/
	qint16			init();
	/*!
	 \brief

	 \fn version
	 \return qint16
	*/
	qint16			version();

	/*!
	 \brief

	 \fn texture
	 \param szURL
	 \param id
	 \param szCachedURL
	 \return bool
	*/
	bool			texture(const QString& szURL, qint32& id, QString& szCachedURL);
private:
	QSqlDatabase	m_db; /*!< TODO: describe */
	QString			m_szFileName; /*!< TODO: describe */
	bool			m_bConnected; /*!< TODO: describe */
	qint16			m_iVersion; /*!< TODO: describe */
};

#endif // CKODITEXTURESLIBRARY_H
