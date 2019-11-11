/**TODO: Remove this comment before submission
 *
 * For Gabe:
 *
 * The purpose of the copy header is to given an input and an output, copy a file.
 *
 * Things this program should do:
 *  1. Confirm the input file is valid, ie. exists.
 *      If file doesn't exists print error and then exit
 *
 *      If file exists continue with operation
 *
 *  2. Confirm that output destination is valid
 *      If not valid, print error and exit
 *
 *      If valid, continue with operation
 *
 *      If output file exits, prompt for overwrite or exit
 *
 *  3. If verbose flag is raised, explain what is happening
 *
 *  4. If force flag is raised, don't prompt for overwrite, just send it bro
 *
 *  5. If no output is given, use default file name. File should have the same type as the input file
 *
 */


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