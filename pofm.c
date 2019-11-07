#include "header.h"

int main(int argc, char* argv[]) {

	ARGS arguments;

	//DEFAULT VALUES

    arguments.input_file = "-";
	arguments.verbose = false;
	arguments.force = false;
	arguments.output = false;
	arguments.output_file = "-";


	//ERROR FLAGS
	bool flagGlobalHelp = false;
	bool flagOutputFileWrong = false;
	bool flagNoCommandType = false;
	bool flagNoInputFile = false;

	int commandType = -1;

	bool argumentsTaken[argc];
    memset( argumentsTaken, 0, argc*sizeof(bool));
	argumentsTaken[0] = true;


	if(argc > 1) {
        //CHECKING FOR COMMAND TYPE
        if (strcmp(argv[1], "copy") == 0) {
            commandType = 0;
            argumentsTaken[1] = true;
        }
        if (strcmp(argv[1], "create") == 0) {
            commandType = 1;
            argumentsTaken[1] = true;
        }
        if (strcmp(argv[1], "remove") == 0) {
            commandType = 2;
            argumentsTaken[1] = true;
        }
        if (strcmp(argv[1], "rename") == 0) {
            commandType = 3;
            argumentsTaken[1] = true;
        }
        if (strcmp(argv[1], "edit") == 0) {
            commandType = 4;
            argumentsTaken[1] = true;
        }
        if (strcmp(argv[1], "move") == 0) {
            commandType = 5;
            argumentsTaken[1] = true;
        }
        if (commandType == -1) {
            flagNoCommandType = true;
        }


        //CHECKING OPTIONS
        for (int i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-v") == 0) {
                arguments.verbose = true;
                argumentsTaken[i] = true;
            }
            if (strcmp(argv[i], "-o") == 0) {
                arguments.output = true;
                argumentsTaken[i] = true;
                if (argv[i + 1] != NULL) {
                    arguments.output = true;
                    arguments.output_file = argv[i + 1];

                    argumentsTaken[i + 1] = true;
                } else {
                    flagOutputFileWrong = true;
                }
            }
            if (strcmp(argv[i], "-f") == 0) {
                arguments.force = true;
                argumentsTaken[i] = true;
            }
            if (strcmp(argv[i], "--help") == 0) {
                flagGlobalHelp = true;
                argumentsTaken[i] = true;
            }

        }

        //CHECKING INPUT FILE
        //CHECKING IF LAST VALUE HAS NOT BEEN TAKEN BY OPTIONS
        if (argumentsTaken[argc - 1] == false) {
            arguments.input_file = argv[argc -1];
            argumentsTaken[argc - 1] = true;
        } else {
            flagNoInputFile = true;
        }
    }
	else{
	    flagGlobalHelp = true;
	}
	//PRINTING ERRORS/HELP
	if(flagGlobalHelp) {
		printf("POFM - A robust portable file managment system.\n"
		       "[COMMAND TYPES]\n"
		       "POFM has five diffrent command types:\n\n"
		       "[COPY]\n"
		       "Copy a file\n"
		       "Usage: 'pofm copy [OPTIONS] [TARGET FILE]'\n\n"
		       
		       "[CREATE]\n"
		       "Create a file\n"
		       "Usage: 'pofm create [OPTIONS]'\n\n"

		       "[REMOVE]\n"
		       "Remove a file\n"
		       "Usage: 'pofm remove [OPTIONS] [TARGET FILE]'\n\n"

		       "[MOVE]\n"
		       "Moves a file from one location to another\n"
		       "Usage: 'pofm move [OPTIONS] [TARGET FILE]'\n\n"

		       "[EDIT]\n"
		       "Opens a robust text editor\n"
		       "Usage 'pofm edit [OPTIONS] [TARGET FILE]'\n\n"

		       "[OPTIONS]\n\n"
		       "\t-v\t Verbose: explain what is happneing\n"
		       "\t-f\t Force: force the command, don't ask before overwriting\n"
		       "\t-o [FILE]\t Output: The Output location/filename of the copy command, if not called the default location/filename will be used.\n\n"
			);
	}
	if(flagOutputFileWrong){
		printf("No output file given, try --help for more information\n");
	}
	if(flagNoCommandType) {
		printf("No command type given, try --help for list of command types\n");
	}
	if(flagNoInputFile && !flagGlobalHelp) {
		printf("No input file given, try --help for pofm usage\n");
	}

	if(flagGlobalHelp + flagOutputFileWrong + flagNoCommandType + flagNoInputFile == 0) {
	   if(commandType == 0) {
	       copy(arguments);
	   }
	   if(commandType == 1) {
	       create(arguments);
	   }
	   if(commandType == 2) {
	       removeFile(arguments);
	   }
	   if(commandType == 3) {
	       renameFile(arguments);
	   }
	   if(commandType == 4) {
	       edit(arguments);
	   }
	   if(commandType == 5) {
	       move(arguments);
	   }
	}
}
