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

	if(m_lpCastModel)
		delete m_lpCastModel;

	if(m_lpDirectorModel)
		delete m_lpDirectorModel;

	if(m_lpWriterModel)
		delete m_lpWriterModel;

	delete ui;
}

void cVideoWidget::initUI()
{
	ui->setupUi(this);
	ui->m_lpInformationTab->setCurrentIndex(0);

	m_lpVideoModel				= new QStandardItemModel(0, 1);
	QStringList	headerLabels	= QStringList() << tr("Video");
	m_lpVideoModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpVideoView->setModel(m_lpVideoModel);
	ui->m_lpVideoView->setItemDelegate(new cVideoViewItemDelegate());

	m_lpCastModel				= new QStandardItemModel(0, 2);
	headerLabels				= QStringList() << tr("Name") << tr("Role");
	m_lpCastModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpCastView->setModel(m_lpCastModel);

	m_lpDirectorModel			= new QStandardItemModel(0, 1);
	headerLabels				= QStringList() << tr("Name");
	m_lpDirectorModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpDirectorView->setModel(m_lpDirectorModel);

	m_lpWriterModel			= new QStandardItemModel(0, 1);
	headerLabels				= QStringList() << tr("Name");
	m_lpWriterModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpWriterView->setModel(m_lpWriterModel);

	QList<int>	sizes;
	sizes << 500 << 1000;
	ui->m_lpSplitter->setSizes(sizes);

	QItemSelectionModel*	selectionModel	= ui->m_lpVideoView->selectionModel();
	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(videoSelectionChanged(QItemSelection,QItemSelection)));

	selectionModel	= ui->m_lpCastView->selectionModel();
	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(castSelectionChanged(QItemSelection,QItemSelection)));

	selectionModel	= ui->m_lpDirectorView->selectionModel();
	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(directorSelectionChanged(QItemSelection,QItemSelection)));

	selectionModel	= ui->m_lpWriterView->selectionModel();
	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(writerSelectionChanged(QItemSelection,QItemSelection)));
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

