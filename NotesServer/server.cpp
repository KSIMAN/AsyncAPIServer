#include "server.h"


Server::Server(boost::asio::io_service &service, int port)
{

}

Server::Server(int port) :
    _listen_port(port),
    _service()
{

}

std::string Server::read_(boost::asio::ip::tcp::socket & socket) {
       boost::asio::streambuf buf;
       boost::asio::read_until( socket, buf, "\n" );
       std::string data = boost::asio::buffer_cast<const char*>(buf.data());
       return data;
}
void Server::send_(boost::asio::ip::tcp::socket & socket, const std::string& message) {
       const std::string msg = message + "\n";
       boost::asio::write( socket, boost::asio::buffer(message) );
}
