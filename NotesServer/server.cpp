#include "server.h"


void HttpServer::Run()
{
    sThread.reset(new boost::thread(boost::bind(&HttpServer::thread_main, this)));
}

void HttpServer::thread_main()
{
    start_accept();
    io_service.run();
}

void HttpServer::start_accept()
{
    boost::shared_ptr<Request> req (new Request(*this));
    acceptor.async_accept(*req->socket,
                          boost::bind(&HttpServer::handle_accept, this, req, boost::placeholders::_1));
}

void HttpServer::handle_accept(boost::shared_ptr<Request> req, const boost::system::error_code& error)
{
    if (!error)  req->answer();
    start_accept();
}
