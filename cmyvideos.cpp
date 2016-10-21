#include "cmyvideos.h"

cMyVideos::cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			const QString& szMPAARating, const QString& szIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds) :
	m_idMovie(idMovie), m_idFile(idFile), m_szLocalMovieTitle(szLocalMovieTitle), m_szMoviePlot(szMoviePlot), m_szMoviePlotOutline(szMoviePlotOutline),
	m_szMovieTagline(szMovieTagline), m_iRatingVotes(iRatingVotes), m_dRating(dRating), m_szWriters(szWriters), m_iYearReleased(iYearReleased),
	m_szThumbnails(szThumbnails), m_szIMDBID(szIMDBID), m_szTitleFormattedForSorting(szTitleFormattedForSorting), m_iRuntime(iRuntime),
	m_szMPAARating(szMPAARating), m_szIMDBTop250Ranking(szIMDBTop250Ranking), m_szGenre(szGenre), m_szDirector(szDirector), m_szOriginalMovieTitle(szOriginalMovieTitle),
	m_szStudio(szStudio), m_szTrailerURL(szTrailerURL), m_szFanartURLs(szFanartURLs), m_szCountry(szCountry), m_szFilePath(szFilePath), m_idPath(idPath), m_idSet(idSet),
	m_iUserrating(iUserrating), m_szSet(szSet), m_szSetOverview(szSetOverview), m_szFileName(szFileName), m_szPathURL(szPathURL), m_iPlayCount(iPlayCount),
	m_lastPlayed(lastPlayed), m_dateAdded(dateAdded), m_dResumeTimeInSeconds(dResumeTimeInSeconds), m_dTotalTimeInSeconds(dTotalTimeInSeconds)
{
}

cMyVideosList::cMyVideosList()
{
}

cMyVideos* cMyVideosList::add(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
							  const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
							  const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
							  const QString& szMPAARating, const QString& szIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
							  const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
							  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
							  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
							  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds)
{
	cMyVideos*	lpNew	= new cMyVideos(idMovie, idFile, szLocalMovieTitle, szMoviePlot, szMoviePlotOutline, szMovieTagline, iRatingVotes, dRating,
										szWriters, iYearReleased, szThumbnails, szIMDBID, szTitleFormattedForSorting, iRuntime, szMPAARating,
										szIMDBTop250Ranking, szGenre, szDirector, szOriginalMovieTitle, szStudio, szTrailerURL, szFanartURLs,
										szCountry, szFilePath, idPath, idSet, iUserrating, szSet, szSetOverview, szFileName, szPathURL, iPlayCount,
										lastPlayed, dateAdded, dResumeTimeInSeconds, dTotalTimeInSeconds);
	append(lpNew);
	return(lpNew);
}
