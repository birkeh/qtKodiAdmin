#include "cmyvideos.h"


cMyVideosValues::cMyVideosValues() :
	m_idMovie(-1), m_idFile(-1), m_szLocalMovieTitle("UNSET"), m_szMoviePlot("UNSET"), m_szMoviePlotOutline("UNSET"),
	m_szMovieTagline("UNSET"), m_iRatingVotes(-1), m_dRating(-1), m_szWriters("UNSET"), m_iYearReleased(-1),
	m_szThumbnails("UNSET"), m_szIMDBID("UNSET"), m_szTitleFormattedForSorting("UNSET"), m_iRuntime(-1),
	m_szMPAARating("UNSET"), m_iIMDBTop250Ranking(-1), m_szGenre("UNSET"), m_szDirector("UNSET"), m_szOriginalMovieTitle("UNSET"),
	m_szStudio("UNSET"), m_szTrailerURL("UNSET"), m_szFanartURLs("UNSET"), m_szCountry("UNSET"), m_szFilePath("UNSET"), m_idPath(-1), m_idSet(-1),
	m_iUserrating(-1), m_szSet("UNSET"), m_szSetOverview("UNSET"), m_szFileName("UNSET"), m_szPathURL("UNSET"), m_iPlayCount(-1),
	m_dResumeTimeInSeconds(-1), m_dTotalTimeInSeconds(-1)
{
}

cMyVideosValues::cMyVideosValues(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds) :
	m_idMovie(idMovie), m_idFile(idFile), m_szLocalMovieTitle(szLocalMovieTitle), m_szMoviePlot(szMoviePlot), m_szMoviePlotOutline(szMoviePlotOutline),
	m_szMovieTagline(szMovieTagline), m_iRatingVotes(iRatingVotes), m_dRating(dRating), m_szWriters(szWriters), m_iYearReleased(iYearReleased),
	m_szThumbnails(szThumbnails), m_szIMDBID(szIMDBID), m_szTitleFormattedForSorting(szTitleFormattedForSorting), m_iRuntime(iRuntime),
	m_szMPAARating(szMPAARating), m_iIMDBTop250Ranking(iIMDBTop250Ranking), m_szGenre(szGenre), m_szDirector(szDirector), m_szOriginalMovieTitle(szOriginalMovieTitle),
	m_szStudio(szStudio), m_szTrailerURL(szTrailerURL), m_szFanartURLs(szFanartURLs), m_szCountry(szCountry), m_szFilePath(szFilePath), m_idPath(idPath), m_idSet(idSet),
	m_iUserrating(iUserrating), m_szSet(szSet), m_szSetOverview(szSetOverview), m_szFileName(szFileName), m_szPathURL(szPathURL), m_iPlayCount(iPlayCount),
	m_lastPlayed(lastPlayed), m_dateAdded(dateAdded), m_dResumeTimeInSeconds(dResumeTimeInSeconds), m_dTotalTimeInSeconds(dTotalTimeInSeconds)
{
}

void cMyVideosValues::set(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds)
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
	m_idSet							= idSet;
	m_iUserrating					= iUserrating;
	m_szSet							= szSet;
	m_szSetOverview					= szSetOverview;
	m_szFileName					= szFileName;
	m_szPathURL						= szPathURL;
	m_iPlayCount					= iPlayCount;
	m_lastPlayed					= lastPlayed;
	m_dateAdded						= dateAdded;
	m_dResumeTimeInSeconds			= dResumeTimeInSeconds;
	m_dTotalTimeInSeconds			= dTotalTimeInSeconds;
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
	if(m_idSet != b.m_idSet) return(false);
	if(m_iUserrating != b.m_iUserrating) return(false);
	if(m_szSet != b.m_szSet) return(false);
	if(m_szSetOverview != b.m_szSetOverview) return(false);
	if(m_szFileName != b.m_szFileName) return(false);
	if(m_szPathURL != b.m_szPathURL) return(false);
	if(m_iPlayCount != b.m_iPlayCount) return(false);
	if(m_lastPlayed != b.m_lastPlayed) return(false);
	if(m_dateAdded != b.m_dateAdded) return(false);
	if(m_dResumeTimeInSeconds != b.m_dResumeTimeInSeconds) return(false);
	if(m_dTotalTimeInSeconds != b.m_dTotalTimeInSeconds) return(false);
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
			|| m_idSet != b.m_idSet
			|| m_iUserrating != b.m_iUserrating
			|| m_szSet != b.m_szSet
			|| m_szSetOverview != b.m_szSetOverview
			|| m_szFileName != b.m_szFileName
			|| m_szPathURL != b.m_szPathURL
			|| m_iPlayCount != b.m_iPlayCount
			|| m_lastPlayed != b.m_lastPlayed
			|| m_dateAdded != b.m_dateAdded
			|| m_dResumeTimeInSeconds != b.m_dResumeTimeInSeconds
			|| m_dTotalTimeInSeconds != b.m_dTotalTimeInSeconds)
		return(true);
	return(false);
}

cMyVideos::cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds) :
	m_values(idMovie, idFile, szLocalMovieTitle, szMoviePlot, szMoviePlotOutline, szMovieTagline, iRatingVotes, dRating, szWriters, iYearReleased,
			szThumbnails, szIMDBID, szTitleFormattedForSorting, iRuntime, szMPAARating, iIMDBTop250Ranking, szGenre, szDirector, szOriginalMovieTitle,
			szStudio, szTrailerURL, szFanartURLs, szCountry, szFilePath, idPath, idSet, iUserrating, szSet, szSetOverview, szFileName, szPathURL, iPlayCount,
			lastPlayed, dateAdded, dResumeTimeInSeconds, dTotalTimeInSeconds)
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
							  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
							  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
							  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds)
{
	cMyVideos*	lpNew	= new cMyVideos(idMovie, idFile, szLocalMovieTitle, szMoviePlot, szMoviePlotOutline, szMovieTagline, iRatingVotes, dRating,
										szWriters, iYearReleased, szThumbnails, szIMDBID, szTitleFormattedForSorting, iRuntime, szMPAARating,
										iIMDBTop250Ranking, szGenre, szDirector, szOriginalMovieTitle, szStudio, szTrailerURL, szFanartURLs,
										szCountry, szFilePath, idPath, idSet, iUserrating, szSet, szSetOverview, szFileName, szPathURL, iPlayCount,
										lastPlayed, dateAdded, dResumeTimeInSeconds, dTotalTimeInSeconds);
	append(lpNew);
	return(lpNew);
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

qint32 cMyVideos::idSet()
{
	return(m_values.m_idSet);
}

qint32 cMyVideos::userRating()
{
	return(m_values.m_iUserrating);
}

QString cMyVideos::set()
{
	return(m_values.m_szSet);
}

QString cMyVideos::setOverview()
{
	return(m_values.m_szSetOverview);
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
