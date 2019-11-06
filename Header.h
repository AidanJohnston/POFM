#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "copy.h"
#include "create.h"
#include "edit.h"
#include "move.h"
#include "remove.h"

typedef struct {

    char* input_file;
    bool verbose;
    bool force;
    bool output;
    char* output_file;
}ARGS;