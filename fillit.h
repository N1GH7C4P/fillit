#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"

// open()
#include <fcntl.h>

// Bit manipulation Macros
#define SetBit(A,k)     ( A |= (1 << k)
#define ClearBit(A,k)   ( A &= ~(1 << k)
#define TestBit(A,k)    ( A & (1 << k)

// Functions
char**		int_to_tetrimino(int shape, char c, char empty);
int			tetrimino_to_bitarray(char **tetrimino, char c);
int			realign_tetrimino(int t);
int			validate_tetrimino(char** tetrimino, char c, int shapes[7][4]);
int			validate_integer(int tetrimino, int shapes[7][4]);

// Extra utility functions
void 		print_tetrimino(char **tetrimino);
void		printAllShapes(int shapes[7][4]);
#endif