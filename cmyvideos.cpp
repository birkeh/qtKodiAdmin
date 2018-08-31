#include "cmyvideos.h"

#include <QSqlQuery>
#include <QStandardItem>


cMyVideosSetValues::cMyVideosSetValues() :
	m_idSet(-1),
	m_strSet("UNSET"),
	m_strOverview("UNSET")
{
}

cMyVideosSetValues::cMyVideosSetValues(qint32 idSet, const QString& strSet, const QString& strOverview) :
	m_idSet(idSet),
	m_strSet(strSet),
	m_strOverview(strOverview)
{
}

void cMyVideosSetValues::set(qint32 idSet, const QString& strSet, const QString& strOverview)
{
	m_idSet			= idSet;
	m_strSet		= strSet;
	m_strOverview	= strOverview;
}

inline bool	cMyVideosSetValues::operator==(const cMyVideosSetValues b) const
{
	if(m_idSet != b.m_idSet) return(false);
	if(m_strSet != b.m_strSet) return(false);
	if(m_strOverview != b.m_strOverview) return(false);
	return(true);
}

inline bool	cMyVideosSetValues::operator!=(const cMyVideosSetValues b) const
{
	if(m_idSet != b.m_idSet
		|| m_strSet != b.m_strSet
		|| m_strOverview != b.m_strOverview)
		return(true);
	return(false);
}

cMyVideosSet::cMyVideosSet(qint32 idSet, const QString& strSet, const QString& strOverview) :
	m_values(idSet, strSet, strOverview)
{
	m_oValues	= m_values;
}

qint32 cMyVideosSet::idSet()
{
	return(m_values.m_idSet);
}

QString cMyVideosSet::strSet()
{
	return(m_values.m_strSet);
}

QString cMyVideosSet::strOverview()
{
	return(m_values.m_strOverview);
}

bool cMyVideosSet::isNew()
{
	return(false);
}

bool cMyVideosSet::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosSetList::cMyVideosSetList()
{
}

cMyVideosSet* cMyVideosSetList::add(qint32 idSet, const QString& strSet, const QString& strOverview)
{
	cMyVideosSet*	lpNew	= new cMyVideosSet(idSet, strSet, strOverview);
	append(lpNew);
	return(lpNew);
}

cMyVideosSet* cMyVideosSetList::get(qint32 idSet)
{
	for(int z = 0;z < count();z++)
	{
		if(at(z)->idSet() == idSet)
			return(at(z));
	}
	return(0);
}

cMyVideosStreamDetailsVideoValues::cMyVideosStreamDetailsVideoValues() :
	m_szVideoCodec("UNSET"),
	m_dAspectRatio(-1),
	m_iWidth(-1),
	m_iHeight(-1)
{
}

cMyVideosStreamDetailsVideoValues::cMyVideosStreamDetailsVideoValues(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight) :
	m_szVideoCodec(szVideoCodec),
	m_dAspectRatio(dAspectRatio),
	m_iWidth(iWidth),
	m_iHeight(iHeight)
{
}

void cMyVideosStreamDetailsVideoValues::set(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight)
{
	m_szVideoCodec	= szVideoCodec;
	m_dAspectRatio	= dAspectRatio;
	m_iWidth		= iWidth;
	m_iHeight		= iHeight;
}

inline bool	cMyVideosStreamDetailsVideoValues::operator==(const cMyVideosStreamDetailsVideoValues b) const
{
	if(m_szVideoCodec != b.m_szVideoCodec) return(false);
	if(m_dAspectRatio != b.m_dAspectRatio) return(false);
	if(m_iWidth != b.m_iWidth) return(false);
	if(m_iHeight != b.m_iHeight) return(false);
	return(true);
}

inline bool	cMyVideosStreamDetailsVideoValues::operator!=(const cMyVideosStreamDetailsVideoValues b) const
{
	if(m_szVideoCodec != b.m_szVideoCodec
		|| m_dAspectRatio != b.m_dAspectRatio
		|| m_iWidth != b.m_iWidth
		|| m_iHeight != b.m_iHeight)
		return(true);
	return(false);
}

cMyVideosStreamDetailsVideo::cMyVideosStreamDetailsVideo(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight) :
	m_values(szVideoCodec, dAspectRatio, iWidth, iHeight)
{
	m_oValues	= m_values;
}

QString cMyVideosStreamDetailsVideo::videoCodec()
{
	return(m_values.m_szVideoCodec);
}

qreal cMyVideosStreamDetailsVideo::aspectRatio()
{
	return(m_values.m_dAspectRatio);
}

qint32 cMyVideosStreamDetailsVideo::width()
{
	return(m_values.m_iWidth);
}

qint32 cMyVideosStreamDetailsVideo::height()
{
	return(m_values.m_iHeight);
}

bool cMyVideosStreamDetailsVideo::isNew()
{
	return(false);
}

bool cMyVideosStreamDetailsVideo::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosStreamDetailsVideoList::cMyVideosStreamDetailsVideoList()
{
}

cMyVideosStreamDetailsVideo* cMyVideosStreamDetailsVideoList::add(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight)
{
	cMyVideosStreamDetailsVideo*	lpNew	= new cMyVideosStreamDetailsVideo(szVideoCodec, dAspectRatio, iWidth, iHeight);
	append(lpNew);
	return(lpNew);
}

cMyVideosStreamDetailsAudioValues::cMyVideosStreamDetailsAudioValues() :
	m_szAudioCodec("UNSET"),
	m_iAudioChannels(-1),
	m_szAudioLanguage("UNSET"),
	m_szStereoMode("UNSET")
{
}

cMyVideosStreamDetailsAudioValues::cMyVideosStreamDetailsAudioValues(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode) :
	m_szAudioCodec(szAudioCodec),
	m_iAudioChannels(iAudioChannels),
	m_szAudioLanguage(szAudioLanguage),
	m_szStereoMode(szStereoMode)
{
}

void cMyVideosStreamDetailsAudioValues::set(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode)
{
	m_szAudioCodec		= szAudioCodec;
	m_iAudioChannels	= iAudioChannels;
	m_szAudioLanguage	= szAudioLanguage;
	m_szStereoMode		= szStereoMode;
}

inline bool	cMyVideosStreamDetailsAudioValues::operator==(const cMyVideosStreamDetailsAudioValues b) const
{
	if(m_szAudioCodec != b.m_szAudioCodec) return(false);
	if(m_iAudioChannels != b.m_iAudioChannels) return(false);
	if(m_szAudioLanguage != b.m_szAudioLanguage) return(false);
	if(m_szStereoMode != b.m_szStereoMode) return(false);
	return(true);
}

inline bool	cMyVideosStreamDetailsAudioValues::operator!=(const cMyVideosStreamDetailsAudioValues b) const
{
	if(m_szAudioCodec != b.m_szAudioCodec
		|| m_iAudioChannels != b.m_iAudioChannels
		|| m_szAudioLanguage != b.m_szAudioLanguage
		|| m_szStereoMode != b.m_szStereoMode)
		return(true);
	return(false);
}

cMyVideosStreamDetailsAudio::cMyVideosStreamDetailsAudio(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode) :
	m_values(szAudioCodec, iAudioChannels, szAudioLanguage, szStereoMode)
{
	m_oValues	= m_values;
}

QString cMyVideosStreamDetailsAudio::audioCodec()
{
	return(m_values.m_szAudioCodec);
}

qint32 cMyVideosStreamDetailsAudio::audioChannels()
{
	return(m_values.m_iAudioChannels);
}

QString cMyVideosStreamDetailsAudio::audioLanguage()
{
	return(m_values.m_szAudioLanguage);
}

QString cMyVideosStreamDetailsAudio::stereoMode()
{
	return(m_values.m_szStereoMode);
}

bool cMyVideosStreamDetailsAudio::isNew()
{
	return(false);
}

bool cMyVideosStreamDetailsAudio::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosStreamDetailsAudioList::cMyVideosStreamDetailsAudioList()
{
}

cMyVideosStreamDetailsAudio* cMyVideosStreamDetailsAudioList::add(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode)
{
	cMyVideosStreamDetailsAudio*	lpNew	= new cMyVideosStreamDetailsAudio(szAudioCodec, iAudioChannels, szAudioLanguage, szStereoMode);
	append(lpNew);
	return(lpNew);
}

cMyVideosStreamDetailsSubtitleValues::cMyVideosStreamDetailsSubtitleValues() :
	m_szSubtitleLanguage("UNSET")
{
}

cMyVideosStreamDetailsSubtitleValues::cMyVideosStreamDetailsSubtitleValues(const QString& szSubtitleLanguage) :
	m_szSubtitleLanguage(szSubtitleLanguage)
{
}

