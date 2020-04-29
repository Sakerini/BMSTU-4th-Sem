#ifndef LAB_01_ERROR_H
#define LAB_01_ERROR_H

#include <iostream>
#include <string>

#define ERROR_OK 0
#define ERROR_INPUT 1
#define ERROR_FOPEN 2
#define ERROR_ARG 3
#define ERROR_MODEL_EMPTY 4
#define ERROR_UNHANDLED_ACTION 5

typedef int err_t;

void handleErr(err_t err, std::string filename, int line, std::string msg);

#endif
