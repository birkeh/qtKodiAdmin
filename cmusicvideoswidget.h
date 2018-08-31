#ifndef CMUSICVIDEOSWIDGET_H
#define CMUSICVIDEOSWIDGET_H

#include <QWidget>

namespace Ui {
class cMusicVideosWidget;
}

/*!
 \brief

 \class cMusicVideosWidget cmusicvideoswidget.h "cmusicvideoswidget.h"
*/
class cMusicVideosWidget : public QWidget
{
	Q_OBJECT

public:
	/*!
	 \brief

	 \fn cMusicVideosWidget
	 \param parent
	*/
	explicit cMusicVideosWidget(QWidget *parent = 0);
	/*!
	 \brief

	 \fn ~cMusicVideosWidget
	*/
	~cMusicVideosWidget();

private:
	Ui::cMusicVideosWidget *ui; /*!< TODO: describe */
};

#endif // CMUSICVIDEOSWIDGET_H
