#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


#include "cmoviewidget.h"
#include "ctvshowwidget.h"
#include "ckodilibrary.h"

#include <QMainWindow>


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

private:
	Ui::cMainWindow*	ui;
	cMovieWidget*		m_lpMovieWidget;
	cTVShowWidget*		m_lpTVShowWidget;
	cKodiLibrary		m_kodiLibrary;

	void				initUI();
	void				initDB();
};

#endif // CMAINWINDOW_H
