#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
#include <fcntl.h>

#define SetBit(A,k)     ( A |= (1 << k)
#define ClearBit(A,k)   ( A &= ~(1 << k)
#define TestBit(A,k)    ( A & (1 << k)

int			ascii_to_int(char** tetrimino, char c);
long		ft_pow (int exponent, long base);
void		ft_print_tetrimino(char **tetrimino);
int			bin_to_int(long long n);
long long 	int_to_bin(int n);
char**		int_to_tetrimino(int shape, char c, char empty);
void 		print_tetrimino(char **tetrimino);
int			tetrimino_to_bitarray(char **tetrimino, char c);
int			validate_tetrimino(char** tetrimino, char c, int shapes[7][4]);
void		printAllShapes(int shapes[7][4]);
int			realign_x(int t);
int			realign_y(int t);
int			realign_tetrimino(int t);
#endif