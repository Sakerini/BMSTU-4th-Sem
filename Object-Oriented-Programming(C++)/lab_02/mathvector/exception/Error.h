#ifndef LAB_02_ERROR_H
#define LAB_02_ERROR_H

#include <exception>
#include <string>

namespace mathvector {
    class CommonError : public std::exception {
    public:
        CommonError(long timestamp, std::string filename, std::string classname,
                    int line, std::string info = "Undefined error:");

        virtual const char *what() const throw() override ;

    protected:
        std::string err_msg;
    };

    class SizeError : public CommonError {
    public:
        SizeError(long timestamp, std::string filename, std::string classname,
                    int line, std::string info = "Sizes mismatch:");
        virtual const char *what() const throw();
    };

    class DivisionByZeroError : public CommonError {
    public:
        DivisionByZeroError(long timestamp, std::string filename, std::string classname,
                  int line, std::string info = "Division by zero");
        virtual const char *what() const throw();
    };

    class BoundariesError : public CommonError {
    public:
        BoundariesError(long timestamp, std::string filename, std::string classname,
                            int line, std::string info = "Index is out of boundaries");
        virtual const char *what() const throw();
    };

    class MemoryError : public CommonError {
    public:
        MemoryError(long timestamp, std::string filename, std::string classname,
                        int line, std::string info = "Memory couldn't be allocated");
        virtual const char *what() const throw();
    };

    class WeakPointerError : public CommonError {
    public:
        WeakPointerError(long timestamp, std::string filename, std::string classname,
                    int line, std::string info = "Weak pointer is invalid");
        virtual const char *what() const throw() override;
    };


}

#include "Error.hpp"

#endif //LAB_02_ERROR_H
