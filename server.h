#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
class Server : public QObject
{
    Q_OBJECT
    QTcpServer *server;                                     //Server socket for listening connection
public:
    explicit Server(QObject *parent = nullptr);
  ~Server();

signals:

public slots:
    void newConnections();                                  //create new connection

};


#endif // SERVER_H
