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

private:
	Ui::cMainWindow*	ui;
	cMovieWidget*		m_lpMovieWidget;
	cTVShowWidget*		m_lpTVShowWidget;
	cMusicWidget*		m_lpMusicWidget;
	cMusicVideosWidget*	m_lpMusicVideoWidget;
	cKodiLibrary*		m_lpKodiLibrary;

	void				initUI();
	void				initDB();
};

#endif // CMAINWINDOW_H
