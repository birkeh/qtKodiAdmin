#ifndef CMYVIDEOS_H
#define CMYVIDEOS_H


#include <QString>
#include <QDateTime>
#include <QList>
#include <QMetaType>

#include <QSqlDatabase>
#include <QStandardItemModel>


/*!
 \brief

 \class tagSTRING2 cmyvideos.h "cmyvideos.h"
*/
typedef struct tagSTRING2
{
	QString	_1; /*!< TODO: describe */
	QString	_2; /*!< TODO: describe */
/*!
 \brief

 \typedef STRING2*/
}	STRING2;

/*!
 \brief

 \class cMyVideosSetValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosSetValues
{
public:
	cMyVideosSetValues();
	/*!
	 \brief

	 \fn cMyVideosSetValues
	 \param idSet
	 \param strSet
	 \param strOverview
	*/
	cMyVideosSetValues(qint32 idSet, const QString& strSet, const QString& strOverview);

	/*!
	 \brief

	 \fn set
	 \param idSet
	 \param strSet
	 \param strOverview
	*/
	void				set(qint32 idSet, const QString& strSet, const QString& strOverview);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosSetValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosSetValues b) const;

	qint32				m_idSet; /*!< TODO: describe */
	QString				m_strSet; /*!< TODO: describe */
	QString				m_strOverview; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosSet cmyvideos.h "cmyvideos.h"
*/
class cMyVideosSet
{
public:
	cMyVideosSet(qint32 idSet, const QString& strSet, const QString& strOverview);

	/*!
	 \brief

	 \fn idSet
	 \return qint32
	*/
	qint32			idSet();
	/*!
	 \brief

	 \fn strSet
	 \return QString
	*/
	QString			strSet();
	/*!
	 \brief
	 \fn strOverview
	 \return QString
	*/
	QString			strOverview();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosSetValues	m_values; /*!< TODO: describe */
	cMyVideosSetValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosSet*)

/*!
 \brief

 \class cMyVideosSetList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosSetList : public QList<cMyVideosSet*>
{
public:
	cMyVideosSetList();
	/*!
	 \brief

	 \fn add
	 \param idSet
	 \param strSet
	 \param strOverview
	 \return cMyVideosSet
	*/
	cMyVideosSet*	add(qint32 idSet, const QString& strSet, const QString& strOverview);
	/*!
	 \brief

	 \fn get
	 \param idSet
	 \return cMyVideosSet
	*/
	cMyVideosSet*	get(qint32 idSet);
private:
};

/*!
 \brief

 \class cMyVideosStreamDetailsVideoValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsVideoValues
{
public:
	cMyVideosStreamDetailsVideoValues();
	/*!
	 \brief

	 \fn cMyVideosStreamDetailsVideoValues
	 \param szVideoCodec
	 \param dAspectRatio
	 \param iWidth
	 \param iHeight
	*/
	cMyVideosStreamDetailsVideoValues(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);

	/*!
	 \brief

	 \fn set
	 \param szVideoCodec
	 \param dAspectRatio
	 \param iWidth
	 \param iHeight
	*/
	void				set(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosStreamDetailsVideoValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosStreamDetailsVideoValues b) const;

	QString				m_szVideoCodec; /*!< TODO: describe */
	qreal				m_dAspectRatio; /*!< TODO: describe */
	qint32				m_iWidth; /*!< TODO: describe */
	qint32				m_iHeight; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosStreamDetailsAudioValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsAudioValues
{
public:
	cMyVideosStreamDetailsAudioValues();
	/*!
	 \brief

	 \fn cMyVideosStreamDetailsAudioValues
	 \param szAudioCodec
	 \param iAudioChannels
	 \param szAudioLanguage
	 \param szStereoMode
	*/
	cMyVideosStreamDetailsAudioValues(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);

	/*!
	 \brief

	 \fn set
	 \param szAudioCodec
	 \param iAudioChannels
	 \param szAudioLanguage
	 \param szStereoMode
	*/
	void				set(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosStreamDetailsAudioValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosStreamDetailsAudioValues b) const;

	QString				m_szAudioCodec; /*!< TODO: describe */
	qint32				m_iAudioChannels; /*!< TODO: describe */
	QString				m_szAudioLanguage; /*!< TODO: describe */
	QString				m_szStereoMode; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosStreamDetailsSubtitleValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsSubtitleValues
{
public:
	cMyVideosStreamDetailsSubtitleValues();
	/*!
	 \brief

	 \fn cMyVideosStreamDetailsSubtitleValues
	 \param szSubtitleLanguage
	*/
	cMyVideosStreamDetailsSubtitleValues(const QString& szSubtitleLanguage);

	/*!
	 \brief

	 \fn set
	 \param szSubtitleLanguage
	*/
	void				set(const QString& szSubtitleLanguage);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosStreamDetailsSubtitleValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosStreamDetailsSubtitleValues b) const;

	QString				m_szSubtitleLanguage; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosStreamDetailsVideo cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsVideo
{
public:
	cMyVideosStreamDetailsVideo(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);

	/*!
	 \brief

	 \fn videoCodec
	 \return QString
	*/
	QString			videoCodec();
	/*!
	 \brief

	 \fn aspectRatio
	 \return qreal
	*/
	qreal			aspectRatio();
	/*!
	 \brief

	 \fn width
	 \return qint32
	*/
	qint32			width();
	/*!
	 \brief

	 \fn height
	 \return qint32
	*/
	qint32			height();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosStreamDetailsVideoValues	m_values; /*!< TODO: describe */
	cMyVideosStreamDetailsVideoValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosStreamDetailsVideo*)

/*!
 \brief

 \class cMyVideosStreamDetailsVideoList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsVideoList : public QList<cMyVideosStreamDetailsVideo*>
{
public:
	cMyVideosStreamDetailsVideoList();
	/*!
	 \brief

	 \fn add
	 \param szVideoCodec
	 \param dAspectRatio
	 \param iWidth
	 \param iHeight
	 \return cMyVideosStreamDetailsVideo
	*/
	cMyVideosStreamDetailsVideo*	add(const QString& szVideoCodec, qreal dAspectRatio, qint32 iWidth, qint32 iHeight);
private:
};

/*!
 \brief

 \class cMyVideosStreamDetailsAudio cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsAudio
{
public:
	cMyVideosStreamDetailsAudio(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);

	/*!
	 \brief

	 \fn audioCodec
	 \return QString
	*/
	QString			audioCodec();
	/*!
	 \brief

	 \fn audioChannels
	 \return qint32
	*/
	qint32			audioChannels();
	/*!
	 \brief

	 \fn audioLanguage
	 \return QString
	*/
	QString			audioLanguage();
	/*!
	 \brief

	 \fn stereoMode
	 \return QString
	*/
	QString			stereoMode();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosStreamDetailsAudioValues	m_values; /*!< TODO: describe */
	cMyVideosStreamDetailsAudioValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosStreamDetailsAudio*)

