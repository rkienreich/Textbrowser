#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QTcpServer>

const int TIMEOUT = 5000; // 5 seconds

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void start();

signals:

public slots:
    void newConnection();
    void clientDisconnect();
    void serverRead();

private:
    QTcpServer* m_server;
    QTcpSocket* m_socket;
};

#endif // HTTPCLIENT_H



