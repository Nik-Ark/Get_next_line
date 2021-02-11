# Get_next_line

Project of 21-School (ECOLE 42)

Purpose of this project is to build program which can take a multiple text files as an input
and output the string on to the console, just before first occurance of the new_line(\n).
When function Get_next_line is called second, third or any other time, it continues write the output from the next line of the file until new_line(\n).
It can maintain multiple text files simulteniosly, and always remember when it stopped write output last time for each file.
For this purpose it builds and uses linked lists, which it frees when text file is read to the end.
When file is read complitly function returns 0(zero) and frees list which stored information about that particular file.
