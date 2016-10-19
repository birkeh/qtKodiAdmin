#include "cmainwindow.h"
#include "ui_cmainwindow.h"

#include <QDir>


cMainWindow::cMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow)
{
	ui->setupUi(this);
	ui->m_lpMainTab->setCurrentIndex(0);

	setWindowTitle("qtKodiAdmin");

//	m_kodiLibrary.init("C:\\Users\\birkeh\\.kodi");
	m_kodiLibrary.init(QDir::homePath() + QDir::separator() + QString(".kodi"));
}

cMainWindow::~cMainWindow()
{
	delete ui;
}
