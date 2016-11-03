#include "cvideowidget.h"
#include "ui_cvideowidget.h"
#include "cimage.h"

#include "cvideoviewitemdelegate.h"
#include "ccheckboxitemdelegate.h"


#define DELETE(x) { if(x) delete x, x=0; }

#define THUMB_WIDTH		220
#define THUMB_HEIGHT	390
#define FANART_WIDTH	480
#define FANART_HEIGHT	270
#define POSTER_WIDTH	220
#define POSTER_HEIGHT	390
#define BANNER_WIDTH	480
#define BANNER_HEIGHT	 90


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
	DELETE(m_lpVideoModel);
	DELETE(m_lpCastModel);
	DELETE(m_lpDirectorModel);
	DELETE(m_lpWriterModel);
	DELETE(m_lpCountryModel);
	DELETE(m_lpGenreModel);
	DELETE(m_lpStudioModel);
	DELETE(m_lpVideoStreamModel);
	DELETE(m_lpAudioStreamModel);
	DELETE(m_lpSubtitleStreamModel);

	delete ui;
}

void cVideoWidget::initUI()
{
	ui->setupUi(this);
	ui->m_lpBanner->setMinimumSize(BANNER_WIDTH, BANNER_HEIGHT);
	ui->m_lpFanart->setMinimumSize(FANART_WIDTH, FANART_HEIGHT);
	ui->m_lpPoster->setMinimumSize(POSTER_WIDTH, POSTER_HEIGHT);
	ui->m_lpThumb->setMinimumSize(THUMB_WIDTH, THUMB_HEIGHT);

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

	m_lpWriterModel				= new QStandardItemModel(0, 1);
	headerLabels				= QStringList() << tr("Name");
	m_lpWriterModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpWriterView->setModel(m_lpWriterModel);

	m_lpCountryModel			= new QStandardItemModel(0, 1);
	headerLabels				= QStringList() << tr("Name");
	m_lpCountryModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpCountryView->setModel(m_lpCountryModel);
	ui->m_lpCountryView->setItemDelegate(new cCheckBoxItemDelegate());

	m_lpGenreModel				= new QStandardItemModel(0, 1);
	headerLabels				= QStringList() << tr("Name");
	m_lpGenreModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpGenreView->setModel(m_lpGenreModel);
	ui->m_lpGenreView->setItemDelegate(new cCheckBoxItemDelegate());

	m_lpStudioModel				= new QStandardItemModel(0, 1);
	headerLabels				= QStringList() << tr("Name");
	m_lpStudioModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpStudioView->setModel(m_lpStudioModel);
	ui->m_lpStudioView->setItemDelegate(new cCheckBoxItemDelegate());

	m_lpVideoStreamModel		= new QStandardItemModel(0, 4);
	ui->m_lpVideoStreamView->setModel(m_lpVideoStreamModel);

	m_lpAudioStreamModel		= new QStandardItemModel(0, 4);
	ui->m_lpAudioStreamView->setModel(m_lpAudioStreamModel);

	m_lpSubtitleStreamModel		= new QStandardItemModel(0, 1);
	ui->m_lpSubtitleStreamView->setModel(m_lpSubtitleStreamModel);

	ui->m_lpCountryView->setWrapping(true);
	ui->m_lpGenreView->setWrapping(true);
	ui->m_lpStudioView->setWrapping(true);

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

	m_lpCountryModel->clear();
	m_lpVideoLibrary->fillCountriesList(m_lpCountryModel);

	m_lpGenreModel->clear();
	m_lpVideoLibrary->fillGenresList(m_lpGenreModel);

	m_lpStudioModel->clear();
	m_lpVideoLibrary->fillStudiosList(m_lpStudioModel);

	ui->m_lpSet->clear();
	m_lpVideoLibrary->fillSetsList(ui->m_lpSet);
}

