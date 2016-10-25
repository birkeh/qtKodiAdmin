#ifndef CVIDEOVIEWITEMDELEGATE_H
#define CVIDEOVIEWITEMDELEGATE_H


#include <QStyledItemDelegate>


class cVideoViewItemDelegate : public QStyledItemDelegate
{
public:
protected:
	void			paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	QSize			sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CVIDEOVIEWITEMDELEGATE_H
