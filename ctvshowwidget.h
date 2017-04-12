#ifndef CTVSHOWWIDGET_H
#define CTVSHOWWIDGET_H


#include "ckodivideolibrary.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QItemSelection>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QDateTimeEdit>
#include <QTextEdit>


namespace Ui {
class cTVShowWidget;
}


class cImage;
class cImageList;

class cTVShowWidget : public QWidget
{
	Q_OBJECT

public:
	explicit cTVShowWidget(QWidget *parent = 0);
	~cTVShowWidget();

	void					setLibrary(cKodiVideoLibrary* lpVideoLibrary, cImageList* lpImageList);
private:
	Ui::cTVShowWidget *ui;
	QStandardItemModel*		m_lpTVShowModel;
	QStandardItemModel*		m_lpCastModel;
	QStandardItemModel*		m_lpDirectorModel;
	QStandardItemModel*		m_lpWriterModel;
	QStandardItemModel*		m_lpCountryModel;
    QStandardItemModel*		m_lpGenreModel;
    QStandardItemModel*		m_lpStudioModel;
    cKodiVideoLibrary*		m_lpVideoLibrary;
	cImageList*				m_lpImageList;

	void					initUI();
	void					showList();
};

#endif // CTVSHOWWIDGET_H
