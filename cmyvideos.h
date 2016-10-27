#ifndef CMYVIDEOS_H
#define CMYVIDEOS_H


#include <QString>
#include <QDateTime>
#include <QList>
#include <QMetaType>


typedef struct tagSTRING2
{
	QString	_1;
	QString	_2;
}	STRING2;

class cMyVideosValues
{
public:
	cMyVideosValues();
	cMyVideosValues(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
				const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
				const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
				const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
				const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
				const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
				const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
				qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	void		set(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
				const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
				const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
				const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
				const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
				const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
				const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
				qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	inline bool	operator==(const cMyVideosValues b) const;
	inline bool	operator!=(const cMyVideosValues b) const;

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
	qint32		m_iIMDBTop250Ranking;					// c13
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

class cMyVideos
{
public:
	cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			  const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			  const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			  const QString& szMPAARating,qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			  const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	qint32			idMovie();
	qint32			idFile();
	QString			localMovieTitle();
	QString			moviePlot();
	QString			moviePlotOutline();
	QString			movieTagline();
	qint32			ratingVotes();
	qreal			rating();
	QStringList		writers();
	qint32			yearReleased();
	QList<STRING2>	thumbnails();
	QString			imdbID();
	QString			titleFormattedForSorting();
	qint32			runtime();
	QString			mpaaRating();
	qint32			imdbTop250Ranking();
	QStringList		genre();
	QStringList		director();
	QString			originalMovieTitle();
	QStringList		studio();
	QString			trailerURL();
	QList<STRING2>	fanartURL();
	QStringList		country();
	QString			filePath();
	qint32			idSet();
	qint32			userRating();
	QString			set();
	QString			setOverview();
	QString			fileName();
	QString			pathURL();
	qint32			playCount();
	QDateTime		lastPlayed();
	QDateTime		dateAdded();
	qreal			resumeTimeInSeconds();
	qreal			totalTimeInSeconds();

	bool			isNew();
	bool			isChanged();
private:
	cMyVideosValues	m_values;
	cMyVideosValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideos*)

class cMyVideosList : public QList<cMyVideos*>
{
public:
	cMyVideosList();
	cMyVideos*	add(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
					const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
					const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
					const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
					const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
					const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
					const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
					qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

private:
};

#endif // CMYVIDEOS_H
