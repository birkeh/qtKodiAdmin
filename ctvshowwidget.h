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

/*!
 \brief

 \class cTVShowWidget ctvshowwidget.h "ctvshowwidget.h"
*/
class cTVShowWidget : public QWidget
{
	Q_OBJECT

public:
	/*!
	 \brief

	 \fn cTVShowWidget
	 \param parent
	*/
	explicit cTVShowWidget(QWidget *parent = 0);
	/*!
	 \brief

	 \fn ~cTVShowWidget
	*/
	~cTVShowWidget();

	/*!
	 \brief

	 \fn setLibrary
	 \param lpVideoLibrary
	 \param lpImageList
	*/
	void					setLibrary(cKodiVideoLibrary* lpVideoLibrary, cImageList* lpImageList);
private:
	Ui::cTVShowWidget *ui; /*!< TODO: describe */
	QStandardItemModel*		m_lpTVShowModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpCastModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpDirectorModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpWriterModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpCountryModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpGenreModel; /*!< TODO: describe */
	QStandardItemModel*		m_lpStudioModel; /*!< TODO: describe */
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
};

#endif // CTVSHOWWIDGET_H
