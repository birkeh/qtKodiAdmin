#ifndef CKODIVIDEOLIBRARY_H
#define CKODIVIDEOLIBRARY_H


#include "cmyvideos.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStatusBar>
#include <QSplashScreen>

#include <QStandardItemModel>
#include <QTreeView>
#include <QComboBox>


/*!
 \brief

 \class cKodiVideoLibrary ckodivideolibrary.h "ckodivideolibrary.h"
*/
class cKodiVideoLibrary
{
public:
	cKodiVideoLibrary(const QString& szFileName);
	/*!
	 \brief

	 \fn ~cKodiVideoLibrary
	*/
	~cKodiVideoLibrary();

	/*!
	 \brief

	 \fn init
	 \return qint16
	*/
	qint16					init();
	/*!
	 \brief

	 \fn version
	 \return qint16
	*/
	qint16					version();

	/*!
	 \brief

	 \fn load
	 \param lpStatusBar
	 \param lpSplashScreen
	 \return qint32
	*/
	qint32					load(QStatusBar* lpStatusBar, QSplashScreen* lpSplashScreen);
	/*!
	 \brief

	 \fn art
	 \param szMediaType
	 \param szType
	 \param idMovie
	 \param artID
	 \param szURL
	 \return bool
	*/
	bool					art(const QString& szMediaType, const QString& szType, qint32 idMovie, qint32& artID, QString& szURL);

	/*!
	 \brief

	 \fn fillVideoList
	 \param lpModel
	*/
	void					fillVideoList(QStandardItemModel* lpModel);
	/*!
	 \brief

	 \fn fillTVShowList
	 \param lpModel
	*/
	void					fillTVShowList(QStandardItemModel* lpModel);
	/*!
	 \brief

	 \fn fillCountriesList
	 \param lpModel
	*/
	void					fillCountriesList(QStandardItemModel* lpModel);
	/*!
	 \brief

	 \fn fillGenresList
	 \param lpModel
	*/
	void					fillGenresList(QStandardItemModel* lpModel);
	/*!
	 \brief

	 \fn fillStudiosList
	 \param lpModel
	*/
	void					fillStudiosList(QStandardItemModel* lpModel);
	/*!
	 \brief

	 \fn fillSetsList
	 \param lpComboBox
	*/
	void					fillSetsList(QComboBox* lpComboBox);
	/*!
	 \brief

	 \fn fillActorList
	 \param lpList
	 \param lpVideos
	*/
	void					fillActorList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillDirectorsList
	 \param lpList
	 \param lpVideos
	*/
	void					fillDirectorsList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillWritersList
	 \param lpList
	 \param lpVideos
	*/
	void					fillWritersList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillCountriesList
	 \param lpList
	 \param lpVideos
	*/
	void					fillCountriesList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillGenresList
	 \param lpList
	 \param lpVideos
	*/
	void					fillGenresList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillStudiosList
	 \param lpList
	 \param lpVideos
	*/
	void					fillStudiosList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillVideoStreamList
	 \param lpModel
	 \param lpVideos
	*/
	void					fillVideoStreamList(QStandardItemModel* lpModel, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillAudioStreamList
	 \param lpModel
	 \param lpVideos
	*/
	void					fillAudioStreamList(QStandardItemModel* lpModel, cMyVideos* lpVideos);
	/*!
	 \brief

	 \fn fillSubtitleStreamList
	 \param lpModel
	 \param lpVideos
	*/
	void					fillSubtitleStreamList(QStandardItemModel* lpModel, cMyVideos* lpVideos);
private:
	QSqlDatabase			m_db; /*!< TODO: describe */
	QString					m_szFileName; /*!< TODO: describe */
	bool					m_bConnected; /*!< TODO: describe */
	qint16					m_iVersion; /*!< TODO: describe */

	cMyVideosActorList		m_videosActorList; /*!< TODO: describe */
	cMyVideosCountryList	m_videosCountryList; /*!< TODO: describe */
	cMyVideosGenreList		m_videosGenreList; /*!< TODO: describe */
	cMyVideosStudioList		m_videosStudioList; /*!< TODO: describe */
	cMyVideosSetList		m_videosSetList; /*!< TODO: describe */
	cMyVideosList			m_videosList; /*!< TODO: describe */

	cMyTVShowsList			m_tvShowsList; /*!< TODO: describe */

	/*!
	 \brief

	 \fn loadActors
	 \return qint32
	*/
	qint32					loadActors();
	/*!
	 \brief

	 \fn loadCountries
	 \return qint32
	*/
	qint32					loadCountries();
	/*!
	 \brief

	 \fn loadGenres
	 \return qint32
	*/
	qint32					loadGenres();
	/*!
	 \brief

	 \fn loadStudios
	 \return qint32
	*/
	qint32					loadStudios();
	/*!
	 \brief

	 \fn loadVideos
	 \return qint32
	*/
	qint32					loadVideos();
	/*!
	 \brief

	 \fn loadTVShows
	 \return qint32
	*/
	qint32					loadTVShows();
	/*!
	 \brief

	 \fn loadSets
	 \return qint32
	*/
	qint32					loadSets();
};

#endif // CKODIVIDEOLIBRARY_H