/*!
 \brief

 \class cMyVideosStreamDetailsAudioList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsAudioList : public QList<cMyVideosStreamDetailsAudio*>
{
public:
	cMyVideosStreamDetailsAudioList();
	/*!
	 \brief

	 \fn add
	 \param szAudioCodec
	 \param iAudioChannels
	 \param szAudioLanguage
	 \param szStereoMode
	 \return cMyVideosStreamDetailsAudio
	*/
	cMyVideosStreamDetailsAudio*	add(const QString& szAudioCodec, qint32 iAudioChannels, const QString& szAudioLanguage, const QString& szStereoMode);
private:
};

/*!
 \brief

 \class cMyVideosStreamDetailsSubtitle cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsSubtitle
{
public:
	cMyVideosStreamDetailsSubtitle(const QString& szSubtitleLanguage);

	/*!
	 \brief

	 \fn subtitleLanguage
	 \return QString
	*/
	QString			subtitleLanguage();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosStreamDetailsSubtitleValues	m_values; /*!< TODO: describe */
	cMyVideosStreamDetailsSubtitleValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosStreamDetailsSubtitle*)

/*!
 \brief

 \class cMyVideosStreamDetailsSubtitleList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStreamDetailsSubtitleList : public QList<cMyVideosStreamDetailsSubtitle*>
{
public:
	cMyVideosStreamDetailsSubtitleList();
	/*!
	 \brief

	 \fn add
	 \param szSubtitleLanguage
	 \return cMyVideosStreamDetailsSubtitle
	*/
	cMyVideosStreamDetailsSubtitle*	add(const QString& szSubtitleLanguage);
private:
};

/*!
 \brief

 \class cMyVideosActorValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosActorValues
{
public:
	cMyVideosActorValues();
	/*!
	 \brief

	 \fn cMyVideosActorValues
	 \param actorID
	 \param szName
	 \param szArtURLs
	*/
	cMyVideosActorValues(qint32 actorID, const QString& szName, const QString& szArtURLs);

	/*!
	 \brief

	 \fn set
	 \param actorID
	 \param szName
	 \param szArtURLs
	*/
	void			set(qint32 actorID, const QString& szName, const QString& szArtURLs);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosActorValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosActorValues b) const;

	qint32			m_actorID; /*!< TODO: describe */
	QString			m_szName; /*!< TODO: describe */
	QString			m_szArtURLs; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosActor cmyvideos.h "cmyvideos.h"
*/
class cMyVideosActor
{
public:
	cMyVideosActor(qint32 actorID, const QString& szName, const QString& szArtUrls);

	/*!
	 \brief

	 \fn actorID
	 \return qint32
	*/
	qint32			actorID();
	/*!
	 \brief

	 \fn name
	 \return QString
	*/
	QString			name();
	/*!
	 \brief
	 \fn szArtURLs
	 \return QString
	*/
	QString			szArtURLs();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();
private:
	cMyVideosActorValues	m_values; /*!< TODO: describe */
	cMyVideosActorValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosActor*)

/*!
 \brief

 \class cMyVideosActorList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosActorList : public QList<cMyVideosActor*>
{
public:
	cMyVideosActorList();
	/*!
	 \brief

	 \fn add
	 \param actorID
	 \param szName
	 \param szArtURLs
	 \return cMyVideosActor
	*/
	cMyVideosActor*	add(qint32 actorID, const QString& szName, const QString& szArtURLs);
	/*!
	 \brief

	 \fn find
	 \param actorID
	 \return cMyVideosActor
	*/
	cMyVideosActor*	find(qint32 actorID);
private:
};

/*!
 \brief

 \class cMyVideosActorLinkValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosActorLinkValues
{
public:
	cMyVideosActorLinkValues();
	/*!
	 \brief

	 \fn cMyVideosActorLinkValues
	 \param lpActor
	 \param szRole
	 \param castOrder
	*/
	cMyVideosActorLinkValues(cMyVideosActor* lpActor, const QString& szRole, qint32 castOrder);

	/*!
	 \brief

	 \fn set
	 \param lpActor
	 \param szRole
	 \param castOrder
	*/
	void			set(cMyVideosActor* lpActor, const QString& szRole, qint32 castOrder);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosActorLinkValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosActorLinkValues b) const;

	cMyVideosActor*	m_lpActor; /*!< TODO: describe */
	QString			m_szRole; /*!< TODO: describe */
	qint32			m_castOrder; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosActorLink cmyvideos.h "cmyvideos.h"
*/
class cMyVideosActorLink
{
public:
	cMyVideosActorLink(cMyVideosActor* lpActor, const QString& szRole, qint32 cast_order);

	/*!
	 \brief

	 \fn actor
	 \return cMyVideosActor
	*/
	cMyVideosActor*	actor();
	/*!
	 \brief

	 \fn role
	 \return QString
	*/
	QString			role();
	/*!
	 \brief
	 \fn castOrder
	 \return qint32
	*/
	qint32			castOrder();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosActorLinkValues	m_values; /*!< TODO: describe */
	cMyVideosActorLinkValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosActorLink*)

/*!
 \brief

 \class cMyVideosActorLinkList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosActorLinkList : public QList<cMyVideosActorLink*>
{
public:
	cMyVideosActorLinkList();
	/*!
	 \brief

	 \fn add
	 \param lpActor
	 \param szRole
	 \param cast_order
	 \return cMyVideosActorLink
	*/
	cMyVideosActorLink *add(cMyVideosActor* lpActor, const QString& szRole, qint32 cast_order);
};

/*!
 \brief

 \class cMyVideosWriterLinkValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosWriterLinkValues
{
public:
	cMyVideosWriterLinkValues();
	/*!
	 \brief

	 \fn cMyVideosWriterLinkValues
	 \param lpActor
	*/
	cMyVideosWriterLinkValues(cMyVideosActor* lpActor);

	/*!
	 \brief

	 \fn set
	 \param lpActor
	*/
	void			set(cMyVideosActor* lpActor);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosWriterLinkValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosWriterLinkValues b) const;

	cMyVideosActor*	m_lpActor; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosWriterLink cmyvideos.h "cmyvideos.h"
*/
class cMyVideosWriterLink
{
public:
	cMyVideosWriterLink(cMyVideosActor* lpActor);

