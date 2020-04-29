#include "Error.h"

void handleErr(err_t err, std::string filename, int line, std::string msg) {

    std::string info = filename + " [" + std::to_string(line) + "]-> ";

    switch (err) {
        case ERROR_OK:
            std::cerr << info << "SUCCESS! " << msg << std::endl;
            break;
        case ERROR_INPUT:
            std::cerr << info << "Input Error! " << msg << std::endl;
            break;
        case ERROR_FOPEN:
            std::cerr << info << "Can not open file! " << msg << std::endl;
            break;
        case ERROR_ARG:
            std::cerr << info << "Incorrect argument! " << msg << std::endl;
            break;
        case ERROR_MODEL_EMPTY:
            std::cerr << info << "Empty model! " << msg << std::endl;
            break;
        case ERROR_UNHANDLED_ACTION:
            std::cerr << info << "Unhandled action! " << msg << std::endl;
            break;
        default:
            std::cerr << info << "Unhandled Error! " << msg << std::endl;
    }
}

