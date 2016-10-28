#ifndef CMYVIDEOS_H
#define CMYVIDEOS_H


#include <QString>
#include <QDateTime>
#include <QList>
#include <QMetaType>

#include <QSqlDatabase>
#include <QStandardItemModel>


typedef struct tagSTRING2
{
	QString	_1;
	QString	_2;
}	STRING2;

class cMyVideosActorValues
{
public:
	cMyVideosActorValues();
	cMyVideosActorValues(qint32 actorID, const QString& szName, const QString& szArtURLs);

	void			set(qint32 actorID, const QString& szName, const QString& szArtURLs);

	inline bool	operator==(const cMyVideosActorValues b) const;
	inline bool	operator!=(const cMyVideosActorValues b) const;

	qint32			m_actorID;
	QString			m_szName;
	QString			m_szArtURLs;
};

class cMyVideosActor
{
public:
	cMyVideosActor(qint32 actorID, const QString& szName, const QString& szArtUrls);

	qint32			actorID();
	QString			name();
	QString			szArtURLs();

	bool			isNew();
	bool			isChanged();
private:
	cMyVideosActorValues	m_values;
	cMyVideosActorValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosActor*)

class cMyVideosActorList : public QList<cMyVideosActor*>
{
public:
	cMyVideosActorList();
	cMyVideosActor*	add(qint32 actorID, const QString& szName, const QString& szArtURLs);
	cMyVideosActor*	find(qint32 actorID);
private:
};

class cMyVideosActorLinkValues
{
public:
	cMyVideosActorLinkValues();
	cMyVideosActorLinkValues(cMyVideosActor* lpActor, const QString& szRole, qint32 castOrder);

	void			set(cMyVideosActor* lpActor, const QString& szRole, qint32 castOrder);

	inline bool	operator==(const cMyVideosActorLinkValues b) const;
	inline bool	operator!=(const cMyVideosActorLinkValues b) const;

	cMyVideosActor*	m_lpActor;
	QString			m_szRole;
	qint32			m_castOrder;
};

class cMyVideosActorLink
{
public:
	cMyVideosActorLink(cMyVideosActor* lpActor, const QString& szRole, qint32 cast_order);

	cMyVideosActor*	actor();
	QString			role();
	qint32			castOrder();

	bool			isNew();
	bool			isChanged();

	cMyVideosActorLinkValues	m_values;
	cMyVideosActorLinkValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosActorLink*)

class cMyVideosActorLinkList : public QList<cMyVideosActorLink*>
{
public:
	cMyVideosActorLinkList();
	cMyVideosActorLink *add(cMyVideosActor* lpActor, const QString& szRole, qint32 cast_order);
};

class cMyVideosWriterLinkValues
{
public:
	cMyVideosWriterLinkValues();
	cMyVideosWriterLinkValues(cMyVideosActor* lpActor);

	void			set(cMyVideosActor* lpActor);

	inline bool	operator==(const cMyVideosWriterLinkValues b) const;
	inline bool	operator!=(const cMyVideosWriterLinkValues b) const;

	cMyVideosActor*	m_lpActor;
};

class cMyVideosWriterLink
{
public:
	cMyVideosWriterLink(cMyVideosActor* lpActor);

	cMyVideosActor*	actor();

	bool			isNew();
	bool			isChanged();

	cMyVideosWriterLinkValues	m_values;
	cMyVideosWriterLinkValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosWriterLink*)

class cMyVideosWriterLinkList : public QList<cMyVideosWriterLink*>
{
public:
	cMyVideosWriterLinkList();
	cMyVideosWriterLink *add(cMyVideosActor* lpActor);
};

class cMyVideosDirectorLinkValues
{
public:
	cMyVideosDirectorLinkValues();
	cMyVideosDirectorLinkValues(cMyVideosActor* lpActor);

	void			set(cMyVideosActor* lpActor);

	inline bool	operator==(const cMyVideosDirectorLinkValues b) const;
	inline bool	operator!=(const cMyVideosDirectorLinkValues b) const;

	cMyVideosActor*	m_lpActor;
};

class cMyVideosDirectorLink
{
public:
	cMyVideosDirectorLink(cMyVideosActor* lpActor);

	cMyVideosActor*	actor();

	bool			isNew();
	bool			isChanged();

	cMyVideosDirectorLinkValues	m_values;
	cMyVideosDirectorLinkValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosDirectorLink*)

class cMyVideosDirectorLinkList : public QList<cMyVideosDirectorLink*>
{
public:
	cMyVideosDirectorLinkList();
	cMyVideosDirectorLink *add(cMyVideosActor* lpActor);
};

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
	cMyVideosActorLinkList		m_actors;
	cMyVideosDirectorLinkList	m_directors;
	cMyVideosWriterLinkList		m_writers;
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

	void			loadActors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	void			loadDirectors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	void			loadWriters(QSqlDatabase& m_db, cMyVideosActorList videosActorList);

	void			fillActorsList(QStandardItemModel *lpView);
	void			fillDirectorsList(QStandardItemModel *lpView);
	void			fillWritersList(QStandardItemModel *lpView);

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