void cMyVideosStreamDetailsSubtitleValues::set(const QString& szSubtitleLanguage)
{
	m_szSubtitleLanguage	= szSubtitleLanguage;
}

inline bool	cMyVideosStreamDetailsSubtitleValues::operator==(const cMyVideosStreamDetailsSubtitleValues b) const
{
	if(m_szSubtitleLanguage != b.m_szSubtitleLanguage) return(false);
	return(true);
}

inline bool	cMyVideosStreamDetailsSubtitleValues::operator!=(const cMyVideosStreamDetailsSubtitleValues b) const
{
	if(m_szSubtitleLanguage != b.m_szSubtitleLanguage)
		return(true);
	return(false);
}

cMyVideosStreamDetailsSubtitle::cMyVideosStreamDetailsSubtitle(const QString& szSubtitleLanguage) :
	m_values(szSubtitleLanguage)
{
	m_oValues	= m_values;
}

QString cMyVideosStreamDetailsSubtitle::subtitleLanguage()
{
	return(m_values.m_szSubtitleLanguage);
}

bool cMyVideosStreamDetailsSubtitle::isNew()
{
	return(false);
}

bool cMyVideosStreamDetailsSubtitle::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosStreamDetailsSubtitleList::cMyVideosStreamDetailsSubtitleList()
{
}

cMyVideosStreamDetailsSubtitle* cMyVideosStreamDetailsSubtitleList::add(const QString& szSubtitleLanguage)
{
	cMyVideosStreamDetailsSubtitle*	lpNew	= new cMyVideosStreamDetailsSubtitle(szSubtitleLanguage);
	append(lpNew);
	return(lpNew);
}

cMyVideosActorValues::cMyVideosActorValues() :
	m_actorID(-1),
	m_szName("UNSET"),
	m_szArtURLs("UNSET")
{
}

cMyVideosActorValues::cMyVideosActorValues(qint32 actorID, const QString& szName, const QString& szArtURLs) :
	m_actorID(actorID),
	m_szName(szName),
	m_szArtURLs(szArtURLs)
{
}

void cMyVideosActorValues::set(qint32 actorID, const QString& szName, const QString& szArtURLs)
{
	m_actorID	= actorID;
	m_szName	= szName;
	m_szArtURLs	= szArtURLs;
}

inline bool	cMyVideosActorValues::operator==(const cMyVideosActorValues b) const
{
	if(m_actorID != b.m_actorID) return(false);
	if(m_szName != b.m_szName) return(false);
	if(m_szArtURLs != b.m_szArtURLs) return(false);
	return(true);
}

inline bool	cMyVideosActorValues::operator!=(const cMyVideosActorValues b) const
{
	if(m_actorID != b.m_actorID
		|| m_szName != b.m_szName
		|| m_szArtURLs != b.m_szArtURLs)
		return(true);
	return(false);
}

cMyVideosActor::cMyVideosActor(qint32 actorID, const QString& szName, const QString& szArtUrls) :
	m_values(actorID, szName, szArtUrls)
{
	m_oValues	= m_values;
}

qint32 cMyVideosActor::actorID()
{
	return(m_values.m_actorID);
}

QString cMyVideosActor::name()
{
	return(m_values.m_szName);
}

QString cMyVideosActor::szArtURLs()
{
	return(m_values.m_szArtURLs);
}

bool cMyVideosActor::isNew()
{
	if(m_values.m_actorID == -1)
		return(true);
	return(false);
}

bool cMyVideosActor::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosActorList::cMyVideosActorList()
{
}

cMyVideosActor* cMyVideosActorList::add(qint32 actorID, const QString& szName, const QString& szArtURLs)
{
	cMyVideosActor*	lpNew	= new cMyVideosActor(actorID, szName, szArtURLs);
	append(lpNew);
	return(lpNew);
}

cMyVideosActor* cMyVideosActorList::find(qint32 actorID)
{
	for(int z = 0;z < count();z++)
	{
		if(at(z)->actorID() == actorID)
			return(at(z));
	}
	return(0);
}

cMyVideosActorLinkValues::cMyVideosActorLinkValues() :
	m_lpActor(0),
	m_szRole("UNSET"),
	m_castOrder(-1)
{
}

cMyVideosActorLinkValues::cMyVideosActorLinkValues(cMyVideosActor* lpActor, const QString& szRole, qint32 castOrder) :
	m_lpActor(lpActor),
	m_szRole(szRole),
	m_castOrder(castOrder)
{
}

void cMyVideosActorLinkValues::set(cMyVideosActor* lpActor, const QString& szRole, qint32 castOrder)
{
	m_lpActor	= lpActor;
	m_szRole	= szRole;
	m_castOrder	= castOrder;
}

inline bool cMyVideosActorLinkValues::operator==(const cMyVideosActorLinkValues b) const
{
	if(m_lpActor != b.m_lpActor) return(false);
	if(m_szRole != b.m_szRole) return(false);
	if(m_castOrder != b.m_castOrder) return(false);
	return(true);
}

inline bool	cMyVideosActorLinkValues::operator!=(const cMyVideosActorLinkValues b) const
{
	if(m_lpActor != b.m_lpActor
		|| m_szRole != b.m_szRole
		|| m_castOrder != b.m_castOrder)
		return(true);
	return(false);
}

cMyVideosActorLink::cMyVideosActorLink(cMyVideosActor *lpActor, const QString& szRole, qint32 cast_order) :
	m_values(lpActor, szRole, cast_order)
{
	m_oValues	= m_values;
}

cMyVideosActor* cMyVideosActorLink::actor()
{
	return(m_values.m_lpActor);
}

QString cMyVideosActorLink::role()
{
	return(m_values.m_szRole);
}

qint32 cMyVideosActorLink::castOrder()
{
	return(m_values.m_castOrder);
}

cMyVideosActorLinkList::cMyVideosActorLinkList()
{
}

cMyVideosActorLink*	cMyVideosActorLinkList::add(cMyVideosActor *lpActor, const QString& szRole, qint32 cast_order)
{
	cMyVideosActorLink*	lpNew	= new cMyVideosActorLink(lpActor, szRole, cast_order);
	append(lpNew);
	return(lpNew);
}

cMyVideosDirectorLinkValues::cMyVideosDirectorLinkValues() :
	m_lpActor(0)
{
}

cMyVideosDirectorLinkValues::cMyVideosDirectorLinkValues(cMyVideosActor* lpActor) :
	m_lpActor(lpActor)
{
}

void cMyVideosDirectorLinkValues::set(cMyVideosActor* lpActor)
{
	m_lpActor	= lpActor;
}

inline bool cMyVideosDirectorLinkValues::operator==(const cMyVideosDirectorLinkValues b) const
{
	if(m_lpActor != b.m_lpActor) return(false);
	return(true);
}

inline bool	cMyVideosDirectorLinkValues::operator!=(const cMyVideosDirectorLinkValues b) const
{
	if(m_lpActor != b.m_lpActor)
		return(true);
	return(false);
}

cMyVideosDirectorLink::cMyVideosDirectorLink(cMyVideosActor *lpActor) :
	m_values(lpActor)
{
	m_oValues	= m_values;
}

cMyVideosActor* cMyVideosDirectorLink::actor()
{
	return(m_values.m_lpActor);
}

cMyVideosDirectorLinkList::cMyVideosDirectorLinkList()
{
}

cMyVideosDirectorLink*	cMyVideosDirectorLinkList::add(cMyVideosActor *lpActor)
{
	cMyVideosDirectorLink*	lpNew	= new cMyVideosDirectorLink(lpActor);
	append(lpNew);
	return(lpNew);
}

cMyVideosWriterLinkValues::cMyVideosWriterLinkValues() :
	m_lpActor(0)
{
}

cMyVideosWriterLinkValues::cMyVideosWriterLinkValues(cMyVideosActor* lpActor) :
	m_lpActor(lpActor)
{
}

void cMyVideosWriterLinkValues::set(cMyVideosActor* lpActor)
{
	m_lpActor	= lpActor;
}

inline bool cMyVideosWriterLinkValues::operator==(const cMyVideosWriterLinkValues b) const
{
	if(m_lpActor != b.m_lpActor) return(false);
	return(true);
}

inline bool	cMyVideosWriterLinkValues::operator!=(const cMyVideosWriterLinkValues b) const
{
	if(m_lpActor != b.m_lpActor)
		return(true);
	return(false);
}

cMyVideosWriterLink::cMyVideosWriterLink(cMyVideosActor *lpActor) :
	m_values(lpActor)
{
	m_oValues	= m_values;
}

