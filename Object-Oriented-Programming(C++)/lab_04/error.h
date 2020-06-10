#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>
#include <sstream>
#include <string.h>

class BaseException : public std::exception
{
private:
    const char* file { nullptr };
    int line { 0 };
    const char* func { nullptr };
    const char* info { nullptr };
    char* msg { nullptr };

public:
    BaseException(const char* file_, int line_, const char* func_, const char* info_ = "") :
        //std::exception(msg),
        file (file_),
        line (line_),
        func (func_),
        info (info_)
    {
    }

    virtual ~BaseException()
    {
        free(msg);
    }
    const char* what() noexcept
    {
        std::stringstream msg;
        msg << "Error in: [" << file << "::" << line << "] function: " << func << " --> " << info << std::endl;
        free(this->msg);
        this->msg = strdup(msg.str().c_str());

        return this->msg;
    }

    const char* get_file() const
    {
        return file;
    }

    int get_line() const
    {
        return line;
    }

    const char* get_func() const
    {
        return func;
    }

    const char* get_info() const
    {
        return info;
    }
};

class UnknownStateException : public BaseException {
public:
    UnknownStateException(const char* file_, int line_, const char* func_)
    : BaseException(file_, line_, func_, "Unknown state exception")
    {
    }
};

class OutOfBoundsException : public BaseException {
public:
    OutOfBoundsException(const char* file_, int line_, const char* func_)
    : BaseException(file_, line_, func_, "Floor out of bounds exception")
    {
    }
};

#endif // ERROR_H
