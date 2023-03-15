#include <tcp_server.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QThread>
MyTcpServer::MyTcpServer(QObject *parent):
	QObject(parent)
{
	server = new QTcpServer(this);
	QObject::connect(server, SIGNAL(newConnection()),this, SLOT(newConnection()));
	if(!server->listen(QHostAddress::Any, 3000)) {
		qDebug() << "Server could not start";
	} else {
		qDebug() << "Server started";
	}
}

MyTcpServer::~MyTcpServer()
{
	qDebug() << "Deleting memory";
}
void MyTcpServer::newConnection()
{
	QTcpSocket *socket = server->nextPendingConnection();
	qDebug() << socket;
	connect(socket, SIGNAL(readyRead()), this, SLOT(myReadyRead()));
	QJsonObject obj;
	obj["MessageID"] = 1;
	QJsonDocument doc(obj);
	QString strJson(doc.toJson(QJsonDocument::Compact));
	socket->write(strJson.toUtf8());
	QThread::sleep(1);
}

void MyTcpServer::myReadyRead()
{
	QTcpSocket *sock = (QTcpSocket*)QObject::sender();
	QString myJson = sock->readAll();
	qDebug() << myJson;
	QJsonDocument doc = QJsonDocument::fromJson(myJson.toUtf8());
	QJsonObject obj = doc.object();
	obj.insert("MessageID",obj.value("MessageID").toInt()+1);
	qDebug() << obj;
	QJsonDocument document(obj);
	QString addedmsg(document.toJson(QJsonDocument::Compact));
	QThread::sleep(1);
	sock->write(addedmsg.toUtf8());
}
