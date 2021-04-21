# Get_next_line

## Useful function for parsing strings

This function reads any file, and returns to you string before new_line ('\n'). <br>
In place of new_line you now have '\0'. <br>
This function is efficient when parsing of file string's takes place. <br>
You can work with multiple files at the same time with this function. <br>
Every time you are calling this function, you get next line of the opened file until next '\n'. <br>
You point which file you want to read from with fd (file descriptor). <br>

| Function Returns | File Status |
| ---------------- | ----------- |
| 1                | A line has been read |
| 0                | EOF has been reached |
| -1               | An error occured     |

## Example

```sh
char *line;
line = NULL;
line = get_next_line(fd, line);
...your operations with delivered line)...
free(line);

## Instalation

```sh
cd GNL
gcc -D BUFFER_SIZE=(ANY VALUE OF YOUR CHOICE) get_next_line.c get_next_line_utils.c (YOUR main.c file is needed)
```
