#pragma once
#include "header.h"
typedef struct {
    char* input_file;
    bool verbose;
    bool force;
    bool output;
    char* output_file;
}ARGS;

bool copy(ARGS arguments) {
    printf("%s\n", arguments.input_file);
}