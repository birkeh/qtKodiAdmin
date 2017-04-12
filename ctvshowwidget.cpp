#include "ctvshowwidget.h"
#include "ui_ctvshowwidget.h"
#include "cimage.h"

#include "cvideoviewitemdelegate.h"
#include "ccheckboxitemdelegate.h"

#include "common.h"


cTVShowWidget::cTVShowWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::cTVShowWidget),
	m_lpTVShowModel(0),
	m_lpImageList(0)
{
	initUI();
}

cTVShowWidget::~cTVShowWidget()
{
	DELETE(m_lpTVShowModel);
	DELETE(m_lpCastModel);
	DELETE(m_lpDirectorModel);
	DELETE(m_lpWriterModel);
	DELETE(m_lpCountryModel);
	DELETE(m_lpGenreModel);
	DELETE(m_lpStudioModel);
//	DELETE(m_lpVideoStreamModel);
//	DELETE(m_lpAudioStreamModel);
//	DELETE(m_lpSubtitleStreamModel);

	delete ui;
}

void cTVShowWidget::initUI()
{
	ui->setupUi(this);
	ui->m_lpBanner->setMinimumSize(BANNER_WIDTH, BANNER_HEIGHT);
	ui->m_lpFanart->setMinimumSize(FANART_WIDTH, FANART_HEIGHT);
	ui->m_lpPoster->setMinimumSize(POSTER_WIDTH, POSTER_HEIGHT);
	ui->m_lpThumb->setMinimumSize(THUMB_WIDTH, THUMB_HEIGHT);

	ui->m_lpInformationTab->setCurrentIndex(0);

	m_lpTVShowModel				= new QStandardItemModel(0, 1);
	QStringList	headerLabels	= QStringList() << tr("TV Show");
	m_lpTVShowModel->setHorizontalHeaderLabels(headerLabels);
	ui->m_lpTVShowView->setModel(m_lpTVShowModel);
	ui->m_lpTVShowView->setItemDelegate(new cVideoViewItemDelegate());


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

//    m_lpVideoStreamModel		= new QStandardItemModel(0, 4);
//    ui->m_lpVideoStreamView->setModel(m_lpVideoStreamModel);

//	m_lpAudioStreamModel		= new QStandardItemModel(0, 4);
//	ui->m_lpAudioStreamView->setModel(m_lpAudioStreamModel);

//	m_lpSubtitleStreamModel		= new QStandardItemModel(0, 1);
//	ui->m_lpSubtitleStreamView->setModel(m_lpSubtitleStreamModel);

	ui->m_lpCountryView->setWrapping(true);
	ui->m_lpGenreView->setWrapping(true);
	ui->m_lpStudioView->setWrapping(true);

	QList<int>	sizes;
	sizes << 500 << 1000;
	ui->m_lpSplitter->setSizes(sizes);

//	QItemSelectionModel*	selectionModel	= ui->m_lpVideoView->selectionModel();
//	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(videoSelectionChanged(QItemSelection,QItemSelection)));

//	selectionModel	= ui->m_lpCastView->selectionModel();
//	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(castSelectionChanged(QItemSelection,QItemSelection)));

//	selectionModel	= ui->m_lpDirectorView->selectionModel();
//	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(directorSelectionChanged(QItemSelection,QItemSelection)));

//	selectionModel	= ui->m_lpWriterView->selectionModel();
//	connect(selectionModel, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(writerSelectionChanged(QItemSelection,QItemSelection)));
}

void cTVShowWidget::setLibrary(cKodiVideoLibrary* lpVideoLibrary, cImageList* lpImageList)
{
	m_lpVideoLibrary	= lpVideoLibrary;
	m_lpImageList		= lpImageList;
	showList();
}

void cTVShowWidget::showList()
{
	m_lpTVShowModel->clear();
	m_lpVideoLibrary->fillTVShowList(m_lpTVShowModel);
	ui->m_lpTVShowView->resizeColumnToContents(0);
	ui->m_lpTVShowView->selectionModel()->setCurrentIndex(m_lpTVShowModel->index(0, 0), QItemSelectionModel::Select | QItemSelectionModel::Current);

	m_lpCountryModel->clear();
	m_lpVideoLibrary->fillCountriesList(m_lpCountryModel);

	m_lpGenreModel->clear();
	m_lpVideoLibrary->fillGenresList(m_lpGenreModel);

	m_lpStudioModel->clear();
	m_lpVideoLibrary->fillStudiosList(m_lpStudioModel);

	ui->m_lpSet->clear();
	m_lpVideoLibrary->fillSetsList(ui->m_lpSet);
}
