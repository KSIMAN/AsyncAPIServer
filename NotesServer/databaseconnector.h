#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H
#include <iostream>
#include <mutex>


struct Task
{
  //maybe not need?
};
class DatabaseConnector
{
public:
    DatabaseConnector();

    /*Opens Local database*/
    bool ConnectToDatabase(std::string db_path);

    /*Opens RemoteDabase*/
    bool ConnectToDatabase(std::string ip_addr, int port);

    /*Close database io*/
    void closeDatabase();




    /*Communications with db*/

    /* Add task to database*/
    bool addTask(std::string task_name, std::string user_name, std::string description, int priority, std::string task_deadline);

    /* Removes Task from database */

    bool removeTask(std::string task_name);

    bool editTask();

    /* Check if task exists */

    bool taskExists();



    ~DatabaseConnector();
protected:
    std::mutex db_mutex;
    bool is_open;


};

#endif // DATABASECONNECTOR_H
