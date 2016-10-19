#ifndef CTVSHOWWIDGET_H
#define CTVSHOWWIDGET_H

#include <QWidget>

namespace Ui {
class cTVShowWidget;
}

class cTVShowWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cTVShowWidget(QWidget *parent = 0);
	~cTVShowWidget();

private:
	Ui::cTVShowWidget *ui;
};

#endif // CTVSHOWWIDGET_H
