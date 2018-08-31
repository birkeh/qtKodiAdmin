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

/*!
 \brief

 \class cVideoWidget cvideowidget.h "cvideowidget.h"
*/
class cVideoWidget : public QWidget
{
	Q_OBJECT

public:
	/*!
	 \brief

	 \fn cVideoWidget
	 \param parent
	*/
	explicit cVideoWidget(QWidget *parent = 0);
	/*!
	 \brief

	 \fn ~cVideoWidget
	*/
	~cVideoWidget();

	/*!
	 \brief

	 \fn setLibrary
	 \param lpVideoLibrary
	 \param lpImageList
	*/
	void					setLibrary(cKodiVideoLibrary* lpVideoLibrary, cImageList* lpImageList);
private:
	Ui::cVideoWidget*		ui; /*!< TODO: describe */
	QStandardItemModel*		m_lpVideoModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpCastModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpDirectorModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpWriterModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpCountryModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpGenreModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpStudioModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpVideoStreamModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpAudioStreamModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpSubtitleStreamModel; /*!< TODO: describe */
	cKodiVideoLibrary*		m_lpVideoLibrary; /*!< TODO: describe */
	cImageList*				m_lpImageList; /*!< TODO: describe */

	/*!
	 \brief

	 \fn initUI
	*/
	void					initUI();
	/*!
	 \brief

	 \fn showList
	*/
	void					showList();

	/*!
	 \brief

	 \fn displaySet
	 \param lpSet
	*/
	void					displaySet(cMyVideosSet* lpSet);
	/*!
	 \brief

	 \fn displayVideo
	 \param lpVideos
	*/
	void					displayVideo(cMyVideos* lpVideos);

	/*!
	 \brief

	 \fn setValue
	 \param lpLineEdit
	 \param szText
	 \param bEnable
	*/
	void					setValue(QLineEdit* lpLineEdit, QString szText, bool bEnable);
	/*!
	 \brief

	 \fn setValue
	 \param lpLineEdit
	 \param szText
	 \param bEnable
	*/
	void					setValue(QTextEdit* lpLineEdit, QString szText, bool bEnable);
	/*!
	 \brief

	 \fn setValue
	 \param lpSpinBox
	 \param dValue
	 \param bEnable
	*/
	void					setValue(QDoubleSpinBox* lpSpinBox, qreal dValue, bool bEnable);
	/*!
	 \brief

	 \fn setValue
	 \param lpSpinBox
	 \param iValue
	 \param bEnable
	*/
	void					setValue(QSpinBox* lpSpinBox, qint32 iValue, bool bEnable);
	/*!
	 \brief

	 \fn setValue
	 \param lpDateTimeEdit
	 \param value
	 \param bEnable
	*/
	void					setValue(QDateTimeEdit* lpDateTimeEdit, QDateTime value, bool bEnable);
	/*!
	 \brief

	 \fn setValue
	 \param lpTimeEdit
	 \param value
	 \param bEnable
	*/
	void					setValue(QTimeEdit* lpTimeEdit, QTime value, bool bEnable);

private slots:
	/*!
	 \brief

	 \fn videoSelectionChanged
	 \param newSelection
	 \param oldSelection
	*/
	void					videoSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	/*!
	 \brief

	 \fn castSelectionChanged
	 \param newSelection
	 \param oldSelection
	*/
	void					castSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	/*!
	 \brief

	 \fn directorSelectionChanged
	 \param newSelection
	 \param oldSelection
	*/
	void					directorSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
	/*!
	 \brief

	 \fn writerSelectionChanged
	 \param newSelection
	 \param oldSelection
	*/
	void					writerSelectionChanged(const QItemSelection& newSelection, const QItemSelection& oldSelection);
};

#endif // CMOVIEWIDGET_H
