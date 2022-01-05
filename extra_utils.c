#include "fillit.h"
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
