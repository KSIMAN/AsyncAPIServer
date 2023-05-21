#include "server.h"
#include "logger.h"
int main (int argc, char *argv[])
{
   Logger::GetInstance()->appendMessageToLog("Starting server!!", message_type::INFO);
   HttpServer server(8080);
   server.Run();

}
