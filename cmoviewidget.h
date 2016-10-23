#ifndef CMOVIEWIDGET_H
#define CMOVIEWIDGET_H


#include "ckodivideolibrary.h"

#include <QWidget>
#include <QStandardItemModel>


namespace Ui {
class cMovieWidget;
}


class cMovieWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cMovieWidget(QWidget *parent = 0);
	~cMovieWidget();

	void				setLibrary(cKodiVideoLibrary* lpLibrary);
private:
	Ui::cMovieWidget*	ui;
	QStandardItemModel*	m_lpMovieModel;
	cKodiVideoLibrary*	m_lpLibrary;

	void				initUI();
	void				showList();
};

#endif // CMOVIEWIDGET_H