cMyVideosActor* cMyVideosWriterLink::actor()
{
	return(m_values.m_lpActor);
}

cMyVideosWriterLinkList::cMyVideosWriterLinkList()
{
}

cMyVideosWriterLink*	cMyVideosWriterLinkList::add(cMyVideosActor *lpActor)
{
	cMyVideosWriterLink*	lpNew	= new cMyVideosWriterLink(lpActor);
	append(lpNew);
	return(lpNew);
}

cMyVideosCountryValues::cMyVideosCountryValues() :
	m_countryID(-1),
	m_szName("UNSET")
{
}

cMyVideosCountryValues::cMyVideosCountryValues(qint32 countryID, const QString& szName) :
	m_countryID(countryID),
	m_szName(szName)
{
}

void cMyVideosCountryValues::set(qint32 countryID, const QString& szName)
{
	m_countryID	= countryID;
	m_szName	= szName;
}

inline bool	cMyVideosCountryValues::operator==(const cMyVideosCountryValues b) const
{
	if(m_countryID != b.m_countryID) return(false);
	if(m_szName != b.m_szName) return(false);
	return(true);
}

inline bool	cMyVideosCountryValues::operator!=(const cMyVideosCountryValues b) const
{
	if(m_countryID != b.m_countryID
		|| m_szName != b.m_szName)
		return(true);
	return(false);
}

cMyVideosCountry::cMyVideosCountry(qint32 countryID, const QString& szName) :
	m_values(countryID, szName)
{
	m_oValues	= m_values;
}

qint32 cMyVideosCountry::countryID()
{
	return(m_values.m_countryID);
}

QString cMyVideosCountry::name()
{
	return(m_values.m_szName);
}

bool cMyVideosCountry::isNew()
{
	if(m_values.m_countryID == -1)
		return(true);
	return(false);
}

bool cMyVideosCountry::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosCountryList::cMyVideosCountryList()
{
}

cMyVideosCountry* cMyVideosCountryList::add(qint32 countryID, const QString& szName)
{
	cMyVideosCountry*	lpNew	= new cMyVideosCountry(countryID, szName);
	append(lpNew);
	return(lpNew);
}

cMyVideosCountry* cMyVideosCountryList::find(qint32 countryID)
{
	for(int z = 0;z < count();z++)
	{
		if(at(z)->countryID() == countryID)
			return(at(z));
	}
	return(0);
}

cMyVideosCountryLinkValues::cMyVideosCountryLinkValues() :
	m_lpCountry(0)
{
}

cMyVideosCountryLinkValues::cMyVideosCountryLinkValues(cMyVideosCountry* lpCountry) :
	m_lpCountry(lpCountry)
{
}

void cMyVideosCountryLinkValues::set(cMyVideosCountry* lpCountry)
{
	m_lpCountry	= lpCountry;
}

inline bool cMyVideosCountryLinkValues::operator==(const cMyVideosCountryLinkValues b) const
{
	if(m_lpCountry!= b.m_lpCountry) return(false);
	return(true);
}

inline bool	cMyVideosCountryLinkValues::operator!=(const cMyVideosCountryLinkValues b) const
{
	if(m_lpCountry!= b.m_lpCountry)
		return(true);
	return(false);
}

cMyVideosCountryLink::cMyVideosCountryLink(cMyVideosCountry* lpCountry) :
	m_values(lpCountry)
{
	m_oValues	= m_values;
}

cMyVideosCountry* cMyVideosCountryLink::country()
{
	return(m_values.m_lpCountry);
}

cMyVideosCountryLinkList::cMyVideosCountryLinkList()
{
}

cMyVideosCountryLink*	cMyVideosCountryLinkList::add(cMyVideosCountry *lpCountry)
{
	cMyVideosCountryLink*	lpNew	= new cMyVideosCountryLink(lpCountry);
	append(lpNew);
	return(lpNew);
}

cMyVideosGenreValues::cMyVideosGenreValues() :
	m_genreID(-1),
	m_szName("UNSET")
{
}

cMyVideosGenreValues::cMyVideosGenreValues(qint32 genreID, const QString& szName) :
	m_genreID(genreID),
	m_szName(szName)
{
}

void cMyVideosGenreValues::set(qint32 genreID, const QString& szName)
{
	m_genreID	= genreID;
	m_szName	= szName;
}

inline bool	cMyVideosGenreValues::operator==(const cMyVideosGenreValues b) const
{
	if(m_genreID != b.m_genreID) return(false);
	if(m_szName != b.m_szName) return(false);
	return(true);
}

inline bool	cMyVideosGenreValues::operator!=(const cMyVideosGenreValues b) const
{
	if(m_genreID != b.m_genreID
		|| m_szName != b.m_szName)
		return(true);
	return(false);
}

cMyVideosGenre::cMyVideosGenre(qint32 genreID, const QString& szName) :
	m_values(genreID, szName)
{
	m_oValues	= m_values;
}

qint32 cMyVideosGenre::genreID()
{
	return(m_values.m_genreID);
}

QString cMyVideosGenre::name()
{
	return(m_values.m_szName);
}

bool cMyVideosGenre::isNew()
{
	if(m_values.m_genreID == -1)
		return(true);
	return(false);
}

bool cMyVideosGenre::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosGenreList::cMyVideosGenreList()
{
}

cMyVideosGenre* cMyVideosGenreList::add(qint32 genreID, const QString& szName)
{
	cMyVideosGenre*	lpNew	= new cMyVideosGenre(genreID, szName);
	append(lpNew);
	return(lpNew);
}

cMyVideosGenre* cMyVideosGenreList::find(qint32 genreID)
{
	for(int z = 0;z < count();z++)
	{
		if(at(z)->genreID() == genreID)
			return(at(z));
	}
	return(0);
}

cMyVideosGenreLinkValues::cMyVideosGenreLinkValues() :
	m_lpGenre(0)
{
}

cMyVideosGenreLinkValues::cMyVideosGenreLinkValues(cMyVideosGenre* lpGenre) :
	m_lpGenre(lpGenre)
{
}

void cMyVideosGenreLinkValues::set(cMyVideosGenre* lpGenre)
{
	m_lpGenre	= lpGenre;
}

inline bool cMyVideosGenreLinkValues::operator==(const cMyVideosGenreLinkValues b) const
{
	if(m_lpGenre!= b.m_lpGenre) return(false);
	return(true);
}

inline bool	cMyVideosGenreLinkValues::operator!=(const cMyVideosGenreLinkValues b) const
{
	if(m_lpGenre!= b.m_lpGenre)
		return(true);
	return(false);
}

cMyVideosGenreLink::cMyVideosGenreLink(cMyVideosGenre* lpGenre) :
	m_values(lpGenre)
{
	m_oValues	= m_values;
}

cMyVideosGenre* cMyVideosGenreLink::genre()
{
	return(m_values.m_lpGenre);
}

cMyVideosGenreLinkList::cMyVideosGenreLinkList()
{
}

cMyVideosGenreLink*	cMyVideosGenreLinkList::add(cMyVideosGenre *lpGenre)
{
	cMyVideosGenreLink*	lpNew	= new cMyVideosGenreLink(lpGenre);
	append(lpNew);
	return(lpNew);
}

cMyVideosStudioValues::cMyVideosStudioValues() :
	m_studioID(-1),
	m_szName("UNSET")
{
}

cMyVideosStudioValues::cMyVideosStudioValues(qint32 studioID, const QString& szName) :
	m_studioID(studioID),
	m_szName(szName)
{
}

void cMyVideosStudioValues::set(qint32 studioID, const QString& szName)
{
	m_studioID	= studioID;
	m_szName	= szName;
}

inline bool	cMyVideosStudioValues::operator==(const cMyVideosStudioValues b) const
{
	if(m_studioID != b.m_studioID) return(false);
	if(m_szName != b.m_szName) return(false);
	return(true);
}

inline bool	cMyVideosStudioValues::operator!=(const cMyVideosStudioValues b) const
{
	if(m_studioID != b.m_studioID
		|| m_szName != b.m_szName)
		return(true);
	return(false);
}

cMyVideosStudio::cMyVideosStudio(qint32 studioID, const QString& szName) :
	m_values(studioID, szName)
{
	m_oValues	= m_values;
}

qint32 cMyVideosStudio::studioID()
{
	return(m_values.m_studioID);
}

QString cMyVideosStudio::name()
{
	return(m_values.m_szName);
}

bool cMyVideosStudio::isNew()
{
	if(m_values.m_studioID == -1)
		return(true);
	return(false);
}

bool cMyVideosStudio::isChanged()
{
	if(m_values != m_oValues)
		return(true);
	return(false);
}

