/**TODO: Remove this comment before submission
 *
 * For Gabe:
 *
 * The purpose of the create header is to given an output, create a file.
 *
 * Things this program should do:
 *  1. Ignore the input field
 *
 *  2. Confirm that output destination is valid
 *      If not valid, print error and exit
 *
 *      If valid, continue with operation
 *
 *      If output file exits, prompt for overwrite or exit
 *
 *
 *  3. If verbose flag is raised, explain what is happening
 *
 *  4. If force flag is raised, don't prompt for overwrite, just send it bro
 *
 *  5. If no output is given, use default file name.
 */

#pragma once
#include "header.h"

bool create(ARGS arguments) 
{	
	if (doesFileExist(arguments.input_file))
	{
		if (arguments.force)
		{
			FILE* input = fopen(arguments.input_file, "w");
			if (input == NULL)
			{
				printf("Cannot create %s.\n", arguments.input_file);
				exit(1);
			}

			if (arguments.verbose)
				printf("File %s successfully created.\n", arguments.input_file);
			exit(1);
		}

		printf("File %s already exists. Do you want to overwrite it? y/n\n", arguments.input_file);
		char answer = 0;
		scanf("%c", &answer);
        printf("%d\n", answer);
		while (answer != 121 && answer != 110)
		{
            scanf("%c", &answer);
			printf("Invalid response. Please enter y or n\n");
			scanf("%c", &answer);
		}

		if (answer == 110)
			exit(1);
		if (answer == 121)
		{
			FILE* fptr = fopen(arguments.input_file, "w");
			if (fptr == NULL)
			{
				printf("Cannot create %s.\n", arguments.input_file);
				exit(1);
			}

			if (arguments.verbose)
			{
				printf("File %s successfully created.\n", arguments.input_file);
				exit(1);
			}
			else exit(1);
		}
	}
	else
	{
		FILE* input = fopen(arguments.input_file, "w");

		if (input == NULL)
		{
			printf("Cannot create file.\n");
			exit(1);
		}

		if (arguments.verbose)
		{
			printf("File %s successfully created.\n", arguments.input_file);
			exit(1);
		}
		else exit(1);
	}
}