void cVideoWidget::videoSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
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

	m_lpCastModel->clear();
	m_lpDirectorModel->clear();
	m_lpWriterModel->clear();

	// Basic Tab
	ui->m_lpTitle->setText(lpVideos->localMovieTitle());
	ui->m_lpOriginalTitle->setText(lpVideos->originalMovieTitle());
	ui->m_lpTitleForSorting->setText(lpVideos->titleFormattedForSorting());
	ui->m_lpSet->setText(lpVideos->set());
	ui->m_lpTagline->setText(lpVideos->movieTagline());
	ui->m_lpRating->setValue(lpVideos->rating());
	ui->m_lpRatingVotes->setValue(lpVideos->ratingVotes());
	ui->m_lpTop250->setValue(lpVideos->imdbTop250Ranking());
	ui->m_lpReleased->setValue(lpVideos->yearReleased());
	ui->m_lpRuntime->setValue(lpVideos->runtime());
	ui->m_lpCertification->setText(lpVideos->mpaaRating());
	ui->m_lpTrailer->setText(lpVideos->trailerURL());
	ui->m_lpPlayCount->setValue(lpVideos->playCount());
	ui->m_lpLastPlayed->setDateTime(lpVideos->lastPlayed());
	ui->m_lpPlot->setText(lpVideos->moviePlot());
	ui->m_lpOutline->setText(lpVideos->moviePlotOutline());

	// Extended Tab
	ui->m_lpGenres->addItems(lpVideos->genre());
	ui->m_lpCountries->addItems(lpVideos->country());
	ui->m_lpStudios->addItems(lpVideos->studio());

	// Crew Tab
	ui->m_lpCastPicture->clear();
	ui->m_lpDirectorPicture->clear();
	ui->m_lpWriterPicture->clear();

	m_lpVideoLibrary->fillActorList(m_lpCastModel, lpVideos);
	ui->m_lpCastView->resizeColumnToContents(0);
	ui->m_lpCastView->resizeColumnToContents(1);

	m_lpVideoLibrary->fillDirectorsList(m_lpDirectorModel, lpVideos);

	m_lpVideoLibrary->fillWritersList(m_lpWriterModel, lpVideos);

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
	{
		ui->m_lpThumb->setPixmap(thumb.scaled(480, 270, Qt::KeepAspectRatio));
		ui->m_lpThumbBox->setTitle(QString(tr("Thumb (%1 x %2)")).arg(thumb.width()).arg(thumb.height()));
	}
	else
	{
		ui->m_lpThumb->clear();
		ui->m_lpThumbBox->setTitle("Thumb");
	}

	if(fanart.width())
	{
		ui->m_lpFanart->setPixmap(fanart.scaled(480, 270, Qt::KeepAspectRatio));
		ui->m_lpFanartBox->setTitle(QString(tr("Fanart (%1 x %2)")).arg(fanart.width()).arg(fanart.height()));
	}
	else
	{
		ui->m_lpFanart->clear();
		ui->m_lpFanartBox->setTitle(tr("Fanart"));
	}

	if(poster.width())
	{
		ui->m_lpPoster->setPixmap(poster.scaled(480, 270, Qt::KeepAspectRatio));
		ui->m_lpPosterBox->setTitle(QString(tr("Poster (%1 x %2)")).arg(poster.width()).arg(poster.height()));
	}
	else
	{
		ui->m_lpPoster->clear();
		ui->m_lpPosterBox->setTitle(tr("Poster"));
	}

	if(banner.width())
	{
		ui->m_lpBanner->setPixmap(banner.scaled(480, 270, Qt::KeepAspectRatio));
		ui->m_lpBannerBox->setTitle(QString(tr("Banner (%1 x %2)")).arg(banner.width()).arg(banner.height()));
	}
	else
	{
		ui->m_lpBanner->clear();
		ui->m_lpBannerBox->setTitle(tr("Banner"));
	}
}

void cVideoWidget::castSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	ui->m_lpCastPicture->clear();

	const QModelIndex	index	= ui->m_lpCastView->selectionModel()->currentIndex();
	cMyVideosActorLink*	lpActor	= index.data(Qt::UserRole).value<cMyVideosActorLink*>();

	if(!lpActor)
		return;

	QPixmap	picture = m_lpImageList->get(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpActor->m_values.m_lpActor->actorID());
	if(picture.isNull())
		return;
	ui->m_lpCastPicture->setPixmap(picture.scaled(191, 191, Qt::KeepAspectRatio));
}

void cVideoWidget::directorSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	ui->m_lpDirectorPicture->clear();

	const QModelIndex		index		= ui->m_lpDirectorView->selectionModel()->currentIndex();
	cMyVideosDirectorLink*	lpDirector	= index.data(Qt::UserRole).value<cMyVideosDirectorLink*>();

	if(!lpDirector)
		return;

	QPixmap	picture = m_lpImageList->get(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpDirector->m_values.m_lpActor->actorID());
	if(picture.isNull())
		return;
	ui->m_lpDirectorPicture->setPixmap(picture.scaled(191, 191, Qt::KeepAspectRatio));
}

void cVideoWidget::writerSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	ui->m_lpWriterPicture->clear();

	const QModelIndex		index		= ui->m_lpWriterView->selectionModel()->currentIndex();
	cMyVideosWriterLink*	lpWriter	= index.data(Qt::UserRole).value<cMyVideosWriterLink*>();

	if(!lpWriter)
		return;

	QPixmap	picture = m_lpImageList->get(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpWriter->m_values.m_lpActor->actorID());
	if(picture.isNull())
		return;
	ui->m_lpWriterPicture->setPixmap(picture.scaled(191, 191, Qt::KeepAspectRatio));
}
