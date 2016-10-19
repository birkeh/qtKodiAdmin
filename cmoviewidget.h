#ifndef CMOVIEWIDGET_H
#define CMOVIEWIDGET_H

#include <QWidget>

namespace Ui {
class cMovieWidget;
}

class cMovieWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cMovieWidget(QWidget *parent = 0);
	~cMovieWidget();

private:
	Ui::cMovieWidget *ui;
};

#endif // CMOVIEWIDGET_H
