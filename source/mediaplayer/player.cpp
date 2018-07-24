

#include "player.h"
#include "videowidget.h"
#include <QVBoxLayout>

Player::Player(QWidget* parent)
: QWidget(parent, Qt::FramelessWindowHint)
{
	setWindowTitle("Lingovi");
	m_duration = 0;

	initMediaPlayer();
	initVidowWidget();

	setupUi();

	resize(640, 480);

	QString path = "e:\\test.avi";
	//path = "e:\\colors.mp4";

	m_mediaPlayer->setMedia(QUrl::fromLocalFile(path));
	m_mediaPlayer->play();
}

Player::~Player()
{
}

void Player::initMediaPlayer()
{
	m_mediaPlayer = new QMediaPlayer(this);

	connect(m_mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(onPositionChanged(qint64)));
	connect(m_mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(onDurationChanged(qint64)));
	connect(m_mediaPlayer, SIGNAL(metaDataChanged()), this, SLOT(onMetadataChnaged()));
	connect(m_mediaPlayer, SIGNAL(bufferStatusChanged(int)), this, SLOT(onBufferingProgress(int)));
	connect(m_mediaPlayer, SIGNAL(videoAvailableChanged(bool)), this, SLOT(onVideoAvailableChanged(bool)));
	connect(m_mediaPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(onPlayerError(QMediaPlayer::Error)));
	connect(m_mediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), 
			this, SLOT(onStatusChanged(QMediaPlayer::MediaStatus)));
}

/**
 */
void Player::initVidowWidget()
{
	m_videoWidget = new VideoWidget(this);
	m_mediaPlayer->setVideoOutput(m_videoWidget);
	m_videoWidget->show();
}

/**
 */
void Player::setupUi()
{
	QBoxLayout* layout = new QVBoxLayout;
	layout->setMargin(0);
	layout->addWidget(m_videoWidget);

	setLayout(layout);
}

/**
 */
void Player::open()
{
}

/**
 */
void Player::onDurationChanged(qint64 duration)
{
}


/**
 */
void Player::onPositionChanged(qint64 position)
{
}

/**
 */
void Player::onMetadataChnaged()
{
}

/**
 */
void Player::onStatusChanged(QMediaPlayer::MediaStatus status)
{
}

/**
 */
void Player::onBufferingProgress(int progress)
{
}

/**
 */
void Player::onVideoAvailableChanged(bool available)
{
}

/**
 */
void Player::onPlayerError(QMediaPlayer::Error err)
{
	QString errString;
	switch(err)
	{
	case QMediaPlayer::ResourceError : errString = "ResourceError"; break;
	case QMediaPlayer::FormatError : errString = "FormatError"; break;
	case QMediaPlayer::NetworkError : errString = "NetworkError"; break;
	case QMediaPlayer::AccessDeniedError : errString = "AccessDeniedError"; break;
	case QMediaPlayer::ServiceMissingError : errString = "ServiceMissingError"; break;
	}

	if( !errString.isEmpty()) 
	{
		qDebug("%s", qPrintable(errString));
	}
}

/**
 */
void Player::previousClicked()
{
}

/**
 */
void Player::seek(int)
{
}

/**
 */
void Player::jump()
{
}

/**
 */
void Player::setTrackInfo(QString&)
{
}

/**
 */
void Player::setStatusInfo(QString&)
{
}

/**
 */
void Player::handleCursor(QMediaPlayer::MediaStatus)
{
}

/**
 */
void Player::updateDurationInfo(qint64)
{
}
