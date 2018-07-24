

#include <QtWidgets/QApplication>
#include "./mediaplayer/player.h"

int main ( int argc, char *argv[] )
{
	QApplication app (argc, argv);
	app.setQuitOnLastWindowClosed(true);

	Player player;
	player.show();

	return app.exec();
}
