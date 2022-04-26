# ft_printf
## implementation of printf funciton defined in `<stdio.h>` c Library
### usage

clone the repo

open main.c file

call `ft_printf(frmt, argument)` function

open `terminal` go to the repo's directory

run `make compile` command 

then you'll see the output printed.

## This `ft_printf()` function implements `cspdiuxX%` types only,
### And this next flags `-+ .0#` and `width`
#### `width` Flag is fills the rest with `spaces` or `0's` if flag `0` exist.
### `-` Flag prints width after the argument.
### `+` Flag puts `+` befor argument if it's not negative.
### `space` Flag puts space character before argument.
### `.` or `presision` Flag puts `0's` before argument.
