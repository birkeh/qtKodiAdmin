#include "cmainwindow.h"
#include <QApplication>
#include <QTranslator>

#include <QSettings>

#include <QSplashScreen>
#include <QPixmap>


int main(int argc, char *argv[])
{
	QTranslator		translator;

	translator.load("qtKodiAdmin_de");

	QApplication	a(argc, argv);
	a.installTranslator(&translator);

	a.setApplicationVersion("0.1");
	a.setApplicationDisplayName("qtKodiAdmin");
	a.setOrganizationName("WIN-DESIGN");
	a.setOrganizationDomain("windesign.at");
	a.setApplicationName("qtKodiAdmin");

	QPixmap			pixmap(":/splash/splash.png");
	QSplashScreen*	lpSplashScreen	= new QSplashScreen(pixmap);
	lpSplashScreen->show();
	a.processEvents();
	lpSplashScreen->showMessage("initializing ...", Qt::AlignLeft | Qt::AlignBottom, Qt::white);

	cMainWindow		w(0, lpSplashScreen);

	w.showMaximized();
	//w.show();
	//w.resize(100, 100);

	lpSplashScreen->finish(&w);
	delete lpSplashScreen;

	return a.exec();
}
