#ifndef DATAEMPTYEXCEPTION_H
#define DATAEMPTYEXCEPTION_H

#include<cstring>
#include<stdexcept>
class dataEmptyException : std::exception
{
private:
    char* _msg;
public:
    dataEmptyException() = delete;

    dataEmptyException(const dataEmptyException&) = delete;
    dataEmptyException& operator=(const dataEmptyException&) = delete;

    dataEmptyException(const dataEmptyException&&) = delete;
    dataEmptyException& operator=(const dataEmptyException&&) = delete;

    ~dataEmptyException(){
        delete _msg;
    }

    explicit dataEmptyException(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    std::string what(){
        return _msg;
    }
};

#endif // DATAEMPTYEXCEPTION_H
