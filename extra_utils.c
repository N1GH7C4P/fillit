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
int ascii_to_int(char **tetrimino, char c)
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
void print_tetrimino(char **tetrimino)
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
	ft_putendl("");
}

//Prints prototypes of all valid tetrinos given in numeric form.

void printAllShapes(int shapes[7][4])
{
	int i;
	int j;
	char **tetrinimo;

	i = 0;
	while(i < 7)
	{
		j = 0;
		while(j < 4)
		{
			tetrinimo = int_to_tetrimino(shapes[i][j], '#', '.');
			ft_putnbr(shapes[i][j]);
			ft_putendl("");
			print_tetrimino(tetrinimo);		
			j++;
		}
		ft_putendl("");
		i++;
	}
}
