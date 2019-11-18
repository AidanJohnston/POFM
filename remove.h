/**TODO: Remove this comment before submission
 *
 * For Gabe:
 *
 * The purpose of the move header is to given an input, deleted a file.
 *
 * This should be very close to copy.h, only the original file is removed
 *
* Things this program should do:
 *  1. Confirm the input file is valid, ie. exists.
 *      If file doesn't exists print error and then exit
 *
 *      If file exists continue with operation
 *
 *  3. If verbose flag is raised, explain what is happening
 */


#pragma once
#include "header.h"

bool removeFile(ARGS arguments) {

    bool flag = false;
    char option;

    if(doesFileExist(arguments.input_file)) {
        if (arguments.force) {
            remove(arguments.input_file);
            if (arguments.verbose)
                printf("The file %s was removed.\n", arguments.input_file);
        }
        else {
            printf("Are you sure you want to remove %s\n", arguments.input_file);
            scanf("%c", &option);

            while(!flag) {
                if(option == "y" || option == "Y" || option == "n" || option == "N") {
                    flag = true;
                }
                else {
                    printf("Unknown answer, please try again: \n");
                    scanf("%c", &option);
                }
            }
            if(option == "y" || option == "Y") {
                remove(arguments.input_file);
                if(arguments.verbose)
                    printf("Removed %s\n", arguments.input_file);
            }
            else if(arguments.verbose) {
                printf("Will not remove %s\n");
            }
        }
    }
    else if(arguments.verbose)
        printf("The file %s doesn't exist, could not remove.\n", arguments.input_file);
}