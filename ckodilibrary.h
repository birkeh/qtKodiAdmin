#ifndef CKODILIBRARY_H
#define CKODILIBRARY_H


#include "ckodivideolibrary.h"
#include "ckoditextureslibrary.h"

//#include "cimage.h"

#include <QStatusBar>
#include <QStandardItemModel>

#include <QSplashScreen>


class cImage;
class cImageList;

/*!
 \brief

 \class cKodiLibrary ckodilibrary.h "ckodilibrary.h"
*/
class cKodiLibrary
{
public:
	cKodiLibrary(QStatusBar* lpMainWindowStatusBar, const QString& szPath);
	/*!
	 \brief

	 \fn cKodiLibrary
	 \param lpSplashScreen
	 \param szPath
	*/
	cKodiLibrary(QSplashScreen* lpSplashScreen, const QString& szPath);
	/*!
	 \brief

	 \fn ~cKodiLibrary
	*/
	~cKodiLibrary();

	/*!
	 \brief

	 \fn init
	 \return bool
	*/
	bool					init();

	/*!
	 \brief

	 \fn videoLibrary
	 \return cKodiVideoLibrary
	*/
	cKodiVideoLibrary*		videoLibrary();
	/*!
	 \brief

	 \fn texturesLibrary
	 \return cKodiTexturesLibrary
	*/
	cKodiTexturesLibrary*	texturesLibrary();
	/*!
	 \brief

	 \fn imageList
	 \return cImageList
	*/
	cImageList*				imageList();
private:
	QStatusBar*				m_lpMainWindowStatusBar; /*!< TODO: describe */
	QSplashScreen*			m_lpSplashScreen; /*!< TODO: describe */
	cKodiVideoLibrary*		m_lpKodiVideoLibrary; /*!< TODO: describe */
	cKodiTexturesLibrary*	m_lpKodiTexturesLibrary; /*!< TODO: describe */
	cImageList*				m_lpImageList; /*!< TODO: describe */
	QString					m_szPath; /*!< TODO: describe */

	QString					m_szAddons; /*!< TODO: describe */
	QString					m_szADSP; /*!< TODO: describe */
	QString					m_szEpg; /*!< TODO: describe */
	QString					m_szMyMusic; /*!< TODO: describe */
	QString					m_szMyVideos; /*!< TODO: describe */
	QString					m_szTextures; /*!< TODO: describe */
	QString					m_szTV; /*!< TODO: describe */
	QString					m_szViewModes; /*!< TODO: describe */

	/*!
	 \brief

	 \fn findFile
	 \param szPath
	 \param szFile
	 \return QString
	*/
	QString					findFile(const QString& szPath, const QString& szFile);
};

#endif // CKODILIBRARY_H
