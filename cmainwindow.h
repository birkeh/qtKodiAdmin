#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include "cvideowidget.h"
#include "ctvshowwidget.h"
#include "cmusicwidget.h"
#include "cmusicvideoswidget.h"

#include "ckodilibrary.h"

#include <QMainWindow>
#include <QSqlDatabase>

#include <QSplashScreen>


namespace Ui
{
class cMainWindow;
}

class cMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit cMainWindow(QWidget *parent = 0, QSplashScreen* lpSplashScreen = 0);
	~cMainWindow();

private slots:

private:
	Ui::cMainWindow*	ui;
	cVideoWidget*		m_lpVideoWidget;
	cTVShowWidget*		m_lpTVShowWidget;
	cMusicWidget*		m_lpMusicWidget;
	cMusicVideosWidget*	m_lpMusicVideoWidget;
	cKodiLibrary*		m_lpKodiLibrary;

	void				initUI(QSplashScreen* lpSplashScreen);
	void				initDB(QSplashScreen* lpSplashScreen);
};

#endif // CMAINWINDOW_H
