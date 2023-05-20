#ifndef SERVER_H
#define SERVER_H
#include <boost/asio.hpp>


class Server
{
public:
    Server();

    ~Server();
private:
    boost::asio::io_service service;

};

#endif // SERVER_H
