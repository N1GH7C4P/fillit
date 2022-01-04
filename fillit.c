#include "fillit.h"

//Muuuttaa 4x4 ASCII kuvauksen tetriminosta binääriluvuksi
//bitwise menetelmällä hyödyntäen INT bitarray -tietorakennetta.
//http://www.mathcs.emory.edu/%7Echeung/Courses/255/Syllabus/1-C-intro/bit-array.html

int tetrimino_to_bitarray(char **tetrimino, char c)
{
	int A;	
	int y;
	int x;

	A = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetrimino[y][x] == c)
				SetBit(A,(4*y+x)));
			x++;
		}
		y++;
	}
	return A;
}

// Vertaa 4x4 ASCII tetriminoa laillisiin tetriminoihin 
// ja palauttaa 1 mikäli tetrimino on laillinen tai 0 mikäli se on laiton.

int validate_tetrimino(char** tetrimino, char c, int shapes[7][4])
{
	int i;
	int j;

	int array = tetrimino_to_bitarray(tetrimino, c);

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 4)
		{
			if (array == shapes[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
