#include "cmainwindow.h"
#include <QApplication>
#include <QTranslator>


int main(int argc, char *argv[])
{
	QTranslator		translator;

	translator.load("qtKodiDB_de");

	QApplication	a(argc, argv);
	a.installTranslator(&translator);

	cMainWindow		w;

	w.showMaximized();
	//w.show();
	//w.resize(100, 100);

	return a.exec();
}
