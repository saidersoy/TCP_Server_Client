#ifndef TCP_SERVER_H
#define TCP_SERVER_H
#include<QObject>
#include<QTcpSocket>
#include<QTcpServer>

class MyTcpServer : public QObject
{
	Q_OBJECT
public:
	explicit MyTcpServer (QObject *parent = 0);
	~MyTcpServer();

signals:

public slots:
	void newConnection();
	void myReadyRead();
private:
	QTcpServer *server;
};
#endif // TCP_SERVER_H