	/*!
	 \brief

	 \fn actor
	 \return cMyVideosActor
	*/
	cMyVideosActor*	actor();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosWriterLinkValues	m_values; /*!< TODO: describe */
	cMyVideosWriterLinkValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosWriterLink*)

/*!
 \brief

 \class cMyVideosWriterLinkList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosWriterLinkList : public QList<cMyVideosWriterLink*>
{
public:
	cMyVideosWriterLinkList();
	/*!
	 \brief

	 \fn add
	 \param lpActor
	 \return cMyVideosWriterLink
	*/
	cMyVideosWriterLink *add(cMyVideosActor* lpActor);
};

/*!
 \brief

 \class cMyVideosDirectorLinkValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosDirectorLinkValues
{
public:
	cMyVideosDirectorLinkValues();
	/*!
	 \brief

	 \fn cMyVideosDirectorLinkValues
	 \param lpActor
	*/
	cMyVideosDirectorLinkValues(cMyVideosActor* lpActor);

	/*!
	 \brief

	 \fn set
	 \param lpActor
	*/
	void			set(cMyVideosActor* lpActor);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosDirectorLinkValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosDirectorLinkValues b) const;

	cMyVideosActor*	m_lpActor; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosDirectorLink cmyvideos.h "cmyvideos.h"
*/
class cMyVideosDirectorLink
{
public:
	cMyVideosDirectorLink(cMyVideosActor* lpActor);

	/*!
	 \brief

	 \fn actor
	 \return cMyVideosActor
	*/
	cMyVideosActor*	actor();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosDirectorLinkValues	m_values; /*!< TODO: describe */
	cMyVideosDirectorLinkValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosDirectorLink*)

/*!
 \brief

 \class cMyVideosDirectorLinkList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosDirectorLinkList : public QList<cMyVideosDirectorLink*>
{
public:
	cMyVideosDirectorLinkList();
	/*!
	 \brief

	 \fn add
	 \param lpActor
	 \return cMyVideosDirectorLink
	*/
	cMyVideosDirectorLink *add(cMyVideosActor* lpActor);
};

/*!
 \brief

 \class cMyVideosCountryValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosCountryValues
{
public:
	cMyVideosCountryValues();
	/*!
	 \brief

	 \fn cMyVideosCountryValues
	 \param countryID
	 \param szName
	*/
	cMyVideosCountryValues(qint32 countryID, const QString& szName);

	/*!
	 \brief

	 \fn set
	 \param countryID
	 \param szName
	*/
	void			set(qint32 countryID, const QString& szName);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosCountryValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosCountryValues b) const;

	qint32			m_countryID; /*!< TODO: describe */
	QString			m_szName; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosCountry cmyvideos.h "cmyvideos.h"
*/
class cMyVideosCountry
{
public:
	cMyVideosCountry(qint32 countryID, const QString& szName);

	/*!
	 \brief

	 \fn countryID
	 \return qint32
	*/
	qint32			countryID();
	/*!
	 \brief

	 \fn name
	 \return QString
	*/
	QString			name();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosCountryValues	m_values; /*!< TODO: describe */
	cMyVideosCountryValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosCountry*)

/*!
 \brief

 \class cMyVideosCountryList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosCountryList : public QList<cMyVideosCountry*>
{
public:
	cMyVideosCountryList();
	/*!
	 \brief

	 \fn add
	 \param countryID
	 \param szName
	 \return cMyVideosCountry
	*/
	cMyVideosCountry*	add(qint32 countryID, const QString& szName);
	/*!
	 \brief

	 \fn find
	 \param countryID
	 \return cMyVideosCountry
	*/
	cMyVideosCountry*	find(qint32 countryID);
private:
};

/*!
 \brief

 \class cMyVideosCountryLinkValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosCountryLinkValues
{
public:
	cMyVideosCountryLinkValues();
	/*!
	 \brief

	 \fn cMyVideosCountryLinkValues
	 \param lpCountry
	*/
	cMyVideosCountryLinkValues(cMyVideosCountry* lpCountry);

	/*!
	 \brief

	 \fn set
	 \param lpCountry
	*/
	void			set(cMyVideosCountry* lpCountry);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosCountryLinkValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosCountryLinkValues b) const;

	cMyVideosCountry*	m_lpCountry; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosCountryLink cmyvideos.h "cmyvideos.h"
*/
class cMyVideosCountryLink
{
public:
	cMyVideosCountryLink(cMyVideosCountry* lpCountry);

	/*!
	 \brief

	 \fn country
	 \return cMyVideosCountry
	*/
	cMyVideosCountry*	country();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosCountryLinkValues	m_values; /*!< TODO: describe */
	cMyVideosCountryLinkValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosCountryLink*)

/*!
 \brief

 \class cMyVideosCountryLinkList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosCountryLinkList : public QList<cMyVideosCountryLink*>
{
public:
	cMyVideosCountryLinkList();
	/*!
	 \brief

	 \fn add
	 \param lpCountry
	 \return cMyVideosCountryLink
	*/
	cMyVideosCountryLink *add(cMyVideosCountry* lpCountry);
};

/*!
 \brief

 \class cMyVideosGenreValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosGenreValues
{
public:
	cMyVideosGenreValues();
	/*!
	 \brief

	 \fn cMyVideosGenreValues
	 \param genreID
	 \param szName
	*/
	cMyVideosGenreValues(qint32 genreID, const QString& szName);

	/*!
	 \brief

	 \fn set
	 \param genreID
	 \param szName
	*/
	void			set(qint32 genreID, const QString& szName);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosGenreValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosGenreValues b) const;

	qint32			m_genreID; /*!< TODO: describe */
	QString			m_szName; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosGenre cmyvideos.h "cmyvideos.h"
*/
class cMyVideosGenre
{
public:
	cMyVideosGenre(qint32 genreID, const QString& szName);

	/*!
	 \brief

	 \fn genreID
	 \return qint32
	*/
	qint32			genreID();
	/*!
	 \brief

	 \fn name
	 \return QString
	*/
	QString			name();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosGenreValues	m_values; /*!< TODO: describe */
	cMyVideosGenreValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosGenre*)

/*!
 \brief

 \class cMyVideosGenreList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosGenreList : public QList<cMyVideosGenre*>
{
public:
	cMyVideosGenreList();
	/*!
	 \brief

	 \fn add
	 \param genreID
	 \param szName
	 \return cMyVideosGenre
	*/
	cMyVideosGenre*	add(qint32 genreID, const QString& szName);
	/*!
	 \brief

	 \fn find
	 \param genreID
	 \return cMyVideosGenre
	*/
	cMyVideosGenre*	find(qint32 genreID);
private:
};

