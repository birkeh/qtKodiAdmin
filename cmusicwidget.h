#ifndef CMUSICWIDGET_H
#define CMUSICWIDGET_H

#include <QWidget>

namespace Ui {
class cMusicWidget;
}

/*!
 \brief

 \class cMusicWidget cmusicwidget.h "cmusicwidget.h"
*/
class cMusicWidget : public QWidget
{
	Q_OBJECT

public:
	/*!
	 \brief

	 \fn cMusicWidget
	 \param parent
	*/
	explicit cMusicWidget(QWidget *parent = 0);
	/*!
	 \brief

	 \fn ~cMusicWidget
	*/
	~cMusicWidget();

private:
	Ui::cMusicWidget *ui; /*!< TODO: describe */
};

#endif // CMUSICWIDGET_H