cMyVideosStudioList::cMyVideosStudioList()
{
}

cMyVideosStudio* cMyVideosStudioList::add(qint32 studioID, const QString& szName)
{
	cMyVideosStudio*	lpNew	= new cMyVideosStudio(studioID, szName);
	append(lpNew);
	return(lpNew);
}

cMyVideosStudio* cMyVideosStudioList::find(qint32 studioID)
{
	for(int z = 0;z < count();z++)
	{
		if(at(z)->studioID() == studioID)
			return(at(z));
	}
	return(0);
}

cMyVideosStudioLinkValues::cMyVideosStudioLinkValues() :
	m_lpStudio(0)
{
}

cMyVideosStudioLinkValues::cMyVideosStudioLinkValues(cMyVideosStudio* lpStudio) :
	m_lpStudio(lpStudio)
{
}

void cMyVideosStudioLinkValues::set(cMyVideosStudio* lpStudio)
{
	m_lpStudio	= lpStudio;
}

inline bool cMyVideosStudioLinkValues::operator==(const cMyVideosStudioLinkValues b) const
{
	if(m_lpStudio!= b.m_lpStudio) return(false);
	return(true);
}

inline bool	cMyVideosStudioLinkValues::operator!=(const cMyVideosStudioLinkValues b) const
{
	if(m_lpStudio!= b.m_lpStudio)
		return(true);
	return(false);
}

cMyVideosStudioLink::cMyVideosStudioLink(cMyVideosStudio* lpStudio) :
	m_values(lpStudio)
{
	m_oValues	= m_values;
}

cMyVideosStudio* cMyVideosStudioLink::studio()
{
	return(m_values.m_lpStudio);
}

cMyVideosStudioLinkList::cMyVideosStudioLinkList()
{
}

cMyVideosStudioLink*	cMyVideosStudioLinkList::add(cMyVideosStudio *lpStudio)
{
	cMyVideosStudioLink*	lpNew	= new cMyVideosStudioLink(lpStudio);
	append(lpNew);
	return(lpNew);
}

cMyVideosValues::cMyVideosValues() :
	m_idMovie(-1), m_idFile(-1), m_szLocalMovieTitle("UNSET"), m_szMoviePlot("UNSET"), m_szMoviePlotOutline("UNSET"),
	m_szMovieTagline("UNSET"), m_iRatingVotes(-1), m_dRating(-1), m_szWriters("UNSET"), m_iYearReleased(-1),
	m_szThumbnails("UNSET"), m_szIMDBID("UNSET"), m_szTitleFormattedForSorting("UNSET"), m_iRuntime(-1),
	m_szMPAARating("UNSET"), m_iIMDBTop250Ranking(-1), m_szGenre("UNSET"), m_szDirector("UNSET"), m_szOriginalMovieTitle("UNSET"),
	m_szStudio("UNSET"), m_szTrailerURL("UNSET"), m_szFanartURLs("UNSET"), m_szCountry("UNSET"), m_szFilePath("UNSET"), m_idPath(-1),
	m_iUserrating(-1), m_szFileName("UNSET"), m_szPathURL("UNSET"), m_iPlayCount(-1),
	m_dResumeTimeInSeconds(-1), m_dTotalTimeInSeconds(-1), m_lpSet(0), m_iVideoDuration(-1)
{
}

cMyVideosValues::cMyVideosValues(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet) :
	m_idMovie(idMovie), m_idFile(idFile), m_szLocalMovieTitle(szLocalMovieTitle), m_szMoviePlot(szMoviePlot), m_szMoviePlotOutline(szMoviePlotOutline),
	m_szMovieTagline(szMovieTagline), m_iRatingVotes(iRatingVotes), m_dRating(dRating), m_szWriters(szWriters), m_iYearReleased(iYearReleased),
	m_szThumbnails(szThumbnails), m_szIMDBID(szIMDBID), m_szTitleFormattedForSorting(szTitleFormattedForSorting), m_iRuntime(iRuntime),
	m_szMPAARating(szMPAARating), m_iIMDBTop250Ranking(iIMDBTop250Ranking), m_szGenre(szGenre), m_szDirector(szDirector), m_szOriginalMovieTitle(szOriginalMovieTitle),
	m_szStudio(szStudio), m_szTrailerURL(szTrailerURL), m_szFanartURLs(szFanartURLs), m_szCountry(szCountry), m_szFilePath(szFilePath), m_idPath(idPath),
	m_iUserrating(iUserrating), m_szFileName(szFileName), m_szPathURL(szPathURL), m_iPlayCount(iPlayCount),
	m_lastPlayed(lastPlayed), m_dateAdded(dateAdded), m_dResumeTimeInSeconds(dResumeTimeInSeconds), m_dTotalTimeInSeconds(dTotalTimeInSeconds), m_lpSet(lpSet), m_iVideoDuration(-1)
{
}

void cMyVideosValues::set(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet)
{
	m_idMovie						= idMovie;
	m_idFile						= idFile;
	m_szLocalMovieTitle				= szLocalMovieTitle;
	m_szMoviePlot					= szMoviePlot;
	m_szMoviePlotOutline			= szMoviePlotOutline;
	m_szMovieTagline				= szMovieTagline;
	m_iRatingVotes					= iRatingVotes;
	m_dRating						= dRating;
	m_szWriters						= szWriters;
	m_iYearReleased					= iYearReleased;
	m_szThumbnails					= szThumbnails;
	m_szIMDBID						= szIMDBID;
	m_szTitleFormattedForSorting	= szTitleFormattedForSorting;
	m_iRuntime						= iRuntime;
	m_szMPAARating					= szMPAARating;
	m_iIMDBTop250Ranking			= iIMDBTop250Ranking;
	m_szGenre						= szGenre;
	m_szDirector					= szDirector;
	m_szOriginalMovieTitle			= szOriginalMovieTitle;
	m_szStudio						= szStudio;
	m_szTrailerURL					= szTrailerURL;
	m_szFanartURLs					= szFanartURLs;
	m_szCountry						= szCountry;
	m_szFilePath					= szFilePath;
	m_idPath						= idPath;
	m_iUserrating					= iUserrating;
	m_szFileName					= szFileName;
	m_szPathURL						= szPathURL;
	m_iPlayCount					= iPlayCount;
	m_lastPlayed					= lastPlayed;
	m_dateAdded						= dateAdded;
	m_dResumeTimeInSeconds			= dResumeTimeInSeconds;
	m_dTotalTimeInSeconds			= dTotalTimeInSeconds;
	m_lpSet							= lpSet;
}

inline bool cMyVideosValues::operator==(const cMyVideosValues b) const
{
	if(m_idMovie != b.m_idMovie) return(false);
	if(m_idFile != b.m_idFile) return(false);
	if(m_szLocalMovieTitle != b.m_szLocalMovieTitle) return(false);
	if(m_szMoviePlot != b.m_szMoviePlot) return(false);
	if(m_szMoviePlotOutline != b.m_szMoviePlotOutline) return(false);
	if(m_szMovieTagline != b.m_szMovieTagline) return(false);
	if(m_iRatingVotes != b.m_iRatingVotes) return(false);
	if(m_dRating != b.m_dRating) return(false);
	if(m_szWriters != b.m_szWriters) return(false);
	if(m_iYearReleased != b.m_iYearReleased) return(false);
	if(m_szThumbnails != b.m_szThumbnails) return(false);
	if(m_szIMDBID != b.m_szIMDBID) return(false);
	if(m_szTitleFormattedForSorting != b.m_szTitleFormattedForSorting) return(false);
	if(m_iRuntime != b.m_iRuntime) return(false);
	if(m_szMPAARating != b.m_szMPAARating) return(false);
	if(m_iIMDBTop250Ranking != b.m_iIMDBTop250Ranking) return(false);
	if(m_szGenre != b.m_szGenre) return(false);
	if(m_szDirector != b.m_szDirector) return(false);
	if(m_szOriginalMovieTitle != b.m_szOriginalMovieTitle) return(false);
	if(m_szStudio != b.m_szStudio) return(false);
	if(m_szTrailerURL != b.m_szTrailerURL) return(false);
	if(m_szFanartURLs != b.m_szFanartURLs) return(false);
	if(m_szCountry != b.m_szCountry) return(false);
	if(m_szFilePath != b.m_szFilePath) return(false);
	if(m_idPath != b.m_idPath) return(false);
	if(m_iUserrating != b.m_iUserrating) return(false);
	if(m_szFileName != b.m_szFileName) return(false);
	if(m_szPathURL != b.m_szPathURL) return(false);
	if(m_iPlayCount != b.m_iPlayCount) return(false);
	if(m_lastPlayed != b.m_lastPlayed) return(false);
	if(m_dateAdded != b.m_dateAdded) return(false);
	if(m_dResumeTimeInSeconds != b.m_dResumeTimeInSeconds) return(false);
	if(m_dTotalTimeInSeconds != b.m_dTotalTimeInSeconds) return(false);
	if(m_iVideoDuration != b.m_iVideoDuration) return(false);
	if(m_lpSet != b.m_lpSet) return(false);
	return(true);
}

