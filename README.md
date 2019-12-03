# POFM
Portable File Manipulator

The purpose of the portable file manipulator (POFM) project was to create a portable system that will perform operations on files without the aid of operating system commands. By not using operating system commands, it ensures that the POFM will be able to be ported onto any operating system on any platform. The functions of the POFM include: create a new file, delete a file, rename a file, copy a file, and move a file from one directory to another. It must also feature a text editor that can perform several functions on text files. The text editor must be able to append text to the end of a file, and insert text in a specified position in the file. The position of the inserted text is indicated by the character count. The text editor must also remove all the text in a text file and show the context of a text file with the number of lines per page being specified via user input. All POFM commands must be able to be described with the aid from a help command. The last of the project requirements are that the POFM’s commands must have exception catching capabilities.  

The basic design of the system was intended to make the POFM mostly stateless. Instead of running a program and interacting within it through the use of commands, the system is accessed through the use of terminal commands. (See General Use for details) This allows parts of the system to be used in the middle of a user’s workflow without needing to run an entire separate program. 

While this stateless design was implemented for the Copy, Create, Move, Remove and Rename functions, a stateless Edit function was not very efficient for the user. To solve this issue, running the Edit function of the POFM launches an editor program which will ask the user for Append, Insert, Clear, or Display commands until the user exits the program. This allows the user to edit the desired file in many different ways in a single session. 


## User Manual

### General User

The general use of the portable file management system is as follows:

```sh
./pofm [command] [option] [targetFile]
```
Where command is the type of command the user would like to use.  The current list of commands are create, remove, rename, copy, move, and edit.  A command is required for the pofm to execute.  See Commands for an in depth description of each command. Target File is the name of the file the user currently wants to operate on.  The Target File is required for the pofm to execute.


### Options

Option is a set an optional flags the user can call to change how the program handles the targetFile.  Multiple options can be set at once and don’t need to be in any particular order.

#### Verbose

The verbose option enables the pofm to explain what is currently happening.  This could include things such as saying when a command successfully executed or if a specific file doesn’t exist. The method for calling the verbose option is:

```sh
./pofm [command] -v [targetFile]
```

#### Force

The force option will not check with user if files need to be rewritten.  Ignore nonexistent files.  The method for called the force option is:

```sh
./pofm [command] -f [targetFile]
```

#### Output

The output option sets the name of the output file.  If the option flag is not set, pofm defaults to the name default.txt.  The option flag takes a filename as an input.

```sh
./pofm [command] -o [outputFile] [targetFile]
```
The outputFile must follow directly after the -o command.

### Commands

#### Create

The create command creates a file given a target file.  If the file exists already the pofm will request if you want to overwrite.  The create command does not use the output flag.

```sh
./pofm create [option] [targetFile]
```

### Rename

The rename command, give a target file, rename it.  The rename command uses the output option.  If the output option is not used the name default.txt is used instead. 

```sh
./pofm rename [option] [targetFile]
```

### Copy

The copy command, give a target file, will make a copy of it.  The copy command will use the output option to name the output file.  If no output is given it will default to default.txt.  The method for called copy is:

```sh
./pofm copy [option] [targetFile]
```

### Move

The move command, given a target file, will move a file from one location to another.  The move command will use the output option to name the output file.  If no output is given, it will default to default.txt.  The method for calling move is:

```sh
./pofm move [option] [targetFile]
```

### Edit

The edit command, given a target file, will open an interface to perform actions on the selected file.  These include: appending to the end of the file, clearing the file, inserting at a given character position, and printing the document.  While printing the document the user can specify how long they want each page to be.  The method for calling edit is:

```sh
./pofm edit [option] [targetFile]
```

The edit interface has four commands that are used for editing a chosen file. The Append command is used for adding text to the end of the chosen file. Input is added one line at a time, and the command can be called several times to add multiple lines to the document. Insert is similar, but also takes a position parameter which determines which character to begin inserting text at. Clear simply deletes all contents of the current file. Print will prompt the user for a number of lines to print at a time, and then allow them to print some or all of the file in sections. Using several of these functions, a user can perform all of the basic text editing operations. 

