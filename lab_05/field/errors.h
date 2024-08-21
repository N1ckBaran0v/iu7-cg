#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <exception>
#include <string>

class BaseError : public std::exception {
public:
    BaseError(std::string message) : error_info(message) {}

    virtual const char* what() const noexcept override {
        return error_info.c_str();
    }

    virtual ~BaseError(void) {};
protected:
    std::string error_info;
};

class IncorrectValue : public BaseError {
public:
    IncorrectValue(std::string message) : BaseError(message) {}
};

class IndexOutOfRange : public BaseError {
public:
    IndexOutOfRange(std::string message) : BaseError(message) {}
};

#endif //__ERRORS_H__