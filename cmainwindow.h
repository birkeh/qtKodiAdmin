#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H


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
	cKodiLibrary		m_kodiLibrary;
};

#endif // CMAINWINDOW_H
