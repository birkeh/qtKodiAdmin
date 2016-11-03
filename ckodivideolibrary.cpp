#include "ckodivideolibrary.h"
#include "cimage.h"

#include <QFile>
#include <QVariant>
#include <QStringList>

#include <QSqlQuery>

#include <QDebug>
#include <QTime>


cKodiVideoLibrary::cKodiVideoLibrary(const QString& szFileName) :
	m_szFileName(szFileName),
	m_bConnected(false),
	m_iVersion(-1)
{
}

cKodiVideoLibrary::~cKodiVideoLibrary()
{
	if(m_bConnected && m_db.isOpen())
		m_db.close();
}

qint16 cKodiVideoLibrary::init()
{
	if(m_bConnected)
		return(m_iVersion);

	m_db	= QSqlDatabase::addDatabase("QSQLITE", "VideoLibrary");
	m_db.setDatabaseName(m_szFileName);
	if(!m_db.open())
		return(-1);

	QSqlQuery	query(m_db);
	if(!query.exec("SELECT idVersion FROM version;"))
	{
		m_db.close();
		return(-1);
	}

	if(!query.first())
	{
		m_db.close();
		return(-1);
	}

	m_iVersion		= query.value("idVersion").toInt();
	m_bConnected	= true;

	return(m_iVersion);
}

qint16 cKodiVideoLibrary::version()
{
	if(!m_bConnected)
		return(-1);
	return(m_iVersion);
}

qint32 cKodiVideoLibrary::load()
{
	loadActors();
	loadCountries();
	loadGenres();
	loadStudios();
	loadSets();

	return(loadVideos());
}

qint32 cKodiVideoLibrary::loadActors()
{
	QSqlQuery	query(m_db);

	query.exec("SELECT actor_id, name, art_urls FROM actor ORDER BY name;");
	while(query.next())
	{
		m_videosActorList.add(
			query.value("actor_id").toInt(),
			query.value("name").toString(),
			query.value("art_urls").toString());

	}
	return(m_videosActorList.count());
}

qint32 cKodiVideoLibrary::loadCountries()
{
	QSqlQuery	query(m_db);

	query.exec("SELECT country_id, name FROM country ORDER BY name;");
	while(query.next())
	{
		m_videosCountryList.add(
			query.value("country_id").toInt(),
			query.value("name").toString());

	}
	return(m_videosCountryList.count());
}

qint32 cKodiVideoLibrary::loadGenres()
{
	QSqlQuery	query(m_db);

	query.exec("SELECT genre_id, name FROM genre ORDER BY name;");
	while(query.next())
	{
		m_videosGenreList.add(
			query.value("genre_id").toInt(),
			query.value("name").toString());

	}
	return(m_videosGenreList.count());
}

qint32 cKodiVideoLibrary::loadStudios()
{
	QSqlQuery	query(m_db);

	query.exec("SELECT studio_id, name FROM studio ORDER BY name;");
	while(query.next())
	{
		m_videosStudioList.add(
			query.value("studio_id").toInt(),
			query.value("name").toString());

	}
	return(m_videosStudioList.count());
}

qint32 cKodiVideoLibrary::loadSets()
{
	QSqlQuery	query(m_db);

	query.exec("SELECT idSet, strSet, strOverview FROM sets ORDER BY strSet;");
	while(query.next())
	{
		m_videosSetList.add(query.value("idSet").toInt(),
							query.value("strSet").toString(),
							query.value("strOverview").toString());
	}
	return(m_videosSetList.count());
}

