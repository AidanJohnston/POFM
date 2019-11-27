#pragma once
#include "header.h"
#include "stdio.h"
#include "fstream"
#include "iostream"
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

int getCharCount(ARGS arguments) 
{
	FILE * fp;
	int count = 0;
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
		
		//printf("%c", c);
		count++;
		
	}
	fclose(fp);
	return count;
}

void clear(ARGS arguments){
    ofstream ofs;
    ofs.open(arguments.input_file, ofstream::out | ofstream::trunc);
    ofs.close();
}

void displayFile(ARGS arguments, int linecount)
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
			if (lineNumber >= linecount) 
			{
				//fclost(fp);
				//return;
				char c = '';
				cout << "Press enter for next page or e to exit";
				cin << c;
				if (c == 'e') 
				{
					fclose(fp);
					return;
				}
			}
		}		
		else
		{
			printf("%c", c);
		}
	}
	fclose(fp);
	cout << "\n";
}

void append(ARGS arguments) 
{
	ofstream file;
	file.open(arguments.input_file, ios_base::app);
	string input = "";
	printf("Enter text to append\n");
	cin >> input;
	file << endl << input;
	file.close();
}

void insert(ARGS arguments)
{
	int max = getCharCount(arguments);

	ifstream file(arguments.input_file);
	string fileString((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	clear(arguments);
	
	string input = "";
	printf("Enter text to insert\n");
	cin >> input;

	printf("Enter index to place text, max index is %d\n", max);
	int index;
	cin >> index;
	while (index > max) 
	{
		cout << "Index was out of range, try again" << endl;
		cin >> index;
	}

	

	fileString.insert(index, input);

	ofstream fileOFStream;
	fileOFStream.open(arguments.input_file, ios_base::app);
	fileOFStream << fileString;
	fileOFStream.close();
}

bool edit(ARGS arguments) 
{

	printf("Opening Editor\n\n");
	bool exit = 0;
	while (!exit)
	{
		
		printf("\nEnter a command\na: Append\nc: Clear File\ni: Insert Text\np: Print File Contents\ne: Exit\n");
		char c;
		cin >> c;
		switch (c) 
		{
			case 'a': append(arguments);
				break;
			case 'c': clear(arguments);
				break;
		    case 'i': insert(arguments);
				break;
			case 'p': 
				int linecount;
				cout << "Enter the number of lines to read\n";
				cin >> linecount;
				displayFile(arguments, linecount);
				break;
			case 'e': exit = true;
				break;
			default: 
				printf("INVALID\n");
				cout << "." << c << ".";
				break;
		}
	}
    return true;
}