/*!
 \brief

 \class cMyVideosGenreLinkValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosGenreLinkValues
{
public:
	cMyVideosGenreLinkValues();
	/*!
	 \brief

	 \fn cMyVideosGenreLinkValues
	 \param lpGenre
	*/
	cMyVideosGenreLinkValues(cMyVideosGenre* lpGenre);

	/*!
	 \brief

	 \fn set
	 \param lpGenre
	*/
	void			set(cMyVideosGenre* lpGenre);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosGenreLinkValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosGenreLinkValues b) const;

	cMyVideosGenre*	m_lpGenre; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosGenreLink cmyvideos.h "cmyvideos.h"
*/
class cMyVideosGenreLink
{
public:
	cMyVideosGenreLink(cMyVideosGenre* lpGenre);

	/*!
	 \brief

	 \fn genre
	 \return cMyVideosGenre
	*/
	cMyVideosGenre*	genre();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosGenreLinkValues	m_values; /*!< TODO: describe */
	cMyVideosGenreLinkValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosGenreLink*)

/*!
 \brief

 \class cMyVideosGenreLinkList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosGenreLinkList : public QList<cMyVideosGenreLink*>
{
public:
	cMyVideosGenreLinkList();
	/*!
	 \brief

	 \fn add
	 \param lpGenre
	 \return cMyVideosGenreLink
	*/
	cMyVideosGenreLink *add(cMyVideosGenre* lpGenre);
};

/*!
 \brief

 \class cMyVideosStudioValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStudioValues
{
public:
	cMyVideosStudioValues();
	/*!
	 \brief

	 \fn cMyVideosStudioValues
	 \param studioID
	 \param szName
	*/
	cMyVideosStudioValues(qint32 studioID, const QString& szName);

	/*!
	 \brief

	 \fn set
	 \param studioID
	 \param szName
	*/
	void			set(qint32 studioID, const QString& szName);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosStudioValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosStudioValues b) const;

	qint32			m_studioID; /*!< TODO: describe */
	QString			m_szName; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosStudio cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStudio
{
public:
	cMyVideosStudio(qint32 actorID, const QString& szName);

	/*!
	 \brief

	 \fn studioID
	 \return qint32
	*/
	qint32			studioID();
	/*!
	 \brief

	 \fn name
	 \return QString
	*/
	QString			name();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosStudioValues	m_values; /*!< TODO: describe */
	cMyVideosStudioValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosStudio*)

/*!
 \brief

 \class cMyVideosStudioList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStudioList : public QList<cMyVideosStudio*>
{
public:
	cMyVideosStudioList();
	/*!
	 \brief

	 \fn add
	 \param studioID
	 \param szName
	 \return cMyVideosStudio
	*/
	cMyVideosStudio*	add(qint32 studioID, const QString& szName);
	/*!
	 \brief

	 \fn find
	 \param studioID
	 \return cMyVideosStudio
	*/
	cMyVideosStudio*	find(qint32 studioID);
private:
};

/*!
 \brief

 \class cMyVideosStudioLinkValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStudioLinkValues
{
public:
	cMyVideosStudioLinkValues();
	/*!
	 \brief

	 \fn cMyVideosStudioLinkValues
	 \param lpStudio
	*/
	cMyVideosStudioLinkValues(cMyVideosStudio* lpStudio);

	/*!
	 \brief

	 \fn set
	 \param lpStudio
	*/
	void			set(cMyVideosStudio* lpStudio);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosStudioLinkValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosStudioLinkValues b) const;

	cMyVideosStudio*	m_lpStudio; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideosStudioLink cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStudioLink
{
public:
	cMyVideosStudioLink(cMyVideosStudio* lpStudio);

	/*!
	 \brief

	 \fn studio
	 \return cMyVideosStudio
	*/
	cMyVideosStudio*	studio();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosStudioLinkValues	m_values; /*!< TODO: describe */
	cMyVideosStudioLinkValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideosStudioLink*)

/*!
 \brief

 \class cMyVideosStudioLinkList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosStudioLinkList : public QList<cMyVideosStudioLink*>
{
public:
	cMyVideosStudioLinkList();
	/*!
	 \brief

	 \fn add
	 \param lpStudio
	 \return cMyVideosStudioLink
	*/
	cMyVideosStudioLink *add(cMyVideosStudio* lpStudio);
};

/*!
 \brief

 \class cMyVideosValues cmyvideos.h "cmyvideos.h"
*/
class cMyVideosValues
{
public:
	cMyVideosValues();
	/*!
	 \brief

	 \fn cMyVideosValues
	 \param idMovie
	 \param idFile
	 \param szLocalMovieTitle
	 \param szMoviePlot
	 \param szMoviePlotOutline
	 \param szMovieTagline
	 \param iRatingVotes
	 \param dRating
	 \param szWriters
	 \param iYearReleased
	 \param szThumbnails
	 \param szIMDBID
	 \param szTitleFormattedForSorting
	 \param iRuntime
	 \param szMPAARating
	 \param iIMDBTop250Ranking
	 \param szGenre
	 \param szDirector
	 \param szOriginalMovieTitle
	 \param szStudio
	 \param szTrailerURL
	 \param szFanartURLs
	 \param szCountry
	 \param szFilePath
	 \param idPath
	 \param iUserrating
	 \param szFileName
	 \param szPathURL
	 \param iPlayCount
	 \param lastPlayed
	 \param dateAdded
	 \param dResumeTimeInSeconds
	 \param dTotalTimeInSeconds
	 \param lpSet
	*/
	cMyVideosValues(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
				const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
				const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
				const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
				const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
				const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
				const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
				qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet);

	/*!
	 \brief

	 \fn set
	 \param idMovie
	 \param idFile
	 \param szLocalMovieTitle
	 \param szMoviePlot
	 \param szMoviePlotOutline
	 \param szMovieTagline
	 \param iRatingVotes
	 \param dRating
	 \param szWriters
	 \param iYearReleased
	 \param szThumbnails
	 \param szIMDBID
	 \param szTitleFormattedForSorting
	 \param iRuntime
	 \param szMPAARating
	 \param iIMDBTop250Ranking
	 \param szGenre
	 \param szDirector
	 \param szOriginalMovieTitle
	 \param szStudio
	 \param szTrailerURL
	 \param szFanartURLs
	 \param szCountry
	 \param szFilePath
	 \param idPath
	 \param iUserrating
	 \param szFileName
	 \param szPathURL
	 \param iPlayCount
	 \param lastPlayed
	 \param dateAdded
	 \param dResumeTimeInSeconds
	 \param dTotalTimeInSeconds
	 \param lpSet
	*/
	void		set(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
				const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
				const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
				const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
				const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
				const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
				const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
				qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyVideosValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyVideosValues b) const;

