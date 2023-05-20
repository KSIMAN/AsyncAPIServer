#include "databaseconnector.h"

DatabaseConnector::DatabaseConnector():
is_open(false)
{

}

bool DatabaseConnector::ConnectToDatabase(std::string db_path)
{

    if(is_open)
        closeDatabase();

   //Logic of openin

    return -1;
}

void DatabaseConnector::closeDatabase()
{

}
