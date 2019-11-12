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
	FILE *fptr;
	char answer;

	if (arguments.force)
	{
		fptr = fopen(arguments.input_file, "w");
		exit(1);
	}
		
	if (doesFileExist(arguments.input_file)) 
	{
		printf("File %s already exists. Do you want to overwrite it? y/n\n" &arguments.input_file);
		scanf("&c", answer);
		while(answer =! 'y' || 'n')
		{
			printf("Invalid response. Please enter y/n");
			scanf("&c", answer);
		}

		if (answer == 'n')
			exit(1);
		if (answer == 'y')
			fptr = fopen(arguments.input_file, "w");
	}
	if (fptr == NULL)
	{
		printf("Cannot create file.\n");
		exit(1);
	}

	if (arguments.verbose)
		printf("File %s successfully created.\n", arguments.input_file);
	else exit(1);
}
