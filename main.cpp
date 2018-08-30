#include "cmainwindow.h"
#include <QApplication>
#include <QTranslator>

#include <QSettings>


int main(int argc, char *argv[])
{
	QTranslator		translator;

	translator.load("qtKodiDB_de");

	QApplication	a(argc, argv);
	a.installTranslator(&translator);

	a.setApplicationVersion("0.1");
	a.setApplicationDisplayName("qtKodiDB");
	a.setOrganizationName("WIN-DESIGN");
	a.setOrganizationDomain("windesign.at");
	a.setApplicationName("qtKodiDB");

	cMainWindow		w;

	w.showMaximized();
	//w.show();
	//w.resize(100, 100);

	return a.exec();
}
