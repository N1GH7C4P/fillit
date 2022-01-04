#include "fillit.h"

//Exponentti funktio
//Palauttaa base^exponent.
long	ft_pow (int exponent, long base)
{
	int result;

	if (exponent == 0)
		return (1);
	result = 1;
	while (exponent > 1)
	{
		exponent--;
		result = result*base;
	}
	return (result);
}

//Muuttaa binääriluvun integeriksi.
int		bin_to_int(long long n)
{
  int	decimal = 0;
  int	i = 0;
  int	rem;

  while (n != 0)
  {
    rem = n % 10;
    n /= 10;
    decimal += rem * ft_pow(2, i);
    ++i;
  }
  return decimal;
}

//Muuttaa integerin binääriluksi.
long long int_to_bin(int k) {
    if (k == 0)
		return (0);
    if (k == 1) 
		return (1);
    return (k % 2) + 10 * int_to_bin(k / 2);
}

//Muuttaa 4x4 ASCII ruudukon binääriluvuksi, joka talletetaan int -muuttujaan bitwise menetelmällä.
int ft_ascii_to_int(char **tetrimino, char c)
{
	int nb;
	int i;
	int j;

	i = 0;
	nb = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino[i][j] == c)
				nb += ft_pow((i*4 + j + 1), 2);
			j++;
		}
		i++;
	}
	return (nb);
}

//Tulostaa 4x4 ASCII tetriminon standard outputtiin
void ft_print_tetrimino(char **tetrimino)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			ft_putchar(tetrimino[i][j]);
			j++;
		}
		i++;
	}
}

//Muuttaa minkä tahansa luvun 4x4 ASCII kuvauksesksi, 
//muuttaen 1 : 'c' -merkiksi ja 0 : 'empty' -merkiksi.
//Rivit erotetaan toisistaan '\n' merkillä.

char**	hex_to_tetrimino(int shape, char c, char empty)
{
	char **tetrimino = (char**)malloc(sizeof(char*) * 5);

	int y, x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		tetrimino[y] = (char *)malloc(5);
		while (x < 4)
		{
			if (shape & (0x8000 >> (y * 4 + x)))
				tetrimino[y][x] = c;
			else
				tetrimino[y][x] = empty;
			x++;
		}
		tetrimino[y][x] = '\n';
		y++;
	}
	return (tetrimino);
}

//Prints prototypes of all valid tetrinos given in numeric form.

void printAllShapes(int shapes[7][4])
{
	int i;
	int j;
	char **tetrinimo;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			tetrinimo = hex_to_tetrimino(shapes[i][j], '#', '.');
			ft_print_tetrimino(tetrinimo);
			ft_putendl("");
			ft_putnbr(shapes[i][j]);
			ft_putendl("");
			j++;
		}
		i++;
	}
}