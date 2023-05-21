#include "requestprocessor.h"
#include "server.h"

RequestProcessor::RequestProcessor()
{

}

Request::Request(HttpServer& server): server(server)
{
    socket.reset(new tcp::socket(server.io_service));
}

void Request::afterRead(const boost::system::error_code &ec, std::size_t bytes_transferred)
{
    // done reading, writes answer (yes, we ignore the request);
    boost::asio::streambuf response;
    std::ostream res_stream(&response);

    // gets daytime string
    std::string time = "make_daytime_string();";

    res_stream << "HTTP/1.0 200 OK\r\n"
               << "Content-Type: text/html; charset=UTF-8\r\n"
               << "Content-Length: " << time.length() + 2 << "\r\n\r\n"
               << time << "\r\n";
    boost::asio::async_write(*socket, response, boost::bind(&Request::afterWrite, shared_from_this(), boost::placeholders::_1, boost::placeholders::_2));
}

void Request::afterWrite(const boost::system::error_code &ec, std::size_t bytes_transferred)
{
    // done writing, closing connection
    socket->close();
}
