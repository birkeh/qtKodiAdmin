#ifndef CIMAGE_H
#define CIMAGE_H


#include <QString>
#include <QList>
#include <QMetaType>
#include <QPixmap>

#include "ckodivideolibrary.h"
#include "ckoditextureslibrary.h"


/*!
 \brief

 \class cImage cimage.h "cimage.h"
*/

class cImage
{
public:
	/*!
	 \brief

	 \enum MEDIATYPE
	*/
	enum MEDIATYPE
	{
		MEDIATYPE_unknown		= 0,
		MEDIATYPE_actor			= 1,
		MEDIATYPE_movie			= 2,
		MEDIATYPE_set			= 3,
		MEDIATYPE_tvshow		= 4,
		MEDIATYPE_season		= 5,
		MEDIATYPE_episode		= 6,
		MEDIATYPE_musicvideo	= 7,
	};

	/*!
	 \brief

	 \enum TYPE
	*/
	enum TYPE
	{
		TYPE_unknown			= 0,
		TYPE_thumb				= 1,
		TYPE_fanart				= 2,
		TYPE_poster				= 3,
		TYPE_banner				= 4,
	};

	cImage(cKodiVideoLibrary* lpKodiVideoLibrary, cKodiTexturesLibrary* lpKodiTexturesLibrary, cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie, const QString& szPath);

	/*!
	 \brief

	 \fn mediaType
	 \return cImage::MEDIATYPE
	*/
	cImage::MEDIATYPE		mediaType();
	/*!
	 \brief

	 \fn type
	 \return cImage::TYPE
	*/
	cImage::TYPE			type();
	/*!
	 \brief

	 \fn idMovie
	 \return qint32
	*/
	qint32					idMovie();
	/*!
	 \brief

	 \fn fileName
	 \return QString
	*/
	QString					fileName();

	/*!
	 \brief

	 \fn image
	 \return QPixmap
	*/
	QPixmap					image();
private:
	cKodiVideoLibrary*		m_lpKodiVideoLibrary; /*!< TODO: describe */
	cKodiTexturesLibrary*	m_lpKodiTexturesLibrary; /*!< TODO: describe */

	qint32					m_artID; /*!< TODO: describe */
	cImage::MEDIATYPE		m_mediaType; /*!< TODO: describe */
	cImage::TYPE			m_type; /*!< TODO: describe */
	qint32					m_idMovie; /*!< TODO: describe */
	QString					m_szURL; /*!< TODO: describe */
	QString					m_szCachedURL; /*!< TODO: describe */
	QString					m_szFileName; /*!< TODO: describe */
	qint32					m_textureID; /*!< TODO: describe */
	QString					m_szPath; /*!< TODO: describe */

	QPixmap					m_image; /*!< TODO: describe */
};

Q_DECLARE_METATYPE (cImage*)

/*!
 \brief

 \class cImageList cimage.h "cimage.h"
*/
class cImageList : public QList<cImage*>
{
public:
	cImageList(cKodiVideoLibrary* lpKodiVideoLibrary, cKodiTexturesLibrary* lpKodiTexturesLibrary, const QString& szPath);
	/*!
	 \brief

	 \fn get
	 \param mediaType
	 \param type
	 \param idMovie
	 \return QPixmap
	*/
	QPixmap					get(cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie);
	/*!
	 \brief

	 \fn fileName
	 \param mediaType
	 \param type
	 \param idMovie
	 \return QString
	*/
	QString					fileName(cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie);
private:
	cKodiVideoLibrary*		m_lpKodiVideoLibrary; /*!< TODO: describe */
	cKodiTexturesLibrary*	m_lpKodiTexturesLibrary; /*!< TODO: describe */
	QString					m_szPath; /*!< TODO: describe */

	/*!
	 \brief

	 \fn find
	 \param mediaType
	 \param type
	 \param idMovie
	 \return cImage
	*/
	cImage*					find(cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie);
};

#endif // CIMAGE_H
