
#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
class VideoWidget;

/** 
 */
class Player : public QWidget
{
	Q_OBJECT

public:
	Player(QWidget* parent=NULL);
	~Player();

signals:
	void fullScreenChanged(bool fullScreen);

private:
	QMediaPlayer*	m_mediaPlayer;
	VideoWidget*	m_videoWidget;
	qint64			m_duration;

private slots:
	void open();
	void onDurationChanged(qint64);
	void onPositionChanged(qint64);
	void onMetadataChnaged();
	void onStatusChanged(QMediaPlayer::MediaStatus);
	void onBufferingProgress(int);
	void onVideoAvailableChanged(bool);
	void onPlayerError(QMediaPlayer::Error);

	void previousClicked();

	void seek(int);
	void jump();
	

private:
	void initMediaPlayer();
	void initVidowWidget();
	void setupUi();
	void setTrackInfo(QString&);
	void setStatusInfo(QString&);
	void handleCursor(QMediaPlayer::MediaStatus);
	void updateDurationInfo(qint64);



};


#endif