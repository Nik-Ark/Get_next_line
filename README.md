# Get_next_line

## Useful function for parsing strings

This function reads any file, and returns to you string before new_line ('\n'). <br>
In place of new_line you now have '\0'. <br>
This function is efficient when parsing of file string's takes place. <br>

| Function Returns | File Status |
| ---------------- | ----------- |
| 1                | A line has been read |
| 0                | EOF has been reached |
| -1               | An error occured     |

## Instalation

```sh
cd GNL
gcc -D BUFFER_SIZE=(ANY VALUE OF YOUR CHOICE) get_next_line_bonus.c get_next_line_utils_bonus.c (YOUR main.c file is needed)
```