qint32 cKodiVideoLibrary::loadVideos()
{
	QSqlQuery	query(m_db);

	//query.exec("SELECT idMovie, idFile, c00, c01, c02, c03, c04, c05, c06, c07, c08, c09, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, idSet, userrating, strSet, strSetOverview, strFileName, strPath, playCount, lastPlayed, dateAdded, resumeTimeInSeconds, totalTimeInSeconds FROM movie_view ORDER BY c00;");
	query.exec("SELECT		idMovie,"
				"			idFile,"
				"			c00,"
				"			c01,"
				"			c02,"
				"			c03,"
				"			c04,"
				"			c05,"
				"			c06,"
				"			c07,"
				"			c08,"
				"			c09,"
				"			c10,"
				"			c11,"
				"			c12,"
				"			c13,"
				"			c14,"
				"			c15,"
				"			c16,"
				"			c17,"
				"			c18,"
				"			c19,"
				"			c20,"
				"			c21,"
				"			c22,"
				"			c23,"
				"			idSet,"
				"			userrating,"
				"			strSet,"
				"			strSetOverview,"
				"			strFileName,"
				"			strPath,"
				"			playCount,"
				"			lastPlayed,"
				"			dateAdded,"
				"			resumeTimeInSeconds,"
				"			totalTimeInSeconds,"
				"			sortText"
				"			FROM"
				"			("
				"			SELECT	*,"
				"			ifnull(strSet, c00) as sortText"
				"			FROM	movie_view"
				"			)"
				"			ORDER BY	sortText,"
				"			c07;");
	while(query.next())
	{
		m_videosList.add(
			query.value("idMovie").toInt(),
			query.value("idFile").toInt(),
			query.value("c00").toString(),
			query.value("c01").toString(),
			query.value("c02").toString(),
			query.value("c03").toString(),
			query.value("c04").toInt(),
			query.value("c05").toDouble(),
			query.value("c06").toString(),
			query.value("c07").toInt(),
			query.value("c08").toString(),
			query.value("c09").toString(),
			query.value("c10").toString(),
			query.value("c11").toInt(),
			query.value("c12").toString(),
			query.value("c13").toInt(),
			query.value("c14").toString(),
			query.value("c15").toString(),
			query.value("c16").toString(),
			query.value("c18").toString(),
			query.value("c19").toString(),
			query.value("c20").toString(),
			query.value("c21").toString(),
			query.value("c22").toString(),
			query.value("c23").toInt(),
			query.value("userrating").toInt(),
			query.value("strFileName").toString(),
			query.value("strPath").toString(),
			query.value("playCount").toInt(),
			QDateTime::fromString(query.value("lastPlayed").toString(), "yyyy-MM-dd HH:mm:ss"),
			QDateTime::fromString(query.value("dateAdded").toString(), "yyyy-MM-dd HH:mm:ss"),
			query.value("resumeTimeInSeconds").toDouble(),
			query.value("totalTimeInSeconds").toDouble(),
			m_videosSetList.get(query.value("idSet").toInt()));
	}
	return(m_videosList.count());
}

bool cKodiVideoLibrary::art(const QString& szMediaType, const QString& szType, qint32 idMovie, qint32& artID, QString& szURL)
{
	QSqlQuery	query(m_db);
	query.exec(QString("SELECT art_id, media_id, media_type, type, url FROM art WHERE media_type='%1' AND type='%2' AND media_id=%3;").arg(szMediaType).arg(szType).arg(idMovie));
	if(query.next())
	{
		artID	= query.value("art_id").toInt();
		szURL	= query.value("url").toString();
		return(true);
	}
	return(false);
}

