#include "ckodilibrary.h"


#include <QTime>
#include <QDir>
#include <QString>
#include <QStringList>


cKodiLibrary::cKodiLibrary(QStatusBar* lpMainWindowStatusBar, QSqlDatabase& dbVideos) :
	m_command(command_none),
	m_lpMainWindowStatusBar(lpMainWindowStatusBar),
	m_dbVideos(dbVideos)
{
}

void cKodiLibrary::stop()
{
	QMutexLocker	locker(&m_mutex);

	while(m_command != command_none)
		msleep(100);

	m_command	= command_stop;
}

void cKodiLibrary::run()
{
	bool	bStop	= false;
	QTime	timer;
	timer.restart();

	for(;;)
	{
		switch(m_command)
		{
		case command_none:
			break;
		case command_init:
			doInit();
			m_command	= command_none;
			break;
		case command_stop:
			bStop		= true;
			break;
		default:
			break;
		}

		if(bStop)
			break;
		msleep(10);
	}
}

void cKodiLibrary::init()
{
	QMutexLocker	locker(&m_mutex);

	while(m_command != command_none)
		msleep(100);

	m_command	= command_init;
}

bool cKodiLibrary::doInit()
{
	QMutexLocker	locker(&m_mutex);
	qint32			iVideoCount	= 0;

	m_lpMainWindowStatusBar->showMessage("Initializing Videos ...");

	if(!m_dbVideos.open())
		return(false);

	m_lpKodiVideoLibrary	= new cKodiVideoLibrary(m_dbVideos);
	if(m_lpKodiVideoLibrary->init() != -1)
		iVideoCount	= m_lpKodiVideoLibrary->load();
	emit initDone(iVideoCount);

	m_command	= command_none;
	m_lpMainWindowStatusBar->showMessage("Done.", 3000);

	return(iVideoCount != 0);
}
