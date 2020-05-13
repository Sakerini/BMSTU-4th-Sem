#include "Error.h"
#include <string>

namespace mathvector {
    CommonError::CommonError(long timestamp, std::string filename, std::string classname,
                             int line, std::string info) {

        err_msg = "\nFile name: " + filename + "\nClass: " + classname +
                  "\nLine#: " + std::to_string(line) +
                  "\nTime: " + std::to_string(timestamp) + "Info: " + info;
    }

    SizeError::SizeError(long timestamp, std::string filename, std::string classname,
                             int line, std::string info) :
                             CommonError(timestamp,filename,classname, line, info) {};

    const char *CommonError::what() const throw() {
        return err_msg.c_str();
    }

    const char *SizeError::what() const throw() {
        return err_msg.c_str();
    }

    DivisionByZeroError::DivisionByZeroError(long timestamp, std::string filename, std::string classname,
                         int line, std::string info) :
            CommonError(timestamp,filename,classname, line, info) {};

    const char *DivisionByZeroError::what() const throw() {
        return err_msg.c_str();
    }

    BoundariesError::BoundariesError(long timestamp, std::string filename, std::string classname,
                                             int line, std::string info) :
            CommonError(timestamp,filename,classname, line, info) {};

    const char *BoundariesError::what() const throw() {
        return err_msg.c_str();
    }

    MemoryError::MemoryError(long timestamp, std::string filename, std::string classname,
                                     int line, std::string info) :
            CommonError(timestamp,filename,classname, line, info) {};

    const char *MemoryError::what() const throw() {
        return err_msg.c_str();
    }

    WeakPointerError::WeakPointerError(long timestamp, std::string filename, std::string classname,
                             int line, std::string info) :
            CommonError(timestamp,filename,classname, line, info) {};

    const char *WeakPointerError::what() const throw() {
        return err_msg.c_str();
    }
}
