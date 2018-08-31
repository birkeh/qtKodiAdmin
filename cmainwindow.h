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

/*!
 \brief

 \class cMainWindow cmainwindow.h "cmainwindow.h"
*/
class cMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	/*!
	 \brief

	 \fn cMainWindow
	 \param parent
	 \param lpSplashScreen
	*/
	explicit cMainWindow(QWidget *parent = 0, QSplashScreen* lpSplashScreen = 0);
	/*!
	 \brief

	 \fn ~cMainWindow
	*/
	~cMainWindow();

private slots:

private:
	Ui::cMainWindow*	ui; /*!< TODO: describe */
	cVideoWidget*		m_lpVideoWidget; /*!< TODO: describe */
	cTVShowWidget*		m_lpTVShowWidget; /*!< TODO: describe */
	cMusicWidget*		m_lpMusicWidget; /*!< TODO: describe */
	cMusicVideosWidget*	m_lpMusicVideoWidget; /*!< TODO: describe */
	cKodiLibrary*		m_lpKodiLibrary; /*!< TODO: describe */

	/*!
	 \brief

	 \fn initUI
	 \param lpSplashScreen
	*/
	void				initUI(QSplashScreen* lpSplashScreen);
	/*!
	 \brief

	 \fn initDB
	 \param lpSplashScreen
	*/
	void				initDB(QSplashScreen* lpSplashScreen);
};

#endif // CMAINWINDOW_H
