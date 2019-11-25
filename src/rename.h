/**TODO: Remove this comment before submission
 *
 * For Gabe:
 *
 * The purpose of the move header is to given an input and an output, rename a file.
 *
 * This should be very close to copy.h, only the original file is removed
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

bool renameFile(ARGS arguments) {
    char option = 0;
    bool flag = false;
    if(doesFileExist(arguments.input_file)) {
        if(arguments.force) {
            FILE* input = fopen(arguments.input_file, "r");
            if(input == NULL)
                printf("Couldn't open %s\n", arguments.input_file), exit(1);

            FILE* output =  fopen(arguments.output_file, "w");
            if(output == NULL)
                printf("Couldn't open %s\n", arguments.output_file), exit(1);

            char ch = "";
            while ((ch = fgetc(input)) != EOF)
                fputc(ch, output);

            remove(input);
            fclose(input);
            fclose(output);

            if(arguments.verbose)
                printf("Renamed file\n");
        }
        else {
            if(arguments.output) {
                if(doesFileExist(arguments.output_file)) {
                    printf("Are you sure you want to rename %s?  %s already exist. (y/n)\n", arguments.input_file, arguments.output_file);
                    scanf("%c", &option);

                    while(!flag) {
                        if(option == 121 || option == 110) {
                            flag = true;
                        }
                        else {
                            scanf("%c", &option);
                            printf("Unknown answer, please try again: (y/n)\n");
                            scanf("%c", &option);
                        }
                    }
                    if(option == 121) {
                        FILE* input = fopen(arguments.input_file, "r");
                        if(input == NULL)
                            printf("Couldn't open %s\n", arguments.input_file), exit(1);

                        FILE* output = fopen(arguments.output_file, "w");
                        if(output == NULL)
                            printf("Couldn't open file\n"), exit(1);

                        char ch = "";
                        while((ch = fgetc(input)) != EOF)
                            fputc(ch, output);

                        remove(input);
                        fclose(input);
                        fclose(output);

                        if(arguments.verbose)
                            printf("Rename the file\n");
                    }
                    else if(arguments.verbose) {
                        printf("Wont rename the file\n");
                    }
                }
                else {
                    FILE* input = fopen(arguments.input_file, "r");
                    if(input == NULL)
                        printf("Couldn't open %s\n", arguments.input_file), exit(1);

                    FILE* output = fopen(arguments.output_file, "w");
                    if(output == NULL)
                        printf("Couldn't open file\n"), exit(1);

                    char ch = "";
                    while((ch = fgetc(input)) != EOF)
                        fputc(ch, output);

                    remove(input);
                    fclose(input);
                    fclose(output);

                    if(arguments.verbose)
                        printf("Rename the file\n");
                }
            }
            else {
                FILE *input = fopen(arguments.input_file, "r");
                if (input == NULL)
                    printf("Couldn't open %s\n", arguments.input_file), exit(1);

                FILE *output = fopen("default.txt", "w");
                if (output == NULL)
                    printf("Couldn't open file\n"), exit(1);

                char ch = "";
                while ((ch = fgetc(input)) != EOF)
                    fputc(ch, output);

                remove(input);
                fclose(input);
                fclose(output);

                if (arguments.verbose)
                    printf("Renamed the file\n");
            }
        }
    }
    else if(arguments.verbose) {
        printf("The file %s doesn't exist, could not rename.\n", arguments.input_file);
    }
}
