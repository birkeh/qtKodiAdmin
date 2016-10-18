#include "cmainwindow.h"
#include "ui_cmainwindow.h"


cMainWindow::cMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow)
{
	ui->setupUi(this);
	ui->m_lpMainTab->setCurrentIndex(0);

	setWindowTitle("qtKodiAdmin");
	m_kodiLibrary.init("C:\\Users\\birkeh\\.kodi");
}

cMainWindow::~cMainWindow()
{
	delete ui;
}
