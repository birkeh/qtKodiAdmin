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
	QStandardItemModel*		m_lpCastModel;
	QStandardItemModel*		m_lpDirectorModel;
	QStandardItemModel*		m_lpWriterModel;
	QStandardItemModel*		m_lpCountryModel;
	QStandardItemModel*		m_lpGenreModel;
	QStandardItemModel*		m_lpStudioModel;
	QStandardItemModel*		m_lpVideoStreamModel;
	QStandardItemModel*		m_lpAudioStreamModel;
	QStandardItemModel*		m_lpSubtitleStreamModel;
	cKodiVideoLibrary*		m_lpVideoLibrary;
	cImageList*				m_lpImageList;

	void					initUI();
	void					showList();
private slots:
	void					videoSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	void					castSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	void					directorSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	void					writerSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
};

#endif // CMOVIEWIDGET_H
