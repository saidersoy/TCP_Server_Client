#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
	Q_OBJECT
public:
	explicit TcpClient(QObject *parent = 0);

signals:

protected:
	QTcpSocket *tcpSocket;
	QString ip;
	int port;
public:
	void connect();
protected slots:
	void onDisconnected();
	void onConnected();
	void onReadyRead();
};
#endif // TCP_CLIENT_H