inline bool cMyVideosValues::operator!=(const cMyVideosValues b) const
{
	if(m_idMovie != b.m_idMovie
			|| m_idFile != b.m_idFile
			|| m_szLocalMovieTitle != b.m_szLocalMovieTitle
			|| m_szMoviePlot != b.m_szMoviePlot
			|| m_szMoviePlotOutline != b.m_szMoviePlotOutline
			|| m_szMovieTagline != b.m_szMovieTagline
			|| m_iRatingVotes != b.m_iRatingVotes
			|| m_dRating != b.m_dRating
			|| m_szWriters != b.m_szWriters
			|| m_iYearReleased != b.m_iYearReleased
			|| m_szThumbnails != b.m_szThumbnails
			|| m_szIMDBID != b.m_szIMDBID
			|| m_szTitleFormattedForSorting != b.m_szTitleFormattedForSorting
			|| m_iRuntime != b.m_iRuntime
			|| m_szMPAARating != b.m_szMPAARating
			|| m_iIMDBTop250Ranking != b.m_iIMDBTop250Ranking
			|| m_szGenre != b.m_szGenre
			|| m_szDirector != b.m_szDirector
			|| m_szOriginalMovieTitle != b.m_szOriginalMovieTitle
			|| m_szStudio != b.m_szStudio
			|| m_szTrailerURL != b.m_szTrailerURL
			|| m_szFanartURLs != b.m_szFanartURLs
			|| m_szCountry != b.m_szCountry
			|| m_szFilePath != b.m_szFilePath
			|| m_idPath != b.m_idPath
			|| m_iUserrating != b.m_iUserrating
			|| m_szFileName != b.m_szFileName
			|| m_szPathURL != b.m_szPathURL
			|| m_iPlayCount != b.m_iPlayCount
			|| m_lastPlayed != b.m_lastPlayed
			|| m_dateAdded != b.m_dateAdded
			|| m_dResumeTimeInSeconds != b.m_dResumeTimeInSeconds
			|| m_dTotalTimeInSeconds != b.m_dTotalTimeInSeconds
			|| m_iVideoDuration != b.m_iVideoDuration
			|| m_lpSet != b.m_lpSet)
		return(true);
	return(false);
}

cMyVideos::cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet) :
	m_values(idMovie, idFile, szLocalMovieTitle, szMoviePlot, szMoviePlotOutline, szMovieTagline, iRatingVotes, dRating, szWriters, iYearReleased,
			szThumbnails, szIMDBID, szTitleFormattedForSorting, iRuntime, szMPAARating, iIMDBTop250Ranking, szGenre, szDirector, szOriginalMovieTitle,
			szStudio, szTrailerURL, szFanartURLs, szCountry, szFilePath, idPath, iUserrating, szFileName, szPathURL, iPlayCount,
			lastPlayed, dateAdded, dResumeTimeInSeconds, dTotalTimeInSeconds, lpSet)
{
	m_oValues	= m_values;
}

cMyVideosList::cMyVideosList()
{
}

cMyVideos* cMyVideosList::add(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
							  const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
							  const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
							  const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
							  const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
							  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
							  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
							  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet *lpSet)
{
	cMyVideos*	lpNew	= new cMyVideos(idMovie, idFile, szLocalMovieTitle, szMoviePlot, szMoviePlotOutline, szMovieTagline, iRatingVotes, dRating,
										szWriters, iYearReleased, szThumbnails, szIMDBID, szTitleFormattedForSorting, iRuntime, szMPAARating,
										iIMDBTop250Ranking, szGenre, szDirector, szOriginalMovieTitle, szStudio, szTrailerURL, szFanartURLs,
										szCountry, szFilePath, idPath, iUserrating, szFileName, szPathURL, iPlayCount,
										lastPlayed, dateAdded, dResumeTimeInSeconds, dTotalTimeInSeconds, lpSet);
	append(lpNew);
	return(lpNew);
}

void cMyVideos::loadActors(QSqlDatabase& m_db, cMyVideosActorList videosActorList)
{
	if(m_values.m_actors.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   actor_id, "
				  "         role, "
				  "         cast_order "
				  "FROM     actor_link "
				  "WHERE    media_id=:media_id AND "
				  "         media_type='movie' "
				  "ORDER BY cast_order;");
	query.bindValue(":media_id", m_values.m_idMovie);
	query.exec();
	while(query.next())
	{
		cMyVideosActor*	lpActor	= videosActorList.find(query.value("actor_id").toInt());
		if(lpActor)
			m_values.m_actors.add(lpActor, query.value("role").toString(), query.value("cast_order").toInt());
	}
	m_oValues.m_actors	= m_values.m_actors;
}

void cMyVideos::loadDirectors(QSqlDatabase& m_db, cMyVideosActorList videosActorList)
{
	if(m_values.m_directors.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   actor_id "
				  "FROM     director_link "
				  "WHERE    media_id=:media_id AND "
				  "         media_type='movie';");
	query.bindValue(":media_id", m_values.m_idMovie);
	query.exec();
	while(query.next())
	{
		cMyVideosActor*	lpActor	= videosActorList.find(query.value("actor_id").toInt());
		if(lpActor)
			m_values.m_directors.add(lpActor);
	}
	m_oValues.m_directors	= m_values.m_directors;
}

void cMyVideos::loadWriters(QSqlDatabase& m_db, cMyVideosActorList videosActorList)
{
	if(m_values.m_writers.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   actor_id "
				  "FROM     writer_link "
				  "WHERE    media_id=:media_id AND "
				  "         media_type='movie';");
	query.bindValue(":media_id", m_values.m_idMovie);
	query.exec();
	while(query.next())
	{
		cMyVideosActor*	lpActor	= videosActorList.find(query.value("actor_id").toInt());
		if(lpActor)
			m_values.m_writers.add(lpActor);
	}
	m_oValues.m_writers	= m_values.m_writers;
}

void cMyVideos::loadCountries(QSqlDatabase& m_db, cMyVideosCountryList videosCountryList)
{
	if(m_values.m_countries.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   country_id "
				  "FROM     country_link "
				  "WHERE    media_id=:media_id AND "
				  "         media_type='movie';");
	query.bindValue(":media_id", m_values.m_idMovie);
	query.exec();
	while(query.next())
	{
		cMyVideosCountry*	lpCountry	= videosCountryList.find(query.value("country_id").toInt());
		if(lpCountry)
			m_values.m_countries.add(lpCountry);
	}
	m_oValues.m_countries	= m_values.m_countries;
}

void cMyVideos::loadGenres(QSqlDatabase& m_db, cMyVideosGenreList videosGenreList)
{
	if(m_values.m_genres.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   genre_id "
				  "FROM     genre_link "
				  "WHERE    media_id=:media_id AND "
				  "         media_type='movie';");
	query.bindValue(":media_id", m_values.m_idMovie);
	query.exec();
	while(query.next())
	{
		cMyVideosGenre*	lpGenre	= videosGenreList.find(query.value("genre_id").toInt());
		if(lpGenre)
			m_values.m_genres.add(lpGenre);
	}
	m_oValues.m_genres	= m_values.m_genres;
}

void cMyVideos::loadStudios(QSqlDatabase& m_db, cMyVideosStudioList videosStudioList)
{
	if(m_values.m_studios.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   studio_id "
				  "FROM     studio_link "
				  "WHERE    media_id=:media_id AND "
				  "         media_type='movie';");
	query.bindValue(":media_id", m_values.m_idMovie);
	query.exec();
	while(query.next())
	{
		cMyVideosStudio*	lpStudio	= videosStudioList.find(query.value("studio_id").toInt());
		if(lpStudio)
			m_values.m_studios.add(lpStudio);
	}
	m_oValues.m_studios	= m_values.m_studios;
}

