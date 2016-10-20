#ifndef CMUSICVIDEOSWIDGET_H
#define CMUSICVIDEOSWIDGET_H

#include <QWidget>

namespace Ui {
class cMusicVideosWidget;
}

class cMusicVideosWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cMusicVideosWidget(QWidget *parent = 0);
	~cMusicVideosWidget();

private:
	Ui::cMusicVideosWidget *ui;
};

#endif // CMUSICVIDEOSWIDGET_H
