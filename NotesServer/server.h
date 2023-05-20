#ifndef SERVER_H
#define SERVER_H
#include <boost/asio.hpp>
#include <vector>
#include "databaseconnector.h"
#include <any> //change later



class Server
{
public:
    Server(boost::asio::io_service & service, int port);
    Server(int port);

     ~Server();
    /*Server Running functions*/

    void startListening();

    void acceptConnetion(boost::asio::socket_base * client);

    /*Server Communications functions*/

    void onGotRequest(const char * message, std::size_t len);

    void sendAnswer(boost::asio::socket_base * client, const char * answer);

    /* Callbacks*/
    void onConnectionBeginConnectionCallback();


    /* Getters */

    void setListenPort(int port ){  _listen_port = port; };


protected:

    boost::asio::io_service _service;

    DatabaseConnector * db_connector_ptr;

    int _listen_port;

    std::vector<boost::asio::socket_base*> clients;

    std::string read_(boost::asio::ip::tcp::socket &socket);
    void send_(boost::asio::ip::tcp::socket &socket, const std::string &message); // поч ссыль?

/*
    void do_accept(){
      acceptor_.async_accept(socket_,
                             [this](boost::system::error_code ec) {
                               if (!ec) {
                                 std::cout << "accept connection\n";

                            //     std::make_shared<Session>(std::move(socket_))->start();
                               }
                               do_accept();
                             });
    }
   boost::asio::ip::tcp::acceptor acceptor_; */
   // boost::asio::ip::tcp::socket socket_;

};

#endif // SERVER_H
