#ifndef CCHECKBOXITEMDELEGATE_H
#define CCHECKBOXITEMDELEGATE_H


#include <QStyledItemDelegate>


class cCheckBoxItemDelegate : public QStyledItemDelegate
{
public:
protected:
	void			paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	QSize			sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // CCHECKBOXITEMDELEGATE_H
