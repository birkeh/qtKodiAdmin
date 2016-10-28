#include "cimage.h"

#include <QDir>


QString strMEDIATYPE[] =
{
	"unknown",
	"actor",
	"movie",
	"set",
	"tvshow",
	"season",
	"episode",
	"musicvideo"
};

QString strTYPE[] =
{
	"unknown",
	"thumb",
	"fanart",
	"poster",
	"banner"
};


cImage::cImage(cKodiVideoLibrary* lpKodiVideoLibrary, cKodiTexturesLibrary* lpKodiTexturesLibrary, cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie, const QString &szPath) :
	m_lpKodiVideoLibrary(lpKodiVideoLibrary),
	m_lpKodiTexturesLibrary(lpKodiTexturesLibrary),
	m_artID(-1),
	m_mediaType(mediaType),
	m_type(type),
	m_idMovie(idMovie),
	m_szURL(""),
	m_szCachedURL(""),
	m_szFileName(""),
	m_textureID(-1),
	m_szPath(szPath)
{
	if(m_lpKodiVideoLibrary->art(strMEDIATYPE[mediaType], strTYPE[type], idMovie, m_artID, m_szURL))
	{
		if(m_lpKodiTexturesLibrary->texture(m_szURL, m_textureID, m_szCachedURL))
		{
			QString	str	= m_szPath + QDir::separator() + "Userdata" + QDir::separator() + "Thumbnails" + QDir::separator() + m_szCachedURL;

			if(m_szCachedURL.length())
				m_image.load(str);

			return;
		}

//		downloadFile(m_szURL);
	}
}

cImage::MEDIATYPE cImage::mediaType()
{
	return(m_mediaType);
}

cImage::TYPE cImage::type()
{
	return(m_type);
}

qint32 cImage::idMovie()
{
	return(m_idMovie);
}

QPixmap cImage::image()
{
	return(m_image);
}

cImageList::cImageList(cKodiVideoLibrary *lpKodiVideoLibrary, cKodiTexturesLibrary* lpKodiTexturesLibrary, const QString& szPath) :
	m_lpKodiVideoLibrary(lpKodiVideoLibrary),
	m_lpKodiTexturesLibrary(lpKodiTexturesLibrary),
	m_szPath(szPath)
{
}

QPixmap	cImageList::get(cImage::MEDIATYPE mediaType, cImage::TYPE type, qint32 idMovie)
{
	cImage*	lpImage	= 0;
	for(int z = 0;z < count();z++)
	{
		if(mediaType == at(z)->mediaType() && type == at(z)->type() && idMovie == at(z)->idMovie())
		{
			lpImage	= at(z);
			return(lpImage->image());
			break;
		}
	}

	if(!lpImage)
	{
		lpImage	= new cImage(m_lpKodiVideoLibrary, m_lpKodiTexturesLibrary, mediaType, type, idMovie, m_szPath);
		append(lpImage);
		return(lpImage->image());
	}
	return(QPixmap());
}

QPixmap cImage::downloadFile(const QString& /*szFileName*/)
{
	QPixmap					pixmap;

//	QString	szPath	= QDir::homePath() + QDir::separator() + "qtseries" + QDir::separator() + szFileName;
//	QString	szURL	= "http://thetvdb.com/banners/" + szFileName;

//	QNetworkAccessManager	networkManager;
//	QUrl					url(szURL);
//	QNetworkRequest			request(url);
//	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/xml");

//	QNetworkReply*			reply   = networkManager.get(request);
//	QEventLoop				loop;

//	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//	loop.exec();

//	QByteArray				szData  = reply->readAll();
//	delete reply;

//	pixmap.loadFromData(szData);

//	QDir		dir(szPath);
//	QFileInfo	fileInfo(szPath);
//	dir.mkpath(dir.filePath(fileInfo.absolutePath()));
//	pixmap.save(szPath);

	return(pixmap);
}
