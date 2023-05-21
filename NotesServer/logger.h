#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <mutex>
#include <map>

enum message_type {
        INFO,
        WARNING,
        ERROR
    };

class Logger
{

public:
    static std::string make_daytime_string()
    {
          std::time_t now = std::time(0);
          return std::ctime(&now);
    }
    void appendMessageToLog(std::string message, message_type type);

    /*Not clone please*/

    Logger(Logger &other) = delete;

    void operator=(const Logger &) = delete;

    static Logger *GetInstance();

protected:
    Logger();
    ~Logger() {

        appendMessageToLog("Server shutting down!!", message_type::INFO);
    }

    void writeLine(std::string line);

    const std::string log_dir = "note_server_logs";
    const std::string filename = "lastlog";
    std::string file_path;
    std::ofstream file;

 private:
     static Logger * pinstance_;
     static std::mutex mutex_;

 };



#endif // LOGGER_H
