#ifndef CKODILIBRARY_H
#define CKODILIBRARY_H


#include "ckodivideolibrary.h"


class cKodiLibrary
{
public:
	cKodiLibrary();
	~cKodiLibrary();

	bool				init(const QString &szPath);
private:
	QString				m_szPath;
	QString				m_szAddons;
	QString				m_szADSP;
	QString				m_szEpg;
	QString				m_szMyMusic;
	QString				m_szMyVideos;
	QString				m_szTextures;
	QString				m_szTV;
	QString				m_szViewModes;
	cKodiVideoLibrary	m_kodiVideoLibrary;

	QString				findFile(const QString& szPath, const QString& szFile);
};

#endif // CKODILIBRARY_H
