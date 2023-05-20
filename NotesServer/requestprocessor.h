#ifndef REQUESTPROCESSOR_H
#define REQUESTPROCESSOR_H

class RequestProcessor
{
public:
    RequestProcessor();

    /*Processes request and returns result for client*/
    const char* processRequest(const char* message);

};

#endif // REQUESTPROCESSOR_H
