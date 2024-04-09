#ifndef invalidNValueException_H
#define invalidNValueException_H

#include<cstring>
#include<stdexcept>
class invalidNValueException : std::exception
{
private:
    char* _msg;
public:
    invalidNValueException() = delete;

    invalidNValueException(const invalidNValueException&) = delete;
    invalidNValueException& operator=(const invalidNValueException&) = delete;

    invalidNValueException(const invalidNValueException&&) = delete;
    invalidNValueException& operator=(const invalidNValueException&&) = delete;

    ~invalidNValueException(){
        delete _msg;
    }

    explicit invalidNValueException(const char* msg){
        _msg = new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }

    std::string what(){
        return _msg;
    }
};

#endif // invalidNValueException_H