void cVideoWidget::displaySet(cMyVideosSet* lpSet)
{
	QPixmap				thumb;
	QPixmap				fanart;
	QPixmap				poster;
	QPixmap				banner;
	QString				szThumb;
	QString				szFanart;
	QString				szPoster;
	QString				szBanner;

	ui->m_lpSet->setVisible(false);
	ui->m_lpSetText->setVisible(true);

	m_lpCastModel->clear();
	m_lpDirectorModel->clear();
	m_lpWriterModel->clear();

	m_lpVideoStreamModel->clear();
	m_lpAudioStreamModel->clear();
	m_lpSubtitleStreamModel->clear();

	ui->m_lpCastView->setEnabled(false);
	ui->m_lpDirectorView->setEnabled(false);
	ui->m_lpWriterView->setEnabled(false);
	ui->m_lpCastPicture->clear();
	ui->m_lpDirectorPicture->clear();
	ui->m_lpWriterPicture->clear();
	ui->m_lpCastPicture->setEnabled(false);
	ui->m_lpDirectorPicture->setEnabled(false);
	ui->m_lpWriterPicture->setEnabled(false);

	ui->m_lpGenresGroup->setEnabled(false);
	ui->m_lpCountriesGroup->setEnabled(false);
	ui->m_lpStudiosGroup->setEnabled(false);
	ui->m_lpVideoStreamBox->setEnabled(false);
	ui->m_lpAudioStreamBox->setEnabled(false);
	ui->m_lpSubtitleStreamBox->setEnabled(false);

	// Basic Tab
	setValue(ui->m_lpTitle, QString(""), false);
	setValue(ui->m_lpOriginalTitle, QString(""), false);
	setValue(ui->m_lpTitleForSorting, QString(""), false);
	ui->m_lpSet->setCurrentIndex(ui->m_lpSet->findText(lpSet->strSet()));
	ui->m_lpSetText->setText(lpSet->strSet());
	setValue(ui->m_lpTagline, QString(""), false);
	setValue(ui->m_lpRating, 0, false);
	setValue(ui->m_lpRatingVotes, 0, false);
	setValue(ui->m_lpTop250, 0, false);
	setValue(ui->m_lpReleased, 0, false);
	setValue(ui->m_lpRuntime, 0, false);
	setValue(ui->m_lpCertification, 0, false);
	setValue(ui->m_lpTrailer, QString(""), false);
	setValue(ui->m_lpPlayCount, 0, false);
	setValue(ui->m_lpLastPlayed, QDateTime(), false);
	setValue(ui->m_lpPlot, QString(""), false);
	setValue(ui->m_lpOutline, QString(""), false);

	setValue(ui->m_lpVideoDuration, QTime::fromMSecsSinceStartOfDay(0), false);

	thumb		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_thumb, lpSet->idSet());
	fanart		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_fanart, lpSet->idSet());
	poster		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_poster, lpSet->idSet());
	banner		= m_lpImageList->get(cImage::MEDIATYPE_set, cImage::TYPE_banner, lpSet->idSet());

	szThumb		= m_lpImageList->fileName(cImage::MEDIATYPE_set, cImage::TYPE_thumb, lpSet->idSet());
	szFanart	= m_lpImageList->fileName(cImage::MEDIATYPE_set, cImage::TYPE_fanart, lpSet->idSet());
	szPoster	= m_lpImageList->fileName(cImage::MEDIATYPE_set, cImage::TYPE_poster, lpSet->idSet());
	szBanner	= m_lpImageList->fileName(cImage::MEDIATYPE_set, cImage::TYPE_banner, lpSet->idSet());

	if(thumb.width())
	{
		ui->m_lpThumb->setPixmap(thumb.scaled(THUMB_WIDTH, THUMB_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpThumbBox->setTitle(QString(tr("Thumb (%1 x %2)")).arg(thumb.width()).arg(thumb.height()));
		ui->m_lpThumb->setToolTip(szThumb);
	}
	else
	{
		ui->m_lpThumb->clear();
		ui->m_lpThumbBox->setTitle("Thumb");
		ui->m_lpThumb->setToolTip("");
	}

	if(fanart.width())
	{
		ui->m_lpFanart->setPixmap(fanart.scaled(FANART_WIDTH, FANART_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpFanartBox->setTitle(QString(tr("Fanart (%1 x %2)")).arg(fanart.width()).arg(fanart.height()));
		ui->m_lpFanart->setToolTip(szFanart);
	}
	else
	{
		ui->m_lpFanart->clear();
		ui->m_lpFanartBox->setTitle(tr("Fanart"));
		ui->m_lpFanart->setToolTip("");
	}

	if(poster.width())
	{
		ui->m_lpPoster->setPixmap(poster.scaled(POSTER_WIDTH, POSTER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpPosterBox->setTitle(QString(tr("Poster (%1 x %2)")).arg(poster.width()).arg(poster.height()));
		ui->m_lpPoster->setToolTip(szPoster);
	}
	else
	{
		ui->m_lpPoster->clear();
		ui->m_lpPosterBox->setTitle(tr("Poster"));
		ui->m_lpPoster->setToolTip("");
	}

	if(banner.width())
	{
		ui->m_lpBanner->setPixmap(banner.scaled(BANNER_WIDTH, BANNER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpBannerBox->setTitle(QString(tr("Banner (%1 x %2)")).arg(banner.width()).arg(banner.height()));
		ui->m_lpBanner->setToolTip(szBanner);
	}
	else
	{
		ui->m_lpBanner->clear();
		ui->m_lpBannerBox->setTitle(tr("Banner"));
		ui->m_lpBanner->setToolTip("");
	}
}

void cVideoWidget::displayVideo(cMyVideos* lpVideos)
{
	QPixmap				thumb;
	QPixmap				fanart;
	QPixmap				poster;
	QPixmap				banner;
	QString				szThumb;
	QString				szFanart;
	QString				szPoster;
	QString				szBanner;

	ui->m_lpSet->setVisible(true);
	ui->m_lpSetText->setVisible(false);

	m_lpCastModel->clear();
	m_lpDirectorModel->clear();
	m_lpWriterModel->clear();

	ui->m_lpCastView->setEnabled(true);
	ui->m_lpDirectorView->setEnabled(true);
	ui->m_lpWriterView->setEnabled(true);
	ui->m_lpCastPicture->clear();
	ui->m_lpDirectorPicture->clear();
	ui->m_lpWriterPicture->clear();
	ui->m_lpCastPicture->setEnabled(true);
	ui->m_lpDirectorPicture->setEnabled(true);
	ui->m_lpWriterPicture->setEnabled(true);

	ui->m_lpGenresGroup->setEnabled(true);
	ui->m_lpCountriesGroup->setEnabled(true);
	ui->m_lpStudiosGroup->setEnabled(true);
	ui->m_lpVideoStreamBox->setEnabled(true);
	ui->m_lpAudioStreamBox->setEnabled(true);
	ui->m_lpSubtitleStreamBox->setEnabled(true);

	// Basic Tab
	setValue(ui->m_lpTitle, lpVideos->localMovieTitle(), true);
	setValue(ui->m_lpOriginalTitle, lpVideos->originalMovieTitle(), true);
	setValue(ui->m_lpTitleForSorting, lpVideos->titleFormattedForSorting(), true);
	if(lpVideos->set())
	{
		ui->m_lpSet->setCurrentIndex(ui->m_lpSet->findText(lpVideos->set()->strSet()));
		ui->m_lpSetText->setText(lpVideos->set()->strSet());
	}
	else
	{
		ui->m_lpSet->setCurrentIndex(0);
		ui->m_lpSetText->setText("");
	}
	setValue(ui->m_lpTagline, lpVideos->movieTagline(), true);
	setValue(ui->m_lpRating, lpVideos->rating(), true);
	setValue(ui->m_lpRatingVotes, lpVideos->ratingVotes(), true);
	setValue(ui->m_lpTop250, lpVideos->imdbTop250Ranking(), true);
	setValue(ui->m_lpReleased, lpVideos->yearReleased(), true);
	setValue(ui->m_lpRuntime, lpVideos->runtime(), true);
	setValue(ui->m_lpCertification, lpVideos->mpaaRating(), true);
	setValue(ui->m_lpTrailer, lpVideos->trailerURL(), true);
	setValue(ui->m_lpPlayCount, lpVideos->playCount(), true);
	setValue(ui->m_lpLastPlayed, lpVideos->lastPlayed(), true);
	setValue(ui->m_lpPlot, lpVideos->moviePlot(), true);
	setValue(ui->m_lpOutline, lpVideos->moviePlotOutline(), true);

	// Extended Tab
	m_lpVideoLibrary->fillCountriesList(m_lpCountryModel, lpVideos);
	m_lpVideoLibrary->fillGenresList(m_lpGenreModel, lpVideos);
	m_lpVideoLibrary->fillStudiosList(m_lpStudioModel, lpVideos);

	// Crew Tab
	ui->m_lpCastPicture->clear();
	ui->m_lpDirectorPicture->clear();
	ui->m_lpWriterPicture->clear();

	m_lpVideoLibrary->fillActorList(m_lpCastModel, lpVideos);
	ui->m_lpCastView->resizeColumnToContents(0);
	ui->m_lpCastView->resizeColumnToContents(1);

	m_lpVideoLibrary->fillDirectorsList(m_lpDirectorModel, lpVideos);

	m_lpVideoLibrary->fillWritersList(m_lpWriterModel, lpVideos);

	// Stream Tab
	m_lpVideoLibrary->fillVideoStreamList(m_lpVideoStreamModel, lpVideos);
	ui->m_lpVideoStreamView->resizeColumnToContents(0);
	ui->m_lpVideoStreamView->resizeColumnToContents(1);
	ui->m_lpVideoStreamView->resizeColumnToContents(2);
	ui->m_lpVideoStreamView->resizeColumnToContents(3);

	m_lpVideoLibrary->fillAudioStreamList(m_lpAudioStreamModel, lpVideos);
	ui->m_lpAudioStreamView->resizeColumnToContents(0);
	ui->m_lpAudioStreamView->resizeColumnToContents(1);
	ui->m_lpAudioStreamView->resizeColumnToContents(2);
	ui->m_lpAudioStreamView->resizeColumnToContents(3);

	m_lpVideoLibrary->fillSubtitleStreamList(m_lpSubtitleStreamModel, lpVideos);

	if(lpVideos->m_values.m_iVideoDuration != -1)
		setValue(ui->m_lpVideoDuration, QTime::fromMSecsSinceStartOfDay(lpVideos->m_values.m_iVideoDuration*1000), true);
	else
		setValue(ui->m_lpVideoDuration, QTime::fromMSecsSinceStartOfDay(0), true);

	thumb		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_thumb, lpVideos->idMovie());
	fanart		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_fanart, lpVideos->idMovie());
	poster		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_poster, lpVideos->idMovie());
	banner		= m_lpImageList->get(cImage::MEDIATYPE_movie, cImage::TYPE_banner, lpVideos->idMovie());

	szThumb		= m_lpImageList->fileName(cImage::MEDIATYPE_movie, cImage::TYPE_thumb, lpVideos->idMovie());
	szFanart	= m_lpImageList->fileName(cImage::MEDIATYPE_movie, cImage::TYPE_fanart, lpVideos->idMovie());
	szPoster	= m_lpImageList->fileName(cImage::MEDIATYPE_movie, cImage::TYPE_poster, lpVideos->idMovie());
	szBanner	= m_lpImageList->fileName(cImage::MEDIATYPE_movie, cImage::TYPE_banner, lpVideos->idMovie());

	if(thumb.width())
	{
		ui->m_lpThumb->setPixmap(thumb.scaled(THUMB_WIDTH, THUMB_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpThumbBox->setTitle(QString(tr("Thumb (%1 x %2)")).arg(thumb.width()).arg(thumb.height()));
		ui->m_lpThumb->setToolTip(szThumb);
	}
	else
	{
		ui->m_lpThumb->clear();
		ui->m_lpThumbBox->setTitle("Thumb");
		ui->m_lpThumb->setToolTip("");
	}

	if(fanart.width())
	{
		ui->m_lpFanart->setPixmap(fanart.scaled(FANART_WIDTH, FANART_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpFanartBox->setTitle(QString(tr("Fanart (%1 x %2)")).arg(fanart.width()).arg(fanart.height()));
		ui->m_lpFanart->setToolTip(szFanart);
	}
	else
	{
		ui->m_lpFanart->clear();
		ui->m_lpFanartBox->setTitle(tr("Fanart"));
		ui->m_lpFanart->setToolTip("");
	}

	if(poster.width())
	{
		ui->m_lpPoster->setPixmap(poster.scaled(POSTER_WIDTH, POSTER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpPosterBox->setTitle(QString(tr("Poster (%1 x %2)")).arg(poster.width()).arg(poster.height()));
		ui->m_lpPoster->setToolTip(szPoster);
	}
	else
	{
		ui->m_lpPoster->clear();
		ui->m_lpPosterBox->setTitle(tr("Poster"));
		ui->m_lpPoster->setToolTip("");
	}

	if(banner.width())
	{
		ui->m_lpBanner->setPixmap(banner.scaled(BANNER_WIDTH, BANNER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->m_lpBannerBox->setTitle(QString(tr("Banner (%1 x %2)")).arg(banner.width()).arg(banner.height()));
		ui->m_lpBanner->setToolTip(szBanner);
	}
	else
	{
		ui->m_lpBanner->clear();
		ui->m_lpBannerBox->setTitle(tr("Banner"));
		ui->m_lpBanner->setToolTip("");
	}
}
void cVideoWidget::setValue(QLineEdit* lpLineEdit, QString szText, bool bEnable)
{
	lpLineEdit->setText(szText);
	lpLineEdit->setEnabled(bEnable);
}

void cVideoWidget::setValue(QTextEdit* lpTextEdit, QString szText, bool bEnable)
{
	lpTextEdit->setText(szText);
	lpTextEdit->setEnabled(bEnable);
}

void cVideoWidget::setValue(QDoubleSpinBox* lpSpinBox, qreal dValue, bool bEnable)
{
	lpSpinBox->setValue(dValue);
	lpSpinBox->setEnabled(bEnable);
}

void cVideoWidget::setValue(QSpinBox* lpSpinBox, qint32 iValue, bool bEnable)
{
	lpSpinBox->setValue(iValue);
	lpSpinBox->setEnabled(bEnable);
}

void cVideoWidget::setValue(QDateTimeEdit* lpDateTimeEdit, QDateTime value, bool bEnable)
{
	lpDateTimeEdit->setDateTime(value);
	lpDateTimeEdit->setEnabled(bEnable);
}

void cVideoWidget::setValue(QTimeEdit* lpTimeEdit, QTime value, bool bEnable)
{
	lpTimeEdit->setTime(value);
	lpTimeEdit->setEnabled(bEnable);
}

void cVideoWidget::videoSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	const QModelIndex	index		= ui->m_lpVideoView->selectionModel()->currentIndex();

	if(m_lpVideoModel->itemFromIndex(index)->hasChildren())
	{
		cMyVideosSet*	lpSet		= index.data(Qt::UserRole).value<cMyVideosSet*>();
		displaySet(lpSet);
	}
	else
	{
		cMyVideos*		lpVideos	= index.data(Qt::UserRole).value<cMyVideos*>();
		displayVideo(lpVideos);
	}
}

void cVideoWidget::castSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	ui->m_lpCastPicture->clear();
	ui->m_lpCastPicture->setToolTip("");

	const QModelIndex	index	= ui->m_lpCastView->selectionModel()->currentIndex();
	cMyVideosActorLink*	lpActor	= index.data(Qt::UserRole).value<cMyVideosActorLink*>();

	if(!lpActor)
		return;

	QPixmap	picture = m_lpImageList->get(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpActor->m_values.m_lpActor->actorID());
	if(picture.isNull())
		return;
	ui->m_lpCastPicture->setPixmap(picture.scaled(191, 191, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->m_lpCastPicture->setToolTip(m_lpImageList->fileName(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpActor->m_values.m_lpActor->actorID()));
}

void cVideoWidget::directorSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	ui->m_lpDirectorPicture->clear();
	ui->m_lpDirectorPicture->setToolTip("");

	const QModelIndex		index		= ui->m_lpDirectorView->selectionModel()->currentIndex();
	cMyVideosDirectorLink*	lpDirector	= index.data(Qt::UserRole).value<cMyVideosDirectorLink*>();

	if(!lpDirector)
		return;

	QPixmap	picture = m_lpImageList->get(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpDirector->m_values.m_lpActor->actorID());
	if(picture.isNull())
		return;
	ui->m_lpDirectorPicture->setPixmap(picture.scaled(191, 191, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->m_lpDirectorPicture->setToolTip(m_lpImageList->fileName(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpDirector->m_values.m_lpActor->actorID()));
}

void cVideoWidget::writerSelectionChanged(const QItemSelection& /*newSelection*/, const QItemSelection& /*oldSelection*/)
{
	ui->m_lpWriterPicture->clear();
	ui->m_lpWriterPicture->setToolTip("");

	const QModelIndex		index		= ui->m_lpWriterView->selectionModel()->currentIndex();
	cMyVideosWriterLink*	lpWriter	= index.data(Qt::UserRole).value<cMyVideosWriterLink*>();

	if(!lpWriter)
		return;

	QPixmap	picture = m_lpImageList->get(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpWriter->m_values.m_lpActor->actorID());
	if(picture.isNull())
		return;
	ui->m_lpWriterPicture->setPixmap(picture.scaled(191, 191, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->m_lpWriterPicture->setToolTip(m_lpImageList->fileName(cImage::MEDIATYPE_actor, cImage::TYPE_thumb, lpWriter->m_values.m_lpActor->actorID()));
}
