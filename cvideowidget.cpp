#include "cvideowidget.h"
#include "ui_cvideowidget.h"
#include "cimage.h"

#include "cvideoviewitemdelegate.h"


cVideoWidget::cVideoWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cVideoWidget),
	m_lpVideoModel(0),
	m_lpImageList(0)
{
	initUI();
}

cVideoWidget::~cVideoWidget()
{
	if(m_lpVideoModel)
		delete m_lpVideoModel;

	delete ui;
}

void cVideoWidget::initUI()
{
	ui->setupUi(this);

	m_lpVideoModel				= new QStandardItemModel(0, 1);
	QStringList	headerLabels	= QStringList() << tr("Video");
	m_lpVideoModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpVideoView->setModel(m_lpVideoModel);
	ui->m_lpVideoView->setItemDelegate(new cVideoViewItemDelegate());

	QList<int>	sizes;
	sizes << 500 << 1000;
	ui->m_lpSplitter->setSizes(sizes);
	QItemSelectionModel*	selectionModel	= ui->m_lpVideoView->selectionModel();
	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(selectionChanged(QItemSelection,QItemSelection)));
}

void cVideoWidget::setLibrary(cKodiVideoLibrary* lpVideoLibrary, cImageList* lpImageList)
{
	m_lpVideoLibrary	= lpVideoLibrary;
	m_lpImageList		= lpImageList;
	showList();
}

void cVideoWidget::showList()
{
	m_lpVideoModel->clear();

	m_lpVideoLibrary->fillVideoList(m_lpVideoModel);
	ui->m_lpVideoView->resizeColumnToContents(0);
}

void cVideoWidget::selectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	QPixmap				thumb;
	QPixmap				fanart;
	QPixmap				poster;
	QPixmap				banner;

	ui->m_lpThumb->clear();
	ui->m_lpFanart->clear();
	ui->m_lpPoster->clear();
	ui->m_lpBanner->clear();

	const QModelIndex	index		= ui->m_lpVideoView->selectionModel()->currentIndex();
	cMyVideos*			lpVideos	= index.data(Qt::UserRole).value<cMyVideos*>();
	if(m_lpVideoModel->itemFromIndex(index)->hasChildren())
	{
		thumb		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_thumb, lpVideos->idSet());
		fanart		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_fanart, lpVideos->idSet());
		poster		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_poster, lpVideos->idSet());
		banner		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_banner, lpVideos->idSet());
	}
	else
	{
		thumb		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_thumb, lpVideos->idMovie());
		fanart		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_fanart, lpVideos->idMovie());
		poster		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_poster, lpVideos->idMovie());
		banner		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_banner, lpVideos->idMovie());
	}
	if(thumb.width())
		ui->m_lpThumb->setPixmap(thumb.scaled(thumb.size()/4));
	if(fanart.width())
		ui->m_lpFanart->setPixmap(fanart.scaled(fanart.size()/4));
	if(poster.width())
		ui->m_lpPoster->setPixmap(poster.scaled(poster.size()/4));
	if(banner.width())
		ui->m_lpBanner->setPixmap(thumb.scaled(thumb.size()/4));
}
