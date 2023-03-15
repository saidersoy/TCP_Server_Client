#include <QCoreApplication>
#include<tcp_server.h>
#include<tcp_client.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	if(QCoreApplication::arguments().at(1) == "server") {
		MyTcpServer * server = new MyTcpServer();
	} else if(QCoreApplication::arguments().at(1) == "client"){
		TcpClient *tcpClient = new TcpClient();
		tcpClient->connect();
	} else {
		qDebug() << "Error: Wrong arguments";
	}
	return a.exec();
}
