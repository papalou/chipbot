#ifndef SERVER_H
#define SERVER_H

#include <QTcpSocket>
#include <QDataStream>

#include "communication_common.h"

class QTcpServer;
class QNetworkSession;

class server : public QObject
{
	Q_OBJECT

	public:
		server(int port = DEFAULT_PORT);
		~server();

	private slots:
		void sessionOpened();
		void sendCallback();

	private:
		QTcpServer *tcp_server;
		QNetworkSession *network_session;
};

#endif //SERVER_H
