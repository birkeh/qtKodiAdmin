#include "cmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	cMainWindow w;
	w.showMaximized();
	//w.show();
	//w.resize(100, 100);

	return a.exec();
}
