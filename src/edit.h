#pragma once
#include "header.h"
#include "stdio.h"
#include <string>
//#include <curses.h>

void displayFile(ARGS arguments)
{
	FILE * fp;
	fp = fopen(arguments.input_file, "a+");
	int c;
	int lineNumber = 0;
	printf(" 0 - ");
	while (1) 
	{
		c = fgetc(fp);
		if (feof(fp)) {
			break;
		}
		if (c == 10)
		{
			lineNumber++;
			printf("\n %d - ", lineNumber);
		}		
		else
		{
			printf("%c", c);
		}
	}
	fclose(fp);
}

void append(ARGS arguments) 
{

	FILE * fp;
	fp = fopen(arguments.input_file, "a+");

	char input[255];
	printf("Enter text to append\n");
	fgets(input, 255, stdin);
	int count = 0;
	while (input[count] != 10) 
	{
		count++;
		printf("%c", input[count]);
	}
	printf("%d", sizeof(char)*count);
	char * tinput = (char*)malloc(sizeof(char)*count);
	count = 0;
	while(input[count] !=10) 
	{
		tinput[count] = input[count];
		printf("%c", tinput[count]);
		count++;
	}
	printf("appending %s\n", tinput);
	fwrite(input, 1, sizeof(tinput), fp);

	fclose(fp);
}

bool edit(ARGS arguments) 
{

	printf("Opening Editor\n\n");
	bool exit = 0;
	while (!exit)
	{
		
		printf("\nEnter a command\na:append\nc:clear file\ni:insert text\np:print file contents\n");
		char c = getchar();
		getchar(); //get the newline out of the buffer
		switch (c) 
		{
			case 'a': append(arguments);
				break;
			case 'c': printf("CLEAR\n");
				break;
			case 'i': printf("INSERT\n");
				break;
			case 'p': displayFile(arguments);
				break;
			case 'e': exit = true;
				break;
			default: printf("INVALID\n");
				break;
		}
	}
	getchar();
    return true;
}

