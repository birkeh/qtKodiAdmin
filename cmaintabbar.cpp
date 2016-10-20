#include <QBitmap>
#include <QStylePainter>
#include <QStyleOptionTab>

#include "cmaintabbar.h"


cMainTabBar::cMainTabBar(QWidget *parent)
	: QTabBar(parent)
{
}

cMainTabBar::~cMainTabBar()
{
}

QSize cMainTabBar::tabSizeHint(int index) const
{
	QSize	s	= QTabBar::tabSizeHint(index);
	s.setHeight(80);
	return(s);
}

void cMainTabBar::paintEvent(QPaintEvent*)
{
	QStylePainter p(this);

	for (int index = 0; index < count(); index++)
	{
		QStyleOptionTab tab;
		initStyleOption(&tab, index);

		QIcon		tempIcon	= tabIcon(index);
		QString	tempText	= this->tabText(index);

		QRect		tabrect		= tabRect(index);

		tab.icon = QIcon();
		tab.text = QString();

		p.drawControl(QStyle::CE_TabBarTab, tab);

		tempIcon.paint(&p, tabrect, Qt::AlignTop);
		tabrect.adjust(0, 0, 0, -2);
		p.drawText(tabrect, Qt::AlignBottom | Qt::AlignHCenter, tempText );
	}
}
