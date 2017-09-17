#include <QCoreApplication>

#include "server.h"
#include "log.h"

int main(int argc, char *argv[])
{
	write_log( "Start chipbot_bot");

	QCoreApplication a(argc, argv);
	server communication_server;

	return a.exec();
}
