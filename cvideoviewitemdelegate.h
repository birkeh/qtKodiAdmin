#ifndef CVIDEOVIEWITEMDELEGATE_H
#define CVIDEOVIEWITEMDELEGATE_H


#include <QStyledItemDelegate>


/*!
 \brief

 \class cVideoViewItemDelegate cvideoviewitemdelegate.h "cvideoviewitemdelegate.h"
*/
class cVideoViewItemDelegate : public QStyledItemDelegate
{
public:
protected:
	/*!
	 \brief

	 \fn paint
	 \param painter
	 \param option
	 \param index
	*/
	void			paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	/*!
	 \brief

	 \fn sizeHint
	 \param option
	 \param index
	 \return QSize
	*/
	QSize			sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CVIDEOVIEWITEMDELEGATE_H
