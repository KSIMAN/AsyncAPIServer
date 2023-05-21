#include "logger.h"
#include <string>
#include <stdlib.h>
#include <iostream>

std::string log_level[3] = {"[INFO] ", "[WARNING]", "[ERROR]"};
std::mutex file_mutex;
Logger* Logger::pinstance_{nullptr};
std::mutex Logger::mutex_;

Logger::Logger()
{
    file_path = log_dir + "/" + filename;
    std::string create_dir = "mkdir " + log_dir;
    std::system(create_dir.c_str());
}

void Logger::writeLine(std::string line)
{
    try {
        file_mutex.lock();

        file.open(file_path, std::ios::app);
        file << line;
        file.close();

    file_mutex.unlock();
    }  catch (const std::ofstream::failure& e) {
        std::string err_mess = "Error to open logFile for writing: " + std::string(e.what());
         std::cout << err_mess;
    }
}

Logger *Logger::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Logger();
    }
    return pinstance_;
}
void Logger::appendMessageToLog(std::string message, message_type type)
{

    std::string log_string = "\n" + log_level[type] + message + "|" + make_daytime_string();
    writeLine(log_string);

}