	qint32		m_idMovie; /*!< TODO: describe */
	qint32		m_idFile; /*!< TODO: describe */
	QString		m_szLocalMovieTitle;					// c00 /*!< TODO: describe */
	QString		m_szMoviePlot;							// c01 /*!< TODO: describe */
	QString		m_szMoviePlotOutline;					// c02 /*!< TODO: describe */
	QString		m_szMovieTagline;						// c03 /*!< TODO: describe */
	qint32		m_iRatingVotes;							// c04 /*!< TODO: describe */
	qreal		m_dRating;								// c05 /*!< TODO: describe */
	QString		m_szWriters;							// c06 /*!< TODO: describe */
	qint32		m_iYearReleased;						// c07 /*!< TODO: describe */
	QString		m_szThumbnails;							// c08 (Selection List) /*!< TODO: describe */
	QString		m_szIMDBID;								// c09 /*!< TODO: describe */
	QString		m_szTitleFormattedForSorting;			// c10 /*!< TODO: describe */
	qint32		m_iRuntime;								// c11 /*!< TODO: describe */
	QString		m_szMPAARating;							// c12 /*!< TODO: describe */
	qint32		m_iIMDBTop250Ranking;					// c13 /*!< TODO: describe */
	QString		m_szGenre;								// c14 /*!< TODO: describe */
	QString		m_szDirector;							// c15 /*!< TODO: describe */
	QString		m_szOriginalMovieTitle;					// c16 /*!< TODO: describe */
	QString		m_szStudio;								// c18 /*!< TODO: describe */
	QString		m_szTrailerURL;							// c19 /*!< TODO: describe */
	QString		m_szFanartURLs;							// c20 (Selection List) /*!< TODO: describe */
	QString		m_szCountry;							// c21 /*!< TODO: describe */
	QString		m_szFilePath;							// c22 /*!< TODO: describe */
	qint32		m_idPath;								// c23 /*!< TODO: describe */
	qint32		m_iUserrating;							// userrating /*!< TODO: describe */
	QString		m_szFileName;							// strFileName /*!< TODO: describe */
	QString		m_szPathURL;							// strPath /*!< TODO: describe */
	qint32		m_iPlayCount;							// playCount /*!< TODO: describe */
	QDateTime	m_lastPlayed;							// lastPlayed /*!< TODO: describe */
	QDateTime	m_dateAdded;							// dateAdded /*!< TODO: describe */
	qreal		m_dResumeTimeInSeconds;					// resumeTimeInSeconds /*!< TODO: describe */
	qreal		m_dTotalTimeInSeconds;					// totalTimeInSeconds /*!< TODO: describe */
	cMyVideosSet*	m_lpSet; /*!< TODO: describe */

	cMyVideosActorLinkList		m_actors; /*!< TODO: describe */
	cMyVideosDirectorLinkList	m_directors; /*!< TODO: describe */
	cMyVideosWriterLinkList		m_writers; /*!< TODO: describe */
	cMyVideosCountryLinkList	m_countries; /*!< TODO: describe */
	cMyVideosGenreLinkList		m_genres; /*!< TODO: describe */
	cMyVideosStudioLinkList		m_studios; /*!< TODO: describe */
	cMyVideosStreamDetailsVideoList		m_streamVideo; /*!< TODO: describe */
	cMyVideosStreamDetailsAudioList		m_streamAudio; /*!< TODO: describe */
	cMyVideosStreamDetailsSubtitleList	m_streamSubtitle; /*!< TODO: describe */
	qint32		m_iVideoDuration; /*!< TODO: describe */
};

/*!
 \brief

 \class cMyVideos cmyvideos.h "cmyvideos.h"
*/
class cMyVideos
{
public:
	cMyVideos(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
			  const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
			  const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
			  const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
			  const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
			  const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
			  const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			  qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet);

