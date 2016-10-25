#ifndef CIMAGE_H
#define CIMAGE_H


#include <QString>
#include <QList>
#include <QMetaType>
#include <QPixmap>

#include "ckodivideolibrary.h"
#include "ckoditextureslibrary.h"


class cImage
{
public:
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

	enum TYPE
	{
		TYPE_unknown			= 0,
		TYPE_thumb				= 1,
		TYPE_fanart				= 2,
		TYPE_poster				= 3,
		TYPE_banner				= 4,
	};

	cImage(cKodiVideoLibrary* lpKodiVideoLibrary, cKodiTexturesLibrary* lpKodiTexturesLibrary, cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie, const QString& szPath);

	cImage::MEDIATYPE		mediaType();
	cImage::TYPE			type();
	qint32					idMovie();

	QPixmap					image();
private:
	cKodiVideoLibrary*		m_lpKodiVideoLibrary;
	cKodiTexturesLibrary*	m_lpKodiTexturesLibrary;

	qint32					m_artID;
	cImage::MEDIATYPE		m_mediaType;
	cImage::TYPE			m_type;
	qint32					m_idMovie;
	QString					m_szURL;
	QString					m_szCachedURL;
	QString					m_szFileName;
	qint32					m_textureID;
	QString					m_szPath;

	QPixmap					m_image;

	QPixmap					downloadFile(const QString& szFileName);
};

Q_DECLARE_METATYPE (cImage*)

class cImageList : public QList<cImage*>
{
public:
	cImageList(cKodiVideoLibrary* lpKodiVideoLibrary, cKodiTexturesLibrary* lpKodiTexturesLibrary, const QString& szPath);
	QPixmap					get(cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie);

private:
	cKodiVideoLibrary*		m_lpKodiVideoLibrary;
	cKodiTexturesLibrary*	m_lpKodiTexturesLibrary;
	QString					m_szPath;
};

#endif // CIMAGE_H
