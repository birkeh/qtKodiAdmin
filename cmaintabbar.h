#ifndef CMAINTABBAR_H
#define CMAINTABBAR_H


#include <QTabBar>
#include <QIcon>
#include <QPainter>


/*!
 \brief

 \class cMainTabBar cmaintabbar.h "cmaintabbar.h"
*/
class cMainTabBar : public QTabBar
{
	Q_OBJECT
public:
	cMainTabBar(QWidget *parent = Q_NULLPTR);
	/*!
	 \brief

	 \fn ~cMainTabBar
	*/
	virtual	~cMainTabBar();

protected:
	/*!
	 \brief

	 \fn tabSizeHint
	 \param index
	 \return QSize
	*/
	QSize		tabSizeHint(int index) const;
	/*!
	 \brief

	 \fn paintEvent
	 \param
	*/
	void		paintEvent(QPaintEvent *);
};

#endif // CMAINTABBAR_H
