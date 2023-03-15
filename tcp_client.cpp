#include<tcp_client.h>
#include <QHostAddress>
#include <QDataStream>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
	ip = "127.0.0.1";
	port = 3000;
	tcpSocket = new QTcpSocket(this);
	QObject::connect(tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
	QObject::connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
	QObject::connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

void TcpClient::connect()
{
	tcpSocket->connectToHost(QHostAddress(ip), port);
}

void TcpClient::onDisconnected()
{
	qDebug() << "11231232";
}

void TcpClient::onReadyRead()
{
	qDebug() << "on Ready Read function";
	QString message  = tcpSocket->readAll();
	qDebug() << message << "received";
	QJsonDocument doc = QJsonDocument::fromJson(message.toUtf8());
	QJsonObject obj = doc.object();
	obj.insert("MessageID",obj.value("MessageID").toInt()+1);
	QJsonDocument document(obj);
	QString addedmsg(document.toJson(QJsonDocument::Compact));
	tcpSocket->write(addedmsg.toUtf8());
	qDebug() << addedmsg <<	"sent";
}

void TcpClient::onConnected()
{
	qDebug() << "connected";
}
