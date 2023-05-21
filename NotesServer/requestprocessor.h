#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H
#include <iostream>
#include <ostream>
#include <istream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

#include "databaseconnector.h"

class HttpServer;

class Request : public boost::enable_shared_from_this<Request>
{


    // member variables
    HttpServer& server;
    boost::asio::streambuf request;

    DatabaseConnector * db_connector_ptr;

    void afterRead( const boost::system::error_code& ec, std::size_t bytes_transferred);

    void afterWrite( const boost::system::error_code& ec, std::size_t bytes_transferred);

    public:

        boost::shared_ptr<boost::asio::ip::tcp::socket> socket;
        Request(HttpServer& server);
        void answer()
        {
            if (!socket) return;

            // reads request till the end
            boost::asio::async_read_until(*socket, request, "\r\n\r\n",
                                          boost::bind(&Request::afterRead, shared_from_this(), boost::placeholders::_1, boost::placeholders::_2));
        }

};
class RequestProcessor
{
    RequestProcessor();
    ~RequestProcessor();
};


#endif // REQUESTPROCESSOR_H