	/*!
	 \brief

	 \fn loadActors
	 \param m_db
	 \param videosActorList
	*/
	void			loadActors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	/*!
	 \brief

	 \fn loadDirectors
	 \param m_db
	 \param videosActorList
	*/
	void			loadDirectors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	/*!
	 \brief

	 \fn loadWriters
	 \param m_db
	 \param videosActorList
	*/
	void			loadWriters(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	/*!
	 \brief

	 \fn loadCountries
	 \param m_db
	 \param videosCountryList
	*/
	void			loadCountries(QSqlDatabase& m_db, cMyVideosCountryList videosCountryList);
	/*!
	 \brief

	 \fn loadGenres
	 \param m_db
	 \param videosGenreList
	*/
	void			loadGenres(QSqlDatabase& m_db, cMyVideosGenreList videosGenreList);
	/*!
	 \brief

	 \fn loadStudios
	 \param m_db
	 \param videosStudioList
	*/
	void			loadStudios(QSqlDatabase& m_db, cMyVideosStudioList videosStudioList);
	/*!
	 \brief

	 \fn loadVideoStream
	 \param m_db
	*/
	void			loadVideoStream(QSqlDatabase& m_db);
	/*!
	 \brief

	 \fn loadAudioStream
	 \param m_db
	*/
	void			loadAudioStream(QSqlDatabase& m_db);
	/*!
	 \brief

	 \fn loadSubtitleStream
	 \param m_db
	*/
	void			loadSubtitleStream(QSqlDatabase& m_db);

	/*!
	 \brief

	 \fn fillActorsList
	 \param lpView
	*/
	void			fillActorsList(QStandardItemModel *lpView);
	/*!
	 \brief

	 \fn fillDirectorsList
	 \param lpView
	*/
	void			fillDirectorsList(QStandardItemModel *lpView);
	/*!
	 \brief

	 \fn fillWritersList
	 \param lpView
	*/
	void			fillWritersList(QStandardItemModel *lpView);
	/*!
	 \brief

	 \fn fillCountriesList
	 \param lpView
	*/
	void			fillCountriesList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillGenresList
	 \param lpView
	*/
	void			fillGenresList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillStudiosList
	 \param lpView
	*/
	void			fillStudiosList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillVideoStreamList
	 \param lpView
	*/
	void			fillVideoStreamList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillAudioStreamList
	 \param lpView
	*/
	void			fillAudioStreamList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillSubtitleStreamList
	 \param lpView
	*/
	void			fillSubtitleStreamList(QStandardItemModel* lpView);

	/*!
	 \brief

	 \fn idMovie
	 \return qint32
	*/
	qint32			idMovie();
	/*!
	 \brief

	 \fn idFile
	 \return qint32
	*/
	qint32			idFile();
	/*!
	 \brief

	 \fn localMovieTitle
	 \return QString
	*/
	QString			localMovieTitle();
	/*!
	 \brief

	 \fn moviePlot
	 \return QString
	*/
	QString			moviePlot();
	/*!
	 \brief

	 \fn moviePlotOutline
	 \return QString
	*/
	QString			moviePlotOutline();
	/*!
	 \brief

	 \fn movieTagline
	 \return QString
	*/
	QString			movieTagline();
	/*!
	 \brief

	 \fn ratingVotes
	 \return qint32
	*/
	qint32			ratingVotes();
	/*!
	 \brief

	 \fn rating
	 \return qreal
	*/
	qreal			rating();
	/*!
	 \brief

	 \fn writers
	 \return QStringList
	*/
	QStringList		writers();
	/*!
	 \brief

	 \fn yearReleased
	 \return qint32
	*/
	qint32			yearReleased();
	/*!
	 \brief

	 \fn thumbnails
	 \return QList<STRING2>
	*/
	QList<STRING2>	thumbnails();
	/*!
	 \brief

	 \fn imdbID
	 \return QString
	*/
	QString			imdbID();
	/*!
	 \brief

	 \fn titleFormattedForSorting
	 \return QString
	*/
	QString			titleFormattedForSorting();
	/*!
	 \brief

	 \fn runtime
	 \return qint32
	*/
	qint32			runtime();
	/*!
	 \brief

	 \fn mpaaRating
	 \return QString
	*/
	QString			mpaaRating();
	/*!
	 \brief

	 \fn imdbTop250Ranking
	 \return qint32
	*/
	qint32			imdbTop250Ranking();
	/*!
	 \brief

	 \fn genre
	 \return QStringList
	*/
	QStringList		genre();
	/*!
	 \brief

	 \fn director
	 \return QStringList
	*/
	QStringList		director();
	/*!
	 \brief

	 \fn originalMovieTitle
	 \return QString
	*/
	QString			originalMovieTitle();
	/*!
	 \brief

	 \fn studio
	 \return QStringList
	*/
	QStringList		studio();
	/*!
	 \brief

	 \fn trailerURL
	 \return QString
	*/
	QString			trailerURL();
	/*!
	 \brief

	 \fn fanartURL
	 \return QList<STRING2>
	*/
	QList<STRING2>	fanartURL();
	/*!
	 \brief

	 \fn country
	 \return QStringList
	*/
	QStringList		country();
	/*!
	 \brief

	 \fn filePath
	 \return QString
	*/
	QString			filePath();
	/*!
	 \brief

	 \fn userRating
	 \return qint32
	*/
	qint32			userRating();
	/*!
	 \brief

	 \fn fileName
	 \return QString
	*/
	QString			fileName();
	/*!
	 \brief

	 \fn pathURL
	 \return QString
	*/
	QString			pathURL();
	/*!
	 \brief

	 \fn playCount
	 \return qint32
	*/
	qint32			playCount();
	/*!
	 \brief

	 \fn lastPlayed
	 \return QDateTime
	*/
	QDateTime		lastPlayed();
	/*!
	 \brief

	 \fn dateAdded
	 \return QDateTime
	*/
	QDateTime		dateAdded();
	/*!
	 \brief

	 \fn resumeTimeInSeconds
	 \return qreal
	*/
	qreal			resumeTimeInSeconds();
	/*!
	 \brief

	 \fn totalTimeInSeconds
	 \return qreal
	*/
	qreal			totalTimeInSeconds();
	/*!
	 \brief

	 \fn strSet
	 \return QString
	*/
	QString			strSet();
	/*!
	 \brief

	 \fn set
	 \return cMyVideosSet
	*/
	cMyVideosSet*	set();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyVideosValues	m_values; /*!< TODO: describe */
	cMyVideosValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyVideos*)

/*!
 \brief

 \class cMyVideosList cmyvideos.h "cmyvideos.h"
*/
class cMyVideosList : public QList<cMyVideos*>
{
public:
	cMyVideosList();
	/*!
	 \brief

	 \fn add
	 \param idMovie
	 \param idFile
	 \param szLocalMovieTitle
	 \param szMoviePlot
	 \param szMoviePlotOutline
	 \param szMovieTagline
	 \param iRatingVotes
	 \param dRating
	 \param szWriters
	 \param iYearReleased
	 \param szThumbnails
	 \param szIMDBID
	 \param szTitleFormattedForSorting
	 \param iRuntime
	 \param szMPAARating
	 \param iIMDBTop250Ranking
	 \param szGenre
	 \param szDirector
	 \param szOriginalMovieTitle
	 \param szStudio
	 \param szTrailerURL
	 \param szFanartURLs
	 \param szCountry
	 \param szFilePath
	 \param idPath
	 \param iUserrating
	 \param szFileName
	 \param szPathURL
	 \param iPlayCount
	 \param lastPlayed
	 \param dateAdded
	 \param dResumeTimeInSeconds
	 \param dTotalTimeInSeconds
	 \param lpSet
	 \return cMyVideos
	*/
	cMyVideos*	add(qint32 idMovie, qint32 idFile, const QString& szLocalMovieTitle, const QString& szMoviePlot, const QString& szMoviePlotOutline,
					const QString& szMovieTagline, qint32 iRatingVotes, qreal dRating, const QString& szWriters, qint32 iYearReleased,
					const QString& szThumbnails, const QString& szIMDBID, const QString& szTitleFormattedForSorting, qint32 iRuntime,
					const QString& szMPAARating, qint32 iIMDBTop250Ranking, const QString& szGenre, const QString& szDirector,
					const QString& szOriginalMovieTitle, const QString& szStudio, const QString& szTrailerURL, const QString& szFanartURLs,
					const QString& szCountry, const QString& szFilePath, qint32 idPath, qint32 iUserrating,
					const QString& szFileName, const QString& szPathURL, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
					qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds, cMyVideosSet* lpSet);

private:
};

/*!
 \brief

 \class cMyTVShowsValues cmyvideos.h "cmyvideos.h"
*/
class cMyTVShowsValues
{
public:
	cMyTVShowsValues();
	/*!
	 \brief

	 \fn cMyTVShowsValues
	 \param idEpisode
	 \param idFile
	 \param szEpisodeTitle
	 \param szPlotSummary
	 \param dRating
	 \param szWriters
	 \param firstAired
	 \param szThumbnailUrl
	 \param iEpisodeLength
	 \param szDirector
	 \param iSeasonNumber
	 \param iEpisodeNumber
	 \param iSeasonFormattetForSorting
	 \param iEpisodeFormattedForSorting
	 \param iBookmark
	 \param szFullPath
	 \param idShow
	 \param iUserrating
	 \param idSeason
	 \param szFileName
	 \param szPath
	 \param iPlayCount
	 \param lastPlayed
	 \param dateAdded
	 \param szTitle
	 \param szGenre
	 \param szStudio
	 \param premiereDate
	 \param szMPAA
	 \param dResumeTimeInSeconds
	 \param dTotalTimeInSeconds
	*/
	cMyTVShowsValues(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
					 const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
					 qint32 iSeasonFormattetForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
					 qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
					 const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
					 qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	/*!
	 \brief

	 \fn set
	 \param idEpisode
	 \param idFile
	 \param szepisodeTitle
	 \param szPlotSummary
	 \param dRating
	 \param szWriters
	 \param firstAired
	 \param szThumbnailUrl
	 \param iEpisodeLength
	 \param szDirector
	 \param iSeasonNumber
	 \param iEpisodeNumber
	 \param iSeasonFormattedForSorting
	 \param iEpisodeFormattedForSorting
	 \param iBookmark
	 \param szFullPath
	 \param idShow
	 \param iUserrating
	 \param idSeason
	 \param szFileName
	 \param szPath
	 \param iPlayCount
	 \param lastPlayed
	 \param dateAdded
	 \param szTitle
	 \param szGenre
	 \param szStudio
	 \param premiereDate
	 \param szMPAA
	 \param dResumeTimeInSeconds
	 \param dTotalTimeInSeconds
	*/
	void		set(qint32 idEpisode, qint32 idFile, const QString& szepisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
				const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
				qint32 iSeasonFormattedForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
				qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
				const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
				qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	/*!
	 \brief

	 \fn operator ==
	 \param b
	 \return bool operator
	*/
	inline bool	operator==(const cMyTVShowsValues b) const;
	/*!
	 \brief

	 \fn operator !=
	 \param b
	 \return bool operator
	*/
	inline bool	operator!=(const cMyTVShowsValues b) const;

	qint32		m_idEpisode; /*!< TODO: describe */
	qint32		m_idFile; /*!< TODO: describe */
	QString		m_szEpisodeTitle;						// c00 /*!< TODO: describe */
	QString		m_szPlotSummary;						// c01 /*!< TODO: describe */
	qreal		m_dRating;								// c03 /*!< TODO: describe */
	QString		m_szWriters;							// c04 /*!< TODO: describe */
	QDateTime	m_firstAired;							// c05 /*!< TODO: describe */
	QString		m_szThumbnailUrl;						// c06 /*!< TODO: describe */
	qint32		m_iEpisodeLength;						// c09 /*!< TODO: describe */
	QString		m_szDirector;							// c10 /*!< TODO: describe */
	qint32		m_iSeasonNumber;						// c12 /*!< TODO: describe */
	qint32		m_iEpisodeNumber;						// c13 /*!< TODO: describe */
	qint32		m_iSeasonFormattedForSorting;			// c15 /*!< TODO: describe */
	qint32		m_iEpisodeFormattedForSorting;			// c16 /*!< TODO: describe */
	qint32		m_iBookmark;							// c17 /*!< TODO: describe */
	QString		m_szFullPath;							// c18 /*!< TODO: describe */
	qint32		m_idShow; /*!< TODO: describe */
	qint32		m_iUserrating;							// userrating /*!< TODO: describe */
	qint32		m_idSeason; /*!< TODO: describe */
	QString		m_szFileName;							// strFileName /*!< TODO: describe */
	QString		m_szPath;								// strPath /*!< TODO: describe */
	qint32		m_iPlayCount;							// playCount /*!< TODO: describe */
	QDateTime	m_lastPlayed;							// lastPlayed /*!< TODO: describe */
	QDateTime	m_dateAdded;							// dateAdded /*!< TODO: describe */
	QString		m_szTitle;								// strTitle /*!< TODO: describe */
	QString		m_szGenre;								// genre /*!< TODO: describe */
	QString		m_szStudio;								// studio /*!< TODO: describe */
	QDateTime	m_premiereDate;							// premiered /*!< TODO: describe */
	QString		m_szMPAA;								// mpaa /*!< TODO: describe */
	qreal		m_dResumeTimeInSeconds;					// resumeTimeInSeconds /*!< TODO: describe */
	qreal		m_dTotalTimeInSeconds;					// totalTimeInSeconds /*!< TODO: describe */
};

/*!
 \brief

 \class cMyTVShows cmyvideos.h "cmyvideos.h"
*/
class cMyTVShows
{
public:
	cMyTVShows(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
			   const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
			   qint32 iSeasonFormattedForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
			   qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
			   const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
			   qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

	/*!
	 \brief

	 \fn loadActors
	 \param m_db
	 \param videosActorList
	*/
	void			loadActors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	/*!
	 \brief

	 \fn loadDirectors
	 \param m_db
	 \param videosActorList
	*/
	void			loadDirectors(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	/*!
	 \brief

	 \fn loadWriters
	 \param m_db
	 \param videosActorList
	*/
	void			loadWriters(QSqlDatabase& m_db, cMyVideosActorList videosActorList);
	/*!
	 \brief

	 \fn loadCountries
	 \param m_db
	 \param videosCountryList
	*/
	void			loadCountries(QSqlDatabase& m_db, cMyVideosCountryList videosCountryList);
	/*!
	 \brief

	 \fn loadGenres
	 \param m_db
	 \param videosGenreList
	*/
	void			loadGenres(QSqlDatabase& m_db, cMyVideosGenreList videosGenreList);
	/*!
	 \brief

	 \fn loadStudios
	 \param m_db
	 \param videosStudioList
	*/
	void			loadStudios(QSqlDatabase& m_db, cMyVideosStudioList videosStudioList);
	/*!
	 \brief

	 \fn loadVideoStream
	 \param m_db
	*/
	void			loadVideoStream(QSqlDatabase& m_db);
	/*!
	 \brief

	 \fn loadAudioStream
	 \param m_db
	*/
	void			loadAudioStream(QSqlDatabase& m_db);
	/*!
	 \brief

	 \fn loadSubtitleStream
	 \param m_db
	*/
	void			loadSubtitleStream(QSqlDatabase& m_db);

	/*!
	 \brief

	 \fn fillActorsList
	 \param lpView
	*/
	void			fillActorsList(QStandardItemModel *lpView);
	/*!
	 \brief

	 \fn fillDirectorsList
	 \param lpView
	*/
	void			fillDirectorsList(QStandardItemModel *lpView);
	/*!
	 \brief

	 \fn fillWritersList
	 \param lpView
	*/
	void			fillWritersList(QStandardItemModel *lpView);
	/*!
	 \brief

	 \fn fillCountriesList
	 \param lpView
	*/
	void			fillCountriesList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillGenresList
	 \param lpView
	*/
	void			fillGenresList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillStudiosList
	 \param lpView
	*/
	void			fillStudiosList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillVideoStreamList
	 \param lpView
	*/
	void			fillVideoStreamList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillAudioStreamList
	 \param lpView
	*/
	void			fillAudioStreamList(QStandardItemModel* lpView);
	/*!
	 \brief

	 \fn fillSubtitleStreamList
	 \param lpView
	*/
	void			fillSubtitleStreamList(QStandardItemModel* lpView);

	/*!
	 \brief

	 \fn idEpisode
	 \return qint32
	*/
	qint32			idEpisode();
	/*!
	 \brief

	 \fn idFile
	 \return qint32
	*/
	qint32			idFile();
	/*!
	 \brief

	 \fn episodeTitle
	 \return QString
	*/
	QString			episodeTitle();
	/*!
	 \brief

	 \fn plotSummary
	 \return QString
	*/
	QString			plotSummary();
	/*!
	 \brief

	 \fn rating
	 \return qreal
	*/
	qreal			rating();
	/*!
	 \brief

	 \fn writers
	 \return QStringList
	*/
	QStringList		writers();
	/*!
	 \brief

	 \fn firstAired
	 \return QDateTime
	*/
	QDateTime		firstAired();
	/*!
	 \brief

	 \fn thumbnailUrl
	 \return QString
	*/
	QString			thumbnailUrl();
	/*!
	 \brief

	 \fn episodeLength
	 \return qint32
	*/
	qint32			episodeLength();
	/*!
	 \brief

	 \fn director
	 \return QStringList
	*/
	QStringList		director();
	/*!
	 \brief

	 \fn seasonNumber
	 \return qint32
	*/
	qint32			seasonNumber();
	/*!
	 \brief

	 \fn episodeNumber
	 \return qint32
	*/
	qint32			episodeNumber();
	/*!
	 \brief

	 \fn seasonFormattedForSorting
	 \return qint32
	*/
	qint32			seasonFormattedForSorting();
	/*!
	 \brief

	 \fn episodeFormattedForSorting
	 \return qint32
	*/
	qint32			episodeFormattedForSorting();
	/*!
	 \brief

	 \fn bookmark
	 \return qint32
	*/
	qint32			bookmark();
	/*!
	 \brief

	 \fn fullPath
	 \return QString
	*/
	QString			fullPath();
	/*!
	 \brief

	 \fn idShow
	 \return qint32
	*/
	qint32			idShow();
	/*!
	 \brief

	 \fn userRating
	 \return qint32
	*/
	qint32			userRating();
	/*!
	 \brief

	 \fn idSeason
	 \return qint32
	*/
	qint32			idSeason();
	/*!
	 \brief

	 \fn fileName
	 \return QString
	*/
	QString			fileName();
	/*!
	 \brief

	 \fn path
	 \return QString
	*/
	QString			path();
	/*!
	 \brief

	 \fn playCount
	 \return qint32
	*/
	qint32			playCount();
	/*!
	 \brief

	 \fn lastPlayed
	 \return QDateTime
	*/
	QDateTime		lastPlayed();
	/*!
	 \brief

	 \fn dateAdded
	 \return QDateTime
	*/
	QDateTime		dateAdded();
	/*!
	 \brief

	 \fn title
	 \return QString
	*/
	QString			title();
	/*!
	 \brief

	 \fn genre
	 \return QStringList
	*/
	QStringList		genre();
	/*!
	 \brief

	 \fn studio
	 \return QStringList
	*/
	QStringList		studio();
	/*!
	 \brief

	 \fn premierDate
	 \return QDateTime
	*/
	QDateTime		premierDate();
	/*!
	 \brief

	 \fn mpaaRating
	 \return QString
	*/
	QString			mpaaRating();
	/*!
	 \brief

	 \fn resumeTimeInSeconds
	 \return qreal
	*/
	qreal			resumeTimeInSeconds();
	/*!
	 \brief

	 \fn totalTimeInSeconds
	 \return qreal
	*/
	qreal			totalTimeInSeconds();

	/*!
	 \brief

	 \fn isNew
	 \return bool
	*/
	bool			isNew();
	/*!
	 \brief

	 \fn isChanged
	 \return bool
	*/
	bool			isChanged();

	cMyTVShowsValues	m_values; /*!< TODO: describe */
	cMyTVShowsValues	m_oValues; /*!< TODO: describe */
};

Q_DECLARE_METATYPE(cMyTVShows*)

/*!
 \brief

 \class cMyTVShowsList cmyvideos.h "cmyvideos.h"
*/
class cMyTVShowsList : public QList<cMyTVShows*>
{
public:
	cMyTVShowsList();
	/*!
	 \brief

	 \fn add
	 \param idEpisode
	 \param idFile
	 \param szEpisodeTitle
	 \param szPlotSummary
	 \param dRating
	 \param szWriters
	 \param firstAired
	 \param szThumbnailUrl
	 \param iEpisodeLength
	 \param szDirector
	 \param iSeasonNumber
	 \param iEpisodeNumber
	 \param iSeasonFormattetForSorting
	 \param iEpisodeFormattedForSorting
	 \param iBookmark
	 \param szFullPath
	 \param idShow
	 \param iUserrating
	 \param idSeason
	 \param szFileName
	 \param szPath
	 \param iPlayCount
	 \param lastPlayed
	 \param dateAdded
	 \param szTitle
	 \param szGenre
	 \param szStudio
	 \param premiereDate
	 \param szMPAA
	 \param dResumeTimeInSeconds
	 \param dTotalTimeInSeconds
	 \return cMyTVShows
	*/
	cMyTVShows*	add(qint32 idEpisode, qint32 idFile, const QString& szEpisodeTitle, const QString& szPlotSummary, qreal dRating, const QString& szWriters, const QDateTime firstAired,
					const QString& szThumbnailUrl, qint32 iEpisodeLength, const QString& szDirector, qint32 iSeasonNumber, qint32 iEpisodeNumber,
					qint32 iSeasonFormattetForSorting, qint32 iEpisodeFormattedForSorting, qint32 iBookmark, const QString& szFullPath, qint32 idShow, qint32 iUserrating,
					qint32 idSeason, const QString& szFileName, const QString& szPath, qint32 iPlayCount, const QDateTime& lastPlayed, const QDateTime& dateAdded,
					const QString& szTitle, const QString& szGenre, const QString& szStudio, const QDateTime& premiereDate, const QString& szMPAA,
					qreal dResumeTimeInSeconds, qreal dTotalTimeInSeconds);

private:
};

#endif // CMYVIDEOS_H
