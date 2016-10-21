#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include "cmoviewidget.h"
#include "ctvshowwidget.h"
#include "cmusicwidget.h"
#include "cmusicvideoswidget.h"

#include "ckodilibrary.h"

#include <QMainWindow>
#include <QSqlDatabase>


namespace Ui
{
class cMainWindow;
}

class cMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit cMainWindow(QWidget *parent = 0);
	~cMainWindow();

private slots:
	void				onInitDone(qint32 iMovieCount);

private:
	Ui::cMainWindow*	ui;
	cMovieWidget*		m_lpMovieWidget;
	cTVShowWidget*		m_lpTVShowWidget;
	cMusicWidget*		m_lpMusicWidget;
	cMusicVideosWidget*	m_lpMusicVideoWidget;
	cKodiLibrary*		m_lpKodiLibrary;

	QString				m_szPath;
	QString				m_szAddons;
	QString				m_szADSP;
	QString				m_szEpg;
	QString				m_szMyMusic;
	QString				m_szMyVideos;
	QString				m_szTextures;
	QString				m_szTV;
	QString				m_szViewModes;

	QSqlDatabase		m_dbVideos;

	QString				findFile(const QString& szPath, const QString& szFile);
	void				initUI();
	void				initDB();
};

#endif // CMAINWINDOW_H
