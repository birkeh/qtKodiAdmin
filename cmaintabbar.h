#ifndef CMAINTABBAR_H
#define CMAINTABBAR_H


#include <QTabBar>
#include <QIcon>
#include <QPainter>


class cMainTabBar : public QTabBar
{
	Q_OBJECT
public:
	cMainTabBar(QWidget *parent = Q_NULLPTR);
	virtual	~cMainTabBar();

protected:
	QSize		tabSizeHint(int index) const;
	void		paintEvent(QPaintEvent *);
};

#endif // CMAINTABBAR_H