void cKodiVideoLibrary::fillVideoList(QStandardItemModel* lpModel)
{
	lpModel->clear();

	QStandardItem*	lpRoot	= 0;
	QString			szOldSet("");

	for(int z = 0;z < m_videosList.count();z++)
	{
		cMyVideos*	lpVideos	= m_videosList.at(z);

		if(lpVideos->set())
		{
			if(szOldSet != lpVideos->set()->strSet())
			{
				szOldSet		= lpVideos->set()->strSet();
				lpRoot			= new QStandardItem(QString("<b><i>%1</i></b>").arg(lpVideos->set()->strSet()));
				QVariant	v	= qVariantFromValue(lpVideos->set());
				lpRoot->setData(v, Qt::UserRole);
				lpModel->appendRow(lpRoot);
			}
		}
		else
			lpRoot	= 0;

		QStandardItem*	lpItem	= new QStandardItem(QString("<b>%1</b><br><font color='blue'>%2</font>&nbsp;&nbsp;<i>%3</i>").arg(lpVideos->localMovieTitle()).arg(lpVideos->yearReleased()).arg(lpVideos->movieTagline()));
		QVariant	v	= qVariantFromValue(lpVideos);
		lpItem->setData(v, Qt::UserRole);
		if(lpRoot)
			lpRoot->appendRow(lpItem);
		else
			lpModel->appendRow(lpItem);
	}
}

void cKodiVideoLibrary::fillCountriesList(QStandardItemModel *lpModel)
{
	lpModel->clear();

	for(int z = 0;z < m_videosCountryList.count();z++)
	{
		cMyVideosCountry*	lpCountry	= m_videosCountryList.at(z);

		QStandardItem*	lpItem	= new QStandardItem(lpCountry->name());
		QVariant	v	= qVariantFromValue(lpCountry);
		lpItem->setData(v, Qt::UserRole);
		lpItem->setCheckable(true);
		lpModel->appendRow(lpItem);
	}
}

void cKodiVideoLibrary::fillGenresList(QStandardItemModel *lpModel)
{
	lpModel->clear();

	for(int z = 0;z < m_videosGenreList.count();z++)
	{
		cMyVideosGenre*	lpGenre	= m_videosGenreList.at(z);

		QStandardItem*	lpItem	= new QStandardItem(lpGenre->name());
		QVariant	v	= qVariantFromValue(lpGenre);
		lpItem->setData(v, Qt::UserRole);
		lpItem->setCheckable(true);
		lpModel->appendRow(lpItem);
	}
}

void cKodiVideoLibrary::fillStudiosList(QStandardItemModel *lpModel)
{
	lpModel->clear();

	for(int z = 0;z < m_videosStudioList.count();z++)
	{
		cMyVideosStudio*	lpStudio	= m_videosStudioList.at(z);

		QStandardItem*	lpItem	= new QStandardItem(lpStudio->name());
		QVariant	v	= qVariantFromValue(lpStudio);
		lpItem->setData(v, Qt::UserRole);
		lpItem->setCheckable(true);
		lpModel->appendRow(lpItem);
	}
}

void cKodiVideoLibrary::fillSetsList(QComboBox* lpComboBox)
{
	lpComboBox->addItem("");
	for(int z = 0;z < m_videosSetList.count();z++)
	{
		QVariant	v	= QVariant::fromValue(m_videosSetList.at(z));
		lpComboBox->addItem(m_videosSetList.at(z)->strSet(), v);
	}
}

void cKodiVideoLibrary::fillActorList(QStandardItemModel *lpList, cMyVideos* lpVideos)
{
	lpList->clear();

	lpVideos->loadActors(m_db, m_videosActorList);
	lpVideos->fillActorsList(lpList);
}

void cKodiVideoLibrary::fillDirectorsList(QStandardItemModel *lpList, cMyVideos* lpVideos)
{
	lpList->clear();

	lpVideos->loadDirectors(m_db, m_videosActorList);
	lpVideos->fillDirectorsList(lpList);
}

void cKodiVideoLibrary::fillWritersList(QStandardItemModel *lpList, cMyVideos* lpVideos)
{
	lpList->clear();

	lpVideos->loadWriters(m_db, m_videosActorList);
	lpVideos->fillWritersList(lpList);
}

