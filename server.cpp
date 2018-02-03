#include "server.h"
#define _PORT 777
Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);                                  //initialize Server socket
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnections()));        //if we obtain connection on server socket, emmit slot newConnections

    if(server->listen(QHostAddress::Any,_PORT))             //if listen succes (have a root access)
    {
        std::cout<<"Server start success"<<std::endl;           //message, listen success
    }
    else std::cout<<"Error listen"<<std::endl;              //else error
}

void Server::newConnections()
{
    QTcpSocket *socket = server->nextPendingConnection();       //cause by signal newConecction in server
    socket->write("HIHII");                                     //Send data to client
    socket->flush();                                            //send all data from buffer
    socket->waitForBytesWritten(30000);                         //wait for at least one bytes will write in socket
    socket->close();                                            //close socket, disconect
    delete socket;                                              //delete socket
    std::cout<<"Socket close"<<std::endl;


}

Server::~Server()
{
       delete server;                                       //delete socket server
}
