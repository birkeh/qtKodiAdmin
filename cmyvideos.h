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

class cMyVideosStreamDetailsVideoValues
{
public:
	cMyVideosStreamDetailsVideoValues();
	cMyVideosStreamDetailsVideoValues(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);

	void				set(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);

	inline bool	operator==(const cMyVideosStreamDetailsVideoValues b) const;
	inline bool	operator!=(const cMyVideosStreamDetailsVideoValues b) const;

	QString				m_szVideoCodec;
	qreal				m_dAspectRatio;
	qint32				m_iWidth;
	qint32				m_iHeight;
};

class cMyVideosStreamDetailsAudioValues
{
public:
	cMyVideosStreamDetailsAudioValues();
	cMyVideosStreamDetailsAudioValues(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);

	void				set(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);

	inline bool	operator==(const cMyVideosStreamDetailsAudioValues b) const;
	inline bool	operator!=(const cMyVideosStreamDetailsAudioValues b) const;

	QString				m_szAudioCodec;
	qint32				m_iAudioChannels;
	QString				m_szAudioLanguage;
	QString				m_szStereoMode;
};

class cMyVideosStreamDetailsSubtitleValues
{
public:
	cMyVideosStreamDetailsSubtitleValues();
	cMyVideosStreamDetailsSubtitleValues(const QString& szSubtitleLanguage);

	void				set(const QString& szSubtitleLanguage);

	inline bool	operator==(const cMyVideosStreamDetailsSubtitleValues b) const;
	inline bool	operator!=(const cMyVideosStreamDetailsSubtitleValues b) const;

	QString				m_szSubtitleLanguage;
};

class cMyVideosStreamDetailsVideo
{
public:
	cMyVideosStreamDetailsVideo(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);

	QString			videoCodec();
	qreal			aspectRatio();
	qint32			width();
	qint32			height();

	bool			isNew();
	bool			isChanged();

	cMyVideosStreamDetailsVideoValues	m_values;
	cMyVideosStreamDetailsVideoValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosStreamDetailsVideo*)

class cMyVideosStreamDetailsVideoList : public QList<cMyVideosStreamDetailsVideo*>
{
public:
	cMyVideosStreamDetailsVideoList();
	cMyVideosStreamDetailsVideo*	add(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);
private:
};

class cMyVideosStreamDetailsAudio
{
public:
	cMyVideosStreamDetailsAudio(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);

	QString			audioCodec();
	qint32			audioChannels();
	QString			audioLanguage();
	QString			stereoMode();

	bool			isNew();
	bool			isChanged();

	cMyVideosStreamDetailsAudioValues	m_values;
	cMyVideosStreamDetailsAudioValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosStreamDetailsAudio*)

class cMyVideosStreamDetailsAudioList : public QList<cMyVideosStreamDetailsAudio*>
{
public:
	cMyVideosStreamDetailsAudioList();
	cMyVideosStreamDetailsAudio*	add(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);
private:
};

class cMyVideosStreamDetailsSubtitle
{
public:
	cMyVideosStreamDetailsSubtitle(const QString& szSubtitleLanguage);

	QString			subtitleLanguage();

	bool			isNew();
	bool			isChanged();

	cMyVideosStreamDetailsSubtitleValues	m_values;
	cMyVideosStreamDetailsSubtitleValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosStreamDetailsSubtitle*)

class cMyVideosStreamDetailsSubtitleList : public QList<cMyVideosStreamDetailsSubtitle*>
{
public:
	cMyVideosStreamDetailsSubtitleList();
	cMyVideosStreamDetailsSubtitle*	add(const QString& szSubtitleLanguage);
private:
};

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

class cMyVideosCountryValues
{
public:
	cMyVideosCountryValues();
	cMyVideosCountryValues(qint32 countryID, const QString& szName);

	void			set(qint32 countryID, const QString& szName);

	inline bool	operator==(const cMyVideosCountryValues b) const;
	inline bool	operator!=(const cMyVideosCountryValues b) const;

	qint32			m_countryID;
	QString			m_szName;
};

class cMyVideosCountry
{
public:
	cMyVideosCountry(qint32 countryID, const QString& szName);

	qint32			countryID();
	QString			name();

	bool			isNew();
	bool			isChanged();

	cMyVideosCountryValues	m_values;
	cMyVideosCountryValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosCountry*)

class cMyVideosCountryList : public QList<cMyVideosCountry*>
{
public:
	cMyVideosCountryList();
	cMyVideosCountry*	add(qint32 countryID, const QString& szName);
	cMyVideosCountry*	find(qint32 countryID);
private:
};

class cMyVideosCountryLinkValues
{
public:
	cMyVideosCountryLinkValues();
	cMyVideosCountryLinkValues(cMyVideosCountry* lpCountry);

	void			set(cMyVideosCountry* lpCountry);

	inline bool	operator==(const cMyVideosCountryLinkValues b) const;
	inline bool	operator!=(const cMyVideosCountryLinkValues b) const;

	cMyVideosCountry*	m_lpCountry;
};

class cMyVideosCountryLink
{
public:
	cMyVideosCountryLink(cMyVideosCountry* lpCountry);

	cMyVideosCountry*	country();

	bool			isNew();
	bool			isChanged();

	cMyVideosCountryLinkValues	m_values;
	cMyVideosCountryLinkValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosCountryLink*)

class cMyVideosCountryLinkList : public QList<cMyVideosCountryLink*>
{
public:
	cMyVideosCountryLinkList();
	cMyVideosCountryLink *add(cMyVideosCountry* lpCountry);
};

