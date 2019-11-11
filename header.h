#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <zconf.h>

#include "copy.h"
#include "create.h"
#include "edit.h"
#include "move.h"
#include "remove.h"
#include "rename.h"

bool doesFileExist(char* filename) {
    if(access(filename, F_OK) != -1) {
        return true;
    }
    else{
        return false;
    }
}