void cKodiVideoLibrary::fillCountriesList(QStandardItemModel *lpList, cMyVideos* lpVideos)
{
	lpVideos->loadCountries(m_db, m_videosCountryList);

	for(int x = 0;x < lpList->rowCount();x++)
		lpList->item(x, 0)->setCheckState(Qt::Unchecked);

	for(int z = 0;z < lpVideos->m_values.m_countries.count();z++)
	{
		for(int x = 0;x < lpList->rowCount();x++)
		{
			QStandardItem*		lpItem		= lpList->item(x, 0);
			cMyVideosCountry*	lpCountry	= lpItem->data(Qt::UserRole).value<cMyVideosCountry*>();

			if(lpVideos->m_values.m_countries.at(z)->country()->countryID() == lpCountry->countryID())
			{
				lpItem->setCheckState(Qt::Checked);
				break;
			}
		}
	}
}

void cKodiVideoLibrary::fillGenresList(QStandardItemModel *lpList, cMyVideos* lpVideos)
{
	lpVideos->loadGenres(m_db, m_videosGenreList);

	for(int x = 0;x < lpList->rowCount();x++)
		lpList->item(x, 0)->setCheckState(Qt::Unchecked);

	for(int z = 0;z < lpVideos->m_values.m_genres.count();z++)
	{
		for(int x = 0;x < lpList->rowCount();x++)
		{
			QStandardItem*		lpItem		= lpList->item(x, 0);
			cMyVideosGenre*		lpGenre		= lpItem->data(Qt::UserRole).value<cMyVideosGenre*>();

			if(lpVideos->m_values.m_genres.at(z)->genre()->genreID() == lpGenre->genreID())
			{
				lpItem->setCheckState(Qt::Checked);
				break;
			}
		}
	}
}

void cKodiVideoLibrary::fillStudiosList(QStandardItemModel *lpList, cMyVideos* lpVideos)
{
	lpVideos->loadStudios(m_db, m_videosStudioList);

	for(int x = 0;x < lpList->rowCount();x++)
		lpList->item(x, 0)->setCheckState(Qt::Unchecked);

	for(int z = 0;z < lpVideos->m_values.m_studios.count();z++)
	{
		for(int x = 0;x < lpList->rowCount();x++)
		{
			QStandardItem*		lpItem		= lpList->item(x, 0);
			cMyVideosStudio*	lpStudio	= lpItem->data(Qt::UserRole).value<cMyVideosStudio*>();

			if(lpVideos->m_values.m_studios.at(z)->studio()->studioID() == lpStudio->studioID())
			{
				lpItem->setCheckState(Qt::Checked);
				break;
			}
		}
	}
}

void cKodiVideoLibrary::fillVideoStreamList(QStandardItemModel* lpModel, cMyVideos* lpVideos)
{
	lpModel->clear();
	QStringList	headerLabels	= QStringList() << QObject::tr("Codec") << QObject::tr("Ratio") << QObject::tr("Width") << QObject::tr("Height");
	lpModel->setHorizontalHeaderLabels(headerLabels);

	lpVideos->loadVideoStream(m_db);
	lpVideos->fillVideoStreamList(lpModel);
}

void cKodiVideoLibrary::fillAudioStreamList(QStandardItemModel* lpModel, cMyVideos* lpVideos)
{
	lpModel->clear();
	QStringList	headerLabels	= QStringList() << QObject::tr("Codec") << QObject::tr("Channels") << QObject::tr("Language") << QObject::tr("Mode");
	lpModel->setHorizontalHeaderLabels(headerLabels);

	lpVideos->loadAudioStream(m_db);
	lpVideos->fillAudioStreamList(lpModel);
}

void cKodiVideoLibrary::fillSubtitleStreamList(QStandardItemModel* lpModel, cMyVideos* lpVideos)
{
	lpModel->clear();
	QStringList	headerLabels	= QStringList() << QObject::tr("Language");
	lpModel->setHorizontalHeaderLabels(headerLabels);

	lpVideos->loadSubtitleStream(m_db);
	lpVideos->fillSubtitleStreamList(lpModel);
}
