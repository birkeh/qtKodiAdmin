#ifndef CKODILIBRARY_H
#define CKODILIBRARY_H


#include "ckodivideolibrary.h"

#include <QStatusBar>
#include <QStandardItemModel>


class cKodiLibrary
{
public:
	cKodiLibrary(QStatusBar* lpMainWindowStatusBar, const QString& szPath);
	~cKodiLibrary();

	bool				init();

	cKodiVideoLibrary*	videoLibrary();
	void				fillVideoList(QStandardItemModel* lpModel);
private:
	QStatusBar*			m_lpMainWindowStatusBar;
	cKodiVideoLibrary*	m_lpKodiVideoLibrary;
	QString				m_szPath;

	QString				m_szAddons;
	QString				m_szADSP;
	QString				m_szEpg;
	QString				m_szMyMusic;
	QString				m_szMyVideos;
	QString				m_szTextures;
	QString				m_szTV;
	QString				m_szViewModes;

	QString				findFile(const QString& szPath, const QString& szFile);
};

#endif // CKODILIBRARY_H
