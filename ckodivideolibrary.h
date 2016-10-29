#ifndef CKODIVIDEOLIBRARY_H
#define CKODIVIDEOLIBRARY_H


#include "cmyvideos.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStatusBar>

#include <QStandardItemModel>
#include <QTreeView>


class cKodiVideoLibrary
{
public:
	cKodiVideoLibrary(const QString& szFileName);
	~cKodiVideoLibrary();

	qint16					init();
	qint16					version();

	qint32					load();
	bool					art(const QString& szMediaType, const QString& szType, qint32 idMovie, qint32& artID, QString& szURL);

	void					fillVideoList(QStandardItemModel* lpModel);
	void					fillActorList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	void					fillDirectorsList(QStandardItemModel* lpList, cMyVideos* lpVideos);
	void					fillWritersList(QStandardItemModel* lpList, cMyVideos* lpVideos);
private:
	QSqlDatabase			m_db;
	QString					m_szFileName;
	bool					m_bConnected;
	qint16					m_iVersion;

	cMyVideosActorList		m_videosActorList;
	cMyVideosCountryList	m_videosCountryList;
	cMyVideosGenreList		m_videosGenreList;
	cMyVideosStudioList		m_videosStudioList;
	cMyVideosList			m_videosList;

	qint32					loadActors();
	qint32					loadCountries();
	qint32					loadGenres();
	qint32					loadStudios();
	qint32					loadVideos();
};

#endif // CKODIVIDEOLIBRARY_H
