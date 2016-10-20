#ifndef CMUSICWIDGET_H
#define CMUSICWIDGET_H

#include <QWidget>

namespace Ui {
class cMusicWidget;
}

class cMusicWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cMusicWidget(QWidget *parent = 0);
	~cMusicWidget();

private:
	Ui::cMusicWidget *ui;
};

#endif // CMUSICWIDGET_H
