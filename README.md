# Non_Exist_File_Detection
This is the program in order to find the files which do not exist from folder as comparing folder with text file 

Compile command:
g++ scan_file_non_exist.cpp -o scan_file_non_exist

line 16 
is the path of output file which content is including the lists which do not exist from folder(don't have to change).

line 19 
is the path of the folder where the file are in(absolute path! require to be changed)
(have to add "/*" at the end of path)
(for instance the path which includes files is "~/Destop/folder", change to "~/Destop/folder/*").

line 25 
is the path of the text file which includes the list of file(absolute path! require to be changed).
