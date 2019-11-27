#pragma once
#include "header.h"
#include "stdio.h"
#include "fstream"
#include "iostream"
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

void clear(ARGS arguments){
    ofstream ofs;
    ofs.open(arguments.input_file, ofstream::out | ofstream::trunc);
    ofs.close();
}

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
	ofstream file;
	file.open(arguments.input_file, ios_base::app);
	string input = "";
	printf("Enter text to append\n");
	getline(cin, input);
	file << endl << input;
	file.close();
}

void insert(ARGS arguments)
{
	ifstream file(arguments.input_file);
	string fileString((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	clear(arguments);
	
	string input = "";
	printf("Enter text to insert\n");
	getline(cin, input);

	printf("Enter index to place text\n");
	int index;
	cin >> index;

	fileString.insert(index, input);

	ofstream fileOFStream;
	fileOFStream.open(arguments.input_file, ios_base::app);
	fileOFStream << endl << fileString;
	fileOFStream.close();
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
			case 'c': clear(arguments);
				break;
		    case 'i': insert(arguments);
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

