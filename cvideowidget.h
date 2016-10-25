#ifndef CMOVIEWIDGET_H
#define CMOVIEWIDGET_H


#include "ckodivideolibrary.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QItemSelection>


namespace Ui {
class cVideoWidget;
}


class cImage;
class cImageList;

class cVideoWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cVideoWidget(QWidget *parent = 0);
	~cVideoWidget();

	void					setLibrary(cKodiVideoLibrary* lpVideoLibrary, cImageList* lpImageList);
private:
	Ui::cVideoWidget*		ui;
	QStandardItemModel*		m_lpVideoModel;
	cKodiVideoLibrary*		m_lpVideoLibrary;
	cImageList*				m_lpImageList;

	void					initUI();
	void					showList();
private slots:
	void					selectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
};

#endif // CMOVIEWIDGET_H
