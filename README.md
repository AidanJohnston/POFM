# POFM
Portable File Manipulator


# COPY

c,cp,copy

pofm copy [OPTIONS] [SOURCE] [DESTINATION]

[OPTIONS]
-i      Promt for overwrites
-r      Rename file to next avaiable name if file name is taken (ie. filename1.txt)
-f      force(overides -n)
-v      explain what is happening
--help  Displays help for the command

[SOURCE]
Source location of file to be copied

[DESTINATION]
Destination location for the copied file

#CREATE
cr,create

pofm create [OPTIONS] [FILENAME]

[OPOTIONS]
-n      promt for overwrites
-f      force(overides -n)
-v      explain what is happening
--help  Display help for the command

[FILENAME]
The name of the file

#DELETE
dl,delete

pofm delete [OPTIONS] [LOCATION]

[OPTIONS]
-f      force
-i      Promt before removal
-r      remove directories and their content as well
-d      remove empty directires
-v      Verbose, explain what is happening
--help  Display help for the command

[LOCATION]
The location can be a file or a directory

# RENAME
rm,rename

pofm rename [OPTIONS] [SOURCE] [FILENAME]

[OPTIONS]

-f      force
-i      Promt before removal
-d      Command is acting on directory
-fi     Command is acting on file
-v      Verbose, explain what is happening
--help  Display help for command

[SOURCE]
File to be renamed

[FILENAME]
New file name

# EDIT
e,ed,edit

pofm edit [OPTIONS] [SOURCE]

[OPTIONS]

--help      Display help for command
[SOURCE]
The file being edited