void cMyVideos::loadVideoStream(QSqlDatabase& m_db)
{
	if(m_values.m_streamVideo.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   strVideoCodec, "
				  "         fVideoAspect, "
				  "         iVideoWidth, "
				  "         iVideoHeight, "
				  "         iVideoDuration "
				  "FROM     streamdetails "
				  "WHERE    idFile=:idFile AND "
				  "         iStreamType=0;");
	query.bindValue(":idFile", m_values.m_idFile);
	query.exec();
	while(query.next())
	{
		m_values.m_streamVideo.add(query.value("strVideoCodec").toString(), query.value("fVideoAspect").toDouble(), query.value("iVideoWidth").toInt(), query.value("iVideoHeight").toInt());
		this->m_values.m_iVideoDuration		= query.value("iVideoDuration").toInt();
		this->m_oValues.m_iVideoDuration	= query.value("iVideoDuration").toInt();
	}

	m_oValues.m_streamVideo	= m_values.m_streamVideo;
}

void cMyVideos::loadAudioStream(QSqlDatabase& m_db)
{
	if(m_values.m_streamAudio.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   strAudioCodec, "
				  "         iAudioChannels, "
				  "         strAudioLanguage, "
				  "         strStereoMode "
				  "FROM     streamdetails "
				  "WHERE    idFile=:idFile AND "
				  "         iStreamType=1;");
	query.bindValue(":idFile", m_values.m_idFile);
	query.exec();
	while(query.next())
		m_values.m_streamAudio.add(query.value("strAudioCodec").toString(), query.value("iAudioChannels").toInt(), query.value("strAudioLanguage").toString(), query.value("strStereoMode").toString());

	m_oValues.m_streamAudio	= m_values.m_streamAudio;
}

void cMyVideos::loadSubtitleStream(QSqlDatabase& m_db)
{
	if(m_values.m_streamSubtitle.count())
		return;

	QSqlQuery	query(m_db);
	query.prepare("SELECT   strSubtitleLanguage "
				  "FROM     streamdetails "
				  "WHERE    idFile=:idFile AND "
				  "         iStreamType=2;");
	query.bindValue(":idFile", m_values.m_idFile);
	query.exec();
	while(query.next())
		m_values.m_streamSubtitle.add(query.value("strSubtitleLanguage").toString());

	m_oValues.m_streamSubtitle	= m_values.m_streamSubtitle;
}

void cMyVideos::fillActorsList(QStandardItemModel *lpView)
{
	for(int z = 0;z < m_values.m_actors.count();z++)
	{
		QList<QStandardItem*> items;
		items.append(new QStandardItem(m_values.m_actors.at(z)->actor()->name()));
		items.append(new QStandardItem(m_values.m_actors.at(z)->role()));
		QVariant	v	= qVariantFromValue(m_values.m_actors.at(z));
		items[0]->setData(v, Qt::UserRole);
		items[1]->setData(v, Qt::UserRole);
		lpView->appendRow(items);
	}
}

void cMyVideos::fillDirectorsList(QStandardItemModel *lpView)
{
	for(int z = 0;z < m_values.m_directors.count();z++)
	{
		QStringList		list	= m_values.m_directors.at(z)->m_values.m_lpActor->name().split(", ");
		for(int x = 0;x < list.count();x++)
		{
			QStandardItem*	lpItem	= new QStandardItem(list.at(x));
			QVariant		v		= qVariantFromValue(m_values.m_directors.at(z));
			lpItem->setData(v, Qt::UserRole);
			lpView->appendRow(lpItem);
		}
	}
}

void cMyVideos::fillWritersList(QStandardItemModel *lpView)
{
	for(int z = 0;z < m_values.m_writers.count();z++)
	{
		QStringList		list	= m_values.m_writers.at(z)->m_values.m_lpActor->name().split(", ");
		for(int x = 0;x < list.count();x++)
		{
			QStandardItem*	lpItem	= new QStandardItem(list.at(x));
			QVariant		v		= qVariantFromValue(m_values.m_writers.at(z));
			lpItem->setData(v, Qt::UserRole);
			lpView->appendRow(lpItem);
		}
	}
}

void cMyVideos::fillCountriesList(QStandardItemModel* lpView)
{
	for(int z = 0;z < m_values.m_countries.count();z++)
	{
		QStringList		list	= m_values.m_countries.at(z)->m_values.m_lpCountry->name().split(", ");
		for(int x = 0;x < list.count();x++)
		{
			QStandardItem*	lpItem	= new QStandardItem(list.at(x));
			QVariant		v		= qVariantFromValue(m_values.m_countries.at(z));
			lpItem->setData(v, Qt::UserRole);
			lpView->appendRow(lpItem);
		}
	}
}

void cMyVideos::fillGenresList(QStandardItemModel* lpView)
{
	for(int z = 0;z < m_values.m_genres.count();z++)
	{
		QStringList		list	= m_values.m_genres.at(z)->m_values.m_lpGenre->name().split(", ");
		for(int x = 0;x < list.count();x++)
		{
			QStandardItem*	lpItem	= new QStandardItem(list.at(x));
			QVariant		v		= qVariantFromValue(m_values.m_genres.at(z));
			lpItem->setData(v, Qt::UserRole);
			lpView->appendRow(lpItem);
		}
	}
}

void cMyVideos::fillStudiosList(QStandardItemModel* lpView)
{
	for(int z = 0;z < m_values.m_studios.count();z++)
	{
		QStringList		list	= m_values.m_studios.at(z)->m_values.m_lpStudio->name().split(", ");
		for(int x = 0;x < list.count();x++)
		{
			QStandardItem*	lpItem	= new QStandardItem(list.at(x));
			QVariant		v		= qVariantFromValue(m_values.m_studios.at(z));
			lpItem->setData(v, Qt::UserRole);
			lpView->appendRow(lpItem);
		}
	}
}

void cMyVideos::fillVideoStreamList(QStandardItemModel* lpView)
{
	for(int z = 0;z < m_values.m_streamVideo.count();z++)
	{
		cMyVideosStreamDetailsVideo*	lpVideo	= m_values.m_streamVideo.at(z);
		QList<QStandardItem*>			items;
		items.append(new QStandardItem(lpVideo->videoCodec()));
		items.append(new QStandardItem(QString("%1").arg(lpVideo->aspectRatio())));
		items.append(new QStandardItem(QString("%1").arg(lpVideo->width())));
		items.append(new QStandardItem(QString("%1").arg(lpVideo->height())));
		QVariant	v	= qVariantFromValue(lpVideo);
		items[0]->setData(v, Qt::UserRole);
		items[1]->setData(v, Qt::UserRole);
		items[2]->setData(v, Qt::UserRole);
		items[3]->setData(v, Qt::UserRole);
		lpView->appendRow(items);
	}
}

void cMyVideos::fillAudioStreamList(QStandardItemModel* lpView)
{
	for(int z = 0;z < m_values.m_streamAudio.count();z++)
	{
		cMyVideosStreamDetailsAudio*	lpAudio	= m_values.m_streamAudio.at(z);
		QList<QStandardItem*>			items;
		items.append(new QStandardItem(lpAudio->audioCodec()));
		items.append(new QStandardItem(QString("%1").arg(lpAudio->audioChannels())));
		items.append(new QStandardItem(lpAudio->audioLanguage()));
		items.append(new QStandardItem(lpAudio->stereoMode()));
		QVariant	v	= qVariantFromValue(lpAudio);
		items[0]->setData(v, Qt::UserRole);
		items[1]->setData(v, Qt::UserRole);
		items[2]->setData(v, Qt::UserRole);
		items[3]->setData(v, Qt::UserRole);
		lpView->appendRow(items);
	}
}

void cMyVideos::fillSubtitleStreamList(QStandardItemModel* lpView)
{
	for(int z = 0;z < m_values.m_streamSubtitle.count();z++)
	{
		cMyVideosStreamDetailsSubtitle*	lpSubtitle	= m_values.m_streamSubtitle.at(z);
		QStandardItem*					lpItem		= new QStandardItem(lpSubtitle->subtitleLanguage());
		QVariant						v			= qVariantFromValue(lpSubtitle);
		lpItem->setData(v, Qt::UserRole);
		lpView->appendRow(lpItem);
	}
}

qint32 cMyVideos::idMovie()
{
	return(m_values.m_idMovie);
}

qint32 cMyVideos::idFile()
{
	return(m_values.m_idFile);
}

QString cMyVideos::localMovieTitle()
{
	return(m_values.m_szLocalMovieTitle);
}

QString cMyVideos::moviePlot()
{
	return(m_values.m_szMoviePlot);
}

QString cMyVideos::moviePlotOutline()
{
	return(m_values.m_szMoviePlotOutline);
}

QString cMyVideos::movieTagline()
{
	return(m_values.m_szMovieTagline);
}

qint32 cMyVideos::ratingVotes()
{
	return(m_values.m_iRatingVotes);
}

qreal cMyVideos::rating()
{
	return(m_values.m_dRating);
}

QStringList cMyVideos::writers()
{
	return(m_values.m_szWriters.split(", "));
}

