#ifndef SERVER_H
#define SERVER_H
#include <vector>

#include "databaseconnector.h"
#include "requestprocessor.h"

#include <iostream>
#include <ostream>
#include <istream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include <boost/thread.hpp>

using boost::asio::ip::tcp;

class HttpServer
{
    public:

    HttpServer(unsigned int port) : acceptor(io_service, tcp::endpoint(tcp::v4(), port)) {};
    ~HttpServer() { if (sThread) sThread->join(); }

    void Run();

    boost::asio::io_service io_service;

    private:
    tcp::acceptor acceptor;
    boost::shared_ptr<boost::thread> sThread;

    void thread_main();
    /* Callbacks*/

    void start_accept();

    void handle_accept(boost::shared_ptr<Request> req, const boost::system::error_code& error); //handle accept

};


#endif // SERVER_H
