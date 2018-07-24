
#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QVideoWidget>

class VideoWidget : public QVideoWidget
{
	Q_OBJECT

public:
	VideoWidget(QWidget* parent=NULL);
	~VideoWidget();


};


#endif