qint32 cMyVideos::yearReleased()
{
	return(m_values.m_iYearReleased);
}

QList<STRING2> cMyVideos::thumbnails()
{
	QList<STRING2>	list;
	QStringList		tmpList	= m_values.m_szThumbnails.split("><");

	for(int z = 0;z < tmpList.count();z++)
	{
		QString	str	= tmpList.at(z);
		STRING2	str2;
		if(str.indexOf("preview="))
		{
			str2._1	= str.mid(str.indexOf("preview=")+9);
			str2._1	= str2._1.left(str2._1.indexOf("\">"));
			str2._2	= str.mid(str.indexOf("\">")+2);
			str2._2	= str2._2.left(str2._2.indexOf("</thumb"));
			list.append(str2);
		}
	}
	return(list);
}

QString cMyVideos::imdbID()
{
	return(m_values.m_szIMDBID);
}

QString cMyVideos::titleFormattedForSorting()
{
	return(m_values.m_szTitleFormattedForSorting);
}

qint32 cMyVideos::runtime()
{
	return(m_values.m_iRuntime);
}

QString cMyVideos::mpaaRating()
{
	return(m_values.m_szMPAARating);
}

qint32 cMyVideos::imdbTop250Ranking()
{
	return(m_values.m_iIMDBTop250Ranking);
}

QStringList cMyVideos::genre()
{
	return(m_values.m_szGenre.split(" / "));
}

QStringList cMyVideos::director()
{
	return(m_values.m_szDirector.split(", "));
}

QString cMyVideos::originalMovieTitle()
{
	return(m_values.m_szOriginalMovieTitle);
}

QStringList cMyVideos::studio()
{
	return(m_values.m_szStudio.split(" / "));
}

QString cMyVideos::trailerURL()
{
	return(m_values.m_szTrailerURL);
}

QList<STRING2> cMyVideos::fanartURL()
{
	QString			tmp		= m_values.m_szFanartURLs.mid(8, m_values.m_szFanartURLs.length()-17);
	QList<STRING2>	list;
	QStringList		tmpList	= tmp.split("><");

	for(int z = 0;z < tmpList.count();z++)
	{
		QString	str	= tmpList.at(z);
		STRING2	str2;
		if(str.indexOf("preview="))
		{
			str2._1	= str.mid(str.indexOf("preview=")+9);
			str2._1	= str2._1.left(str2._1.indexOf("\">"));
			str2._2	= str.mid(str.indexOf("\">")+2);
			str2._2	= str2._2.left(str2._2.indexOf("</thumb"));
			list.append(str2);
		}
	}
	return(list);
}

QStringList cMyVideos::country()
{
	return(m_values.m_szCountry.split(" / "));
}

QString cMyVideos::filePath()
{
	return(m_values.m_szFilePath);
}

qint32 cMyVideos::userRating()
{
	return(m_values.m_iUserrating);
}

QString cMyVideos::fileName()
{
	return(m_values.m_szFileName);
}

QString cMyVideos::pathURL()
{
	return(m_values.m_szPathURL);
}

qint32 cMyVideos::playCount()
{
	return(m_values.m_iPlayCount);
}

QDateTime cMyVideos::lastPlayed()
{
	return(m_values.m_lastPlayed);
}

QDateTime cMyVideos::dateAdded()
{
	return(m_values.m_dateAdded);
}

qreal cMyVideos::resumeTimeInSeconds()
{
	return(m_values.m_dResumeTimeInSeconds);
}

qreal cMyVideos::totalTimeInSeconds()
{
	return(m_values.m_dTotalTimeInSeconds);
}

cMyVideosSet* cMyVideos::set()
{
	return(m_values.m_lpSet);
}

bool cMyVideos::isNew()
{
	if(m_values.m_idMovie == -1)
		return(true);
	return(false);
}

bool cMyVideos::isChanged()
{
	return(m_values != m_oValues);
}

cMyTVShowsValues::cMyTVShowsValues() :
		m_idEpisode(-1),
		m_idFile(-1),
		m_szEpisodeTitle("UNSET"),
		m_szPlotSummary("UNSET"),
		m_dRating(-1),
		m_szWriters("UNSET"),
		m_szThumbnailUrl("UNSET"),
		m_iEpisodeLength(-1),
		m_szDirector("UNSET"),
		m_iSeasonNumber(-1),
		m_iEpisodeNumber(-1),
		m_iSeasonFormattedForSorting(-1),
		m_iEpisodeFormattedForSorting(-1),
		m_iBookmark(-1),
		m_szFullPath("UNSET"),
		m_idShow(-1),
		m_iUserrating(-1),
		m_idSeason(-1),
		m_szFileName("UNSET"),
		m_szPath("UNSET"),
		m_iPlayCount(-1),
		m_szTitle("UNSET"),
		m_szGenre("UNSET"),
		m_szStudio("UNSET"),
		m_szMPAA("UNSET"),
		m_dResumeTimeInSeconds(-1),
		m_dTotalTimeInSeconds(-1)
{
}

cMyTVShowsValues::cMyTVShowsValues(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
								   const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
								   qint32 iSeasonFormattetForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
								   qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
								   const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
								   qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds) :
	m_idEpisode(idEpisode),
	m_idFile(idFile),
	m_szEpisodeTitle(szEpisodeTitle),
	m_szPlotSummary(szPlotSummary),
	m_dRating(dRating),
	m_szWriters(szWriters),
	m_firstAired(firstAired),
	m_szThumbnailUrl(szThumbnailUrl),
	m_iEpisodeLength(iEpisodeLength),
	m_szDirector(szDirector),
	m_iSeasonNumber(iSeasonNumber),
	m_iEpisodeNumber(iEpisodeNumber),
	m_iSeasonFormattedForSorting(iSeasonFormattetForSorting),
	m_iEpisodeFormattedForSorting(iEpisodeFormattedForSorting),
	m_iBookmark(iBookmark),
	m_szFullPath(szFullPath),
	m_idShow(idShow),
	m_iUserrating(iUserrating),
	m_idSeason(idSeason),
	m_szFileName(szFileName),
	m_szPath(szPath),
	m_iPlayCount(iPlayCount),
	m_lastPlayed(lastPlayed),
	m_dateAdded(dateAdded),
	m_szTitle(szTitle),
	m_szGenre(szGenre),
	m_szStudio(szStudio),
	m_premiereDate(premiereDate),
	m_szMPAA(szMPAA),
	m_dResumeTimeInSeconds(dResumeTimeInSeconds),
	m_dTotalTimeInSeconds(dTotalTimeInSeconds)
{
}

void cMyTVShowsValues::set(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
						   const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
						   qint32 iSeasonFormattedForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
						   qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
						   const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
						   qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds)
{
	m_idEpisode						= idEpisode;
	m_idFile						= idFile;
	m_szEpisodeTitle				= szEpisodeTitle;
	m_szPlotSummary					= szPlotSummary;
	m_dRating						= dRating;
	m_szWriters						= szWriters;
	m_firstAired					= firstAired;
	m_szThumbnailUrl				= szThumbnailUrl;
	m_iEpisodeLength				= iEpisodeLength;
	m_szDirector					= szDirector;
	m_iSeasonNumber					= iSeasonNumber;
	m_iEpisodeNumber				= iEpisodeNumber;
	m_iSeasonFormattedForSorting	= iSeasonFormattedForSorting;
	m_iEpisodeFormattedForSorting	= iEpisodeFormattedForSorting;
	m_iBookmark						= iBookmark;
	m_szFullPath					= szFullPath;
	m_idShow						= idShow;
	m_iUserrating					= iUserrating;
	m_idSeason						= idSeason;
	m_szFileName					= szFileName;
	m_szPath						= szPath;
	m_iPlayCount					= iPlayCount;
	m_lastPlayed					= lastPlayed;
	m_dateAdded						= dateAdded;
	m_szTitle						= szTitle;
	m_szGenre						= szGenre;
	m_szStudio						= szStudio;
	m_premiereDate					= premiereDate;
	m_szMPAA						= szMPAA;
	m_dResumeTimeInSeconds			= dResumeTimeInSeconds;
	m_dTotalTimeInSeconds			= dTotalTimeInSeconds;
}

