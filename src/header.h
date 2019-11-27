#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


class ARGS{
public:
    char* input_file;
    bool verbose;
    bool force;
    bool output;
    char* output_file;
};

bool doesFileExist(char* filename) {
    FILE* fptr = fopen(filename, "r");
    if(fptr) {
        return true;
    }
    else {
        return false;
    }
}


#include "copy.h"
#include "create.h"
#include "edit.h"
#include "move.h"
#include "remove.h"
#include "rename.h"



