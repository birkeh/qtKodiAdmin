#ifndef CMYVIDEOS_H
#define CMYVIDEOS_H


#include <QString>
#include <QDateTime>
#include <QList>
#include <QMetaType>


class cMyVideos
{
public:

	cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			  const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			  const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			  const QString& szMPAARating, const QString& szIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			  const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	qint32		idMovie();
	qint32		idFile();
	QString		localMovieTitle();
	QString		moviePlot();
	QString		moviePlotOutline();
	QString		movieTagline();
	qint32		yearReleased();
	qint32		idSet();
	QString		set();
private:
	qint32		m_idMovie;
	qint32		m_idFile;
	QString		m_szLocalMovieTitle;					// c00
	QString		m_szMoviePlot;							// c01
	QString		m_szMoviePlotOutline;					// c02
	QString		m_szMovieTagline;						// c03
	qint32		m_iRatingVotes;							// c04
	qreal		m_dRating;								// c05
	QString		m_szWriters;							// c06
	qint32		m_iYearReleased;						// c07
	QString		m_szThumbnails;							// c08 (Selection List)
	QString		m_szIMDBID;								// c09
	QString		m_szTitleFormattedForSorting;			// c10
	qint32		m_iRuntime;								// c11
	QString		m_szMPAARating;							// c12
	QString		m_szIMDBTop250Ranking;					// c13
	QString		m_szGenre;								// c14
	QString		m_szDirector;							// c15
	QString		m_szOriginalMovieTitle;					// c16
	QString		m_szStudio;								// c18
	QString		m_szTrailerURL;							// c19
	QString		m_szFanartURLs;							// c20 (Selection List)
	QString		m_szCountry;							// c21
	QString		m_szFilePath;							// c22
	qint32		m_idPath;								// c23
	qint32		m_idSet;								// idSet
	qint32		m_iUserrating;							// userrating
	QString		m_szSet;								// strSet
	QString		m_szSetOverview;						// Set overview
	QString		m_szFileName;							// strFileName
	QString		m_szPathURL;							// strPath
	qint32		m_iPlayCount;							// playCount
	QDateTime	m_lastPlayed;							// lastPlayed
	QDateTime	m_dateAdded;							// dateAdded
	qreal		m_dResumeTimeInSeconds;					// resumeTimeInSeconds
	qreal		m_dTotalTimeInSeconds;					// totalTimeInSeconds
};

Q_DECLARE_METATYPE(cMyVideos*)

class cMyVideosList : public QList<cMyVideos*>
{
public:
	cMyVideosList();
	cMyVideos*	add(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
					const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
					const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
					const QString& szMPAARating, const QString& szIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
					const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
					const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
					const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
					qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

private:
};

#endif // CMYVIDEOS_H