class cMyVideosGenreValues
{
public:
	cMyVideosGenreValues();
	cMyVideosGenreValues(qint32 genreID, const QString& szName);

	void			set(qint32 genreID, const QString& szName);

	inline bool	operator==(const cMyVideosGenreValues b) const;
	inline bool	operator!=(const cMyVideosGenreValues b) const;

	qint32			m_genreID;
	QString			m_szName;
};

class cMyVideosGenre
{
public:
	cMyVideosGenre(qint32 genreID, const QString& szName);

	qint32			genreID();
	QString			name();

	bool			isNew();
	bool			isChanged();

	cMyVideosGenreValues	m_values;
	cMyVideosGenreValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosGenre*)

class cMyVideosGenreList : public QList<cMyVideosGenre*>
{
public:
	cMyVideosGenreList();
	cMyVideosGenre*	add(qint32 genreID, const QString& szName);
	cMyVideosGenre*	find(qint32 genreID);
private:
};

class cMyVideosGenreLinkValues
{
public:
	cMyVideosGenreLinkValues();
	cMyVideosGenreLinkValues(cMyVideosGenre* lpGenre);

	void			set(cMyVideosGenre* lpGenre);

	inline bool	operator==(const cMyVideosGenreLinkValues b) const;
	inline bool	operator!=(const cMyVideosGenreLinkValues b) const;

	cMyVideosGenre*	m_lpGenre;
};

class cMyVideosGenreLink
{
public:
	cMyVideosGenreLink(cMyVideosGenre* lpGenre);

	cMyVideosGenre*	genre();

	bool			isNew();
	bool			isChanged();

	cMyVideosGenreLinkValues	m_values;
	cMyVideosGenreLinkValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosGenreLink*)

class cMyVideosGenreLinkList : public QList<cMyVideosGenreLink*>
{
public:
	cMyVideosGenreLinkList();
	cMyVideosGenreLink *add(cMyVideosGenre* lpGenre);
};

class cMyVideosStudioValues
{
public:
	cMyVideosStudioValues();
	cMyVideosStudioValues(qint32 studioID, const QString& szName);

	void			set(qint32 studioID, const QString& szName);

	inline bool	operator==(const cMyVideosStudioValues b) const;
	inline bool	operator!=(const cMyVideosStudioValues b) const;

	qint32			m_studioID;
	QString			m_szName;
};

class cMyVideosStudio
{
public:
	cMyVideosStudio(qint32 actorID, const QString& szName);

	qint32			studioID();
	QString			name();

	bool			isNew();
	bool			isChanged();

	cMyVideosStudioValues	m_values;
	cMyVideosStudioValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosStudio*)

class cMyVideosStudioList : public QList<cMyVideosStudio*>
{
public:
	cMyVideosStudioList();
	cMyVideosStudio*	add(qint32 studioID, const QString& szName);
	cMyVideosStudio*	find(qint32 studioID);
private:
};

class cMyVideosStudioLinkValues
{
public:
	cMyVideosStudioLinkValues();
	cMyVideosStudioLinkValues(cMyVideosStudio* lpStudio);

	void			set(cMyVideosStudio* lpStudio);

	inline bool	operator==(const cMyVideosStudioLinkValues b) const;
	inline bool	operator!=(const cMyVideosStudioLinkValues b) const;

	cMyVideosStudio*	m_lpStudio;
};

class cMyVideosStudioLink
{
public:
	cMyVideosStudioLink(cMyVideosStudio* lpStudio);

	cMyVideosStudio*	studio();

	bool			isNew();
	bool			isChanged();

	cMyVideosStudioLinkValues	m_values;
	cMyVideosStudioLinkValues	m_oValues;
};

Q_DECLARE_METATYPE(cMyVideosStudioLink*)

class cMyVideosStudioLinkList : public QList<cMyVideosStudioLink*>
{
public:
	cMyVideosStudioLinkList();
	cMyVideosStudioLink *add(cMyVideosStudio* lpStudio);
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
	cMyVideosCountryLinkList	m_countries;
	cMyVideosGenreLinkList		m_genres;
	cMyVideosStudioLinkList		m_studios;
	cMyVideosStreamDetailsVideoList		m_streamVideo;
	cMyVideosStreamDetailsAudioList		m_streamAudio;
	cMyVideosStreamDetailsSubtitleList	m_streamSubtitle;
	qint32		m_iVideoDuration;
};

class cMyVideos
{
public:
	cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			  const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			  const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			  const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			  const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 idSet, qint32 iUserrating, const QString& szSet, const QString& szSetOverview,
			  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	void			loadActors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	void			loadDirectors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	void			loadWriters(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	void			loadCountries(QSqlDatabase& m_db, cMyVideosCountryList videosCountryList);
	void			loadGenres(QSqlDatabase& m_db, cMyVideosGenreList videosGenreList);
	void			loadStudios(QSqlDatabase& m_db, cMyVideosStudioList videosStudioList);
	void			loadVideoStream(QSqlDatabase& m_db);
	void			loadAudioStream(QSqlDatabase& m_db);
	void			loadSubtitleStream(QSqlDatabase& m_db);

	void			fillActorsList(QStandardItemModel *lpView);
	void			fillDirectorsList(QStandardItemModel *lpView);
	void			fillWritersList(QStandardItemModel *lpView);
	void			fillCountriesList(QStandardItemModel* lpView);
	void			fillGenresList(QStandardItemModel* lpView);
	void			fillStudiosList(QStandardItemModel* lpView);
	void			fillVideoStreamList(QStandardItemModel* lpView);
	void			fillAudioStreamList(QStandardItemModel* lpView);
	void			fillSubtitleStreamList(QStandardItemModel* lpView);

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
