#ifndef CKODILIBRARY_H
#define CKODILIBRARY_H


#include "ckodivideolibrary.h"

#include <QStatusBar>
#include <QThread>
#include <QMutexLocker>


class cKodiLibrary : public QThread
{
	Q_OBJECT

public:
	cKodiLibrary(QStatusBar* lpMainWindowStatusBar, QSqlDatabase& dbVideos);
public slots:
	void				stop();
	void				init();

signals:
	void				initDone(qint32 iMovieCount);

private:
	enum commands
	{
		command_none	= 0,
		command_init	= 1,
		command_stop	= 99,
	};

	commands			m_command;
	QMutex				m_mutex;
	QStatusBar*			m_lpMainWindowStatusBar;
	cKodiVideoLibrary*	m_lpKodiVideoLibrary;

	QSqlDatabase		m_dbVideos;

	void				run();

	bool				doInit();
};

#endif // CKODILIBRARY_H
