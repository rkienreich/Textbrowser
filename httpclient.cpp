#include "httpclient.h"
#include <QCoreApplication>
#include <QDebug>

const int port = 80;

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &HttpClient::newConnection);
}

void HttpClient::start()
{
    if (!m_server->listen(QHostAddress::Any, port))
        throw m_server->errorString(); // happens when PORT already in use or privileged
}

// when connected from client
void HttpClient::newConnection()
{
    m_socket = m_server->nextPendingConnection();
    connect(m_socket, &QTcpSocket::disconnected, this, &HttpClient::clientDisconnect);
    connect(m_socket, &QTcpSocket::readyRead, this, &HttpClient::serverRead);
}

// connection is closed by client
void HttpClient::clientDisconnect()
{
    m_socket->close();
}

void HttpClient::serverRead()
{
    qDebug() << "serverRead";

    while (m_socket->bytesAvailable()) {
        QByteArray msg = m_socket->readAll();
        qDebug() << msg;
        std::reverse(msg.begin(), msg.end());
        m_socket->write(msg);
    }
}