inline bool cMyTVShowsValues::operator==(const cMyTVShowsValues b) const
{
	if(m_idEpisode != b.m_idEpisode) return(false);
	if(m_idFile != b.m_idFile) return(false);
	if(m_szEpisodeTitle != b.m_szEpisodeTitle) return(false);
	if(m_szPlotSummary != b.m_szPlotSummary) return(false);
	if(m_dRating != b.m_dRating) return(false);
	if(m_szWriters != b.m_szWriters) return(false);
	if(m_firstAired != b.m_firstAired) return(false);
	if(m_szThumbnailUrl != b.m_szThumbnailUrl) return(false);
	if(m_iEpisodeLength != b.m_iEpisodeLength) return(false);
	if(m_szDirector != b.m_szDirector) return(false);
	if(m_iSeasonNumber != b.m_iSeasonNumber) return(false);
	if(m_iEpisodeNumber != b.m_iEpisodeNumber) return(false);
	if(m_iSeasonFormattedForSorting != b.m_iSeasonFormattedForSorting) return(false);
	if(m_iEpisodeFormattedForSorting != b.m_iEpisodeFormattedForSorting) return(false);
	if(m_iBookmark != b.m_iBookmark) return(false);
	if(m_szFullPath != b.m_szFullPath) return(false);
	if(m_idShow != b.m_idShow) return(false);
	if(m_iUserrating != b.m_iUserrating) return(false);
	if(m_idSeason != b.m_idSeason) return(false);
	if(m_szFileName != b.m_szFileName) return(false);
	if(m_szPath != b.m_szPath) return(false);
	if(m_iPlayCount != b.m_iPlayCount) return(false);
	if(m_lastPlayed != b.m_lastPlayed) return(false);
	if(m_dateAdded != b.m_dateAdded) return(false);
	if(m_szTitle != b.m_szTitle) return(false);
	if(m_szGenre != b.m_szGenre) return(false);
	if(m_szStudio != b.m_szStudio) return(false);
	if(m_premiereDate != b.m_premiereDate) return(false);
	if(m_szMPAA != b.m_szMPAA) return(false);
	if(m_dResumeTimeInSeconds != b.m_dResumeTimeInSeconds) return(false);
	if(m_dTotalTimeInSeconds != b.m_dTotalTimeInSeconds) return(false);
	return(true);
}

inline bool cMyTVShowsValues::operator!=(const cMyTVShowsValues b) const
{
	if(m_idEpisode != b.m_idEpisode
		|| m_idFile != b.m_idFile
		|| m_szEpisodeTitle != b.m_szEpisodeTitle
		|| m_szPlotSummary != b.m_szPlotSummary
		|| m_dRating != b.m_dRating
		|| m_szWriters != b.m_szWriters
		|| m_firstAired != b.m_firstAired
		|| m_szThumbnailUrl != b.m_szThumbnailUrl
		|| m_iEpisodeLength != b.m_iEpisodeLength
		|| m_szDirector != b.m_szDirector
		|| m_iSeasonNumber != b.m_iSeasonNumber
		|| m_iEpisodeNumber != b.m_iEpisodeNumber
		|| m_iSeasonFormattedForSorting != b.m_iSeasonFormattedForSorting
		|| m_iEpisodeFormattedForSorting != b.m_iEpisodeFormattedForSorting
		|| m_iBookmark != b.m_iBookmark
		|| m_szFullPath != b.m_szFullPath
		|| m_idShow != b.m_idShow
		|| m_iUserrating != b.m_iUserrating
		|| m_idSeason != b.m_idSeason
		|| m_szFileName != b.m_szFileName
		|| m_szPath != b.m_szPath
		|| m_iPlayCount != b.m_iPlayCount
		|| m_lastPlayed != b.m_lastPlayed
		|| m_dateAdded != b.m_dateAdded
		|| m_szTitle != b.m_szTitle
		|| m_szGenre != b.m_szGenre
		|| m_szStudio != b.m_szStudio
		|| m_premiereDate != b.m_premiereDate
		|| m_szMPAA != b.m_szMPAA
		|| m_dResumeTimeInSeconds != b.m_dResumeTimeInSeconds
		|| m_dTotalTimeInSeconds != b.m_dTotalTimeInSeconds)
		return(true);
	return(false);
}

cMyTVShows::cMyTVShows(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
					   const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
					   qint32 iSeasonFormattedForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
					   qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
					   const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
					   qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds) :
	m_values(idEpisode, idFile, szEpisodeTitle, szPlotSummary, dRating, szWriters, firstAired,
			 szThumbnailUrl, iEpisodeLength, szDirector, iSeasonNumber, iEpisodeNumber,
			 iSeasonFormattedForSorting, iEpisodeFormattedForSorting, iBookmark, szFullPath, idShow,  iUserrating,
			 idSeason, szFileName, szPath, iPlayCount, lastPlayed, dateAdded,
			 szTitle, szGenre, szStudio, premiereDate, szMPAA,
			 dResumeTimeInSeconds, dTotalTimeInSeconds)
{
	m_oValues	= m_values;
}

qint32 cMyTVShows::idEpisode()
{
	return(m_values.m_idEpisode);
}

qint32 cMyTVShows::idFile()
{
	return(m_values.m_idFile);
}

QString cMyTVShows::episodeTitle()
{
	return(m_values.m_szEpisodeTitle);
}

QString cMyTVShows::plotSummary()
{
	return(m_values.m_szPlotSummary);
}

qreal cMyTVShows::rating()
{
	return(m_values.m_dRating);
}

QStringList cMyTVShows::writers()
{
	return(m_values.m_szWriters.split(", "));
}

QDateTime cMyTVShows::firstAired()
{
	return(m_values.m_firstAired);
}

QString cMyTVShows::thumbnailUrl()
{
	return(m_values.m_szThumbnailUrl);
}

qint32 cMyTVShows::episodeLength()
{
	return(m_values.m_iEpisodeLength);
}

QStringList cMyTVShows::director()
{
	return(m_values.m_szDirector.split(", "));
}

qint32 cMyTVShows::seasonNumber()
{
	return(m_values.m_iSeasonNumber);
}

qint32 cMyTVShows::episodeNumber()
{
	return(m_values.m_iEpisodeNumber);
}

qint32 cMyTVShows::seasonFormattedForSorting()
{
	return(m_values.m_iSeasonFormattedForSorting);
}

qint32 cMyTVShows::episodeFormattedForSorting()
{
	return(m_values.m_iEpisodeFormattedForSorting);
}

qint32 cMyTVShows::bookmark()
{
	return(m_values.m_iBookmark);
}

QString cMyTVShows::fullPath()
{
	return(m_values.m_szFullPath);
}

qint32 cMyTVShows::idShow()
{
	return(m_values.m_idShow);
}

qint32 cMyTVShows::userRating()
{
	return(m_values.m_iUserrating);
}

qint32 cMyTVShows::idSeason()
{
	return(m_values.m_idSeason);
}

QString cMyTVShows::fileName()
{
	return(m_values.m_szFileName);
}

QString cMyTVShows::path()
{
	return(m_values.m_szPath);
}

qint32 cMyTVShows::playCount()
{
	return(m_values.m_iPlayCount);
}

QDateTime cMyTVShows::lastPlayed()
{
	return(m_values.m_lastPlayed);
}

QDateTime cMyTVShows::dateAdded()
{
	return(m_values.m_dateAdded);
}

QString cMyTVShows::title()
{
	return(m_values.m_szTitle);
}

QStringList cMyTVShows::genre()
{
	return(m_values.m_szGenre.split(", "));
}

QStringList cMyTVShows::studio()
{
	return(m_values.m_szStudio.split(", "));
}

QDateTime cMyTVShows::premierDate()
{
	return(m_values.m_premiereDate);
}

QString cMyTVShows::mpaaRating()
{
	return(m_values.m_szMPAA);
}

qreal cMyTVShows::resumeTimeInSeconds()
{
	return(m_values.m_dResumeTimeInSeconds);
}

qreal cMyTVShows::totalTimeInSeconds()
{
	return(m_values.m_dTotalTimeInSeconds);
}

cMyTVShowsList::cMyTVShowsList()
{
}

cMyTVShows* cMyTVShowsList::add(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
								const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
								qint32 iSeasonFormattetForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
								qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
								const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
								qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds)
{
	cMyTVShows*	lpNew	= new cMyTVShows(idEpisode, idFile, szEpisodeTitle, szPlotSummary, dRating, szWriters, firstAired,
										 szThumbnailUrl, iEpisodeLength, szDirector, iSeasonNumber, iEpisodeNumber,
										 iSeasonFormattetForSorting, iEpisodeFormattedForSorting, iBookmark, szFullPath, idShow,  iUserrating,
										 idSeason, szFileName, szPath, iPlayCount, lastPlayed, dateAdded,
										 szTitle, szGenre, szStudio, premiereDate, szMPAA,
										 dResumeTimeInSeconds, dTotalTimeInSeconds);
	append(lpNew);
	return(lpNew);
}
