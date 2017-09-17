#include <QtNetwork>

#include <stdlib.h>
#include <unistd.h>

#include "log.h"
#include "server.h"

server::server(int port) : QObject( Q_NULLPTR), tcp_server(Q_NULLPTR), network_session(0)
{
	write_log( "Initialize server port = %d", port);

	QNetworkConfigurationManager manager;

	if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
		// Get saved network configuration
		QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
		settings.beginGroup(QLatin1String("QtNetwork"));
		const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
		settings.endGroup();

		// If the saved network configuration is not currently discovered use the system default
		QNetworkConfiguration config = manager.configurationFromIdentifier(id);
		if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered) {
			config = manager.defaultConfiguration();
		}

		network_session = new QNetworkSession(config);
		connect(network_session, &QNetworkSession::opened, this, &server::sessionOpened);

		write_log("Opening network session");
		network_session->open();
	} else {
		sessionOpened();
	}

	connect(tcp_server, &QTcpServer::newConnection, this, &server::sendCallback);
}

server::~server(){
	write_log( "Destroy server");
}

void server::sessionOpened(){
	write_log( "Session Opened call");
	// Save the used configuration
	if (network_session) {
		QNetworkConfiguration config = network_session->configuration();
		QString id;
		if (config.type() == QNetworkConfiguration::UserChoice){
			id = network_session->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
		}else{
			id = config.identifier();
		}

		QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
		settings.beginGroup(QLatin1String("QtNetwork"));
		settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
		settings.endGroup();
	}

	
	tcp_server = new QTcpServer();
	if (!tcp_server->listen()) {
		write_log("Unable to start the server: %s.", tcp_server->errorString().toStdString().c_str());
		//close();
		return;
	}
	QString ipAddress;
	QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
	// use the first non-localhost IPv4 address
	for (int i = 0; i < ipAddressesList.size(); ++i) {
		if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
				ipAddressesList.at(i).toIPv4Address()) {
			ipAddress = ipAddressesList.at(i).toString();
			break;
		}
	}
	// if we did not find one, use IPv4 localhost
	if (ipAddress.isEmpty()){
		ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
	}
	write_log("The server is running on IP: %s, port: %d", ipAddress.toStdString().c_str(), tcp_server->serverPort());
}

void server::sendCallback(){
	write_log( "Send callback");
	//QByteArray block;
    //QDataStream out(&block, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_4_0);

    //QTcpSocket *clientConnection = tcp_server->nextPendingConnection();
    //connect(clientConnection, &QAbstractSocket::disconnected,
    //        clientConnection, &QObject::deleteLater);

    //clientConnection->write(block);
    //clientConnection->disconnectFromHost();
}
