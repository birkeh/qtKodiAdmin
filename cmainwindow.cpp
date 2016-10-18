#include "cmainwindow.h"
#include "ui_cmainwindow.h"


cMainWindow::cMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cMainWindow)
{
	ui->setupUi(this);

	m_kodiVideoLibrary.connect("C:\\Users\\birkeh\\.kodi\\userdata\\Database\\MyVideos99.db");
}

cMainWindow::~cMainWindow()
{
	delete ui;
}
