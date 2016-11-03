#ifndef CMOVIEWIDGET_H
#define CMOVIEWIDGET_H


#include "ckodivideolibrary.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QItemSelection>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QDateTimeEdit>
#include <QTextEdit>


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

	void					displaySet(cMyVideosSet* lpSet);
	void					displayVideo(cMyVideos* lpVideos);

	void					setValue(QLineEdit* lpLineEdit, QString szText, bool bEnable);
	void					setValue(QTextEdit* lpLineEdit, QString szText, bool bEnable);
	void					setValue(QDoubleSpinBox* lpSpinBox, qreal dValue, bool bEnable);
	void					setValue(QSpinBox* lpSpinBox, qint32 iValue, bool bEnable);
	void					setValue(QDateTimeEdit* lpDateTimeEdit, QDateTime value, bool bEnable);
	void					setValue(QTimeEdit* lpTimeEdit, QTime value, bool bEnable);

private slots:
	void					videoSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	void					castSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	void					directorSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	void					writerSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
};

#endif // CMOVIEWIDGET_H
