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

int validate_integer(int tetrimino, int shapes[7][4])
{
	int i;
	int j;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 4)
		{
			if (tetrimino == shapes[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	realign_x(int t)
{
	int i;

	while(t)
	{
	i = 0;
		while (i < 16)
		{
			if (TestBit(t,i)))
				return (t);
			i += 4;
		}
		t = t >> 1;
	}

	return (t);
}

static int	realign_y(int t)
{
	int i;

	while(t)
	{
	i = 0;
		while (i < 4)
		{
			if (TestBit(t,i)))
				return (t);
			i++;
		}
		t = t >> 4;
	}
	return (t);
}

int realign_tetrimino(int t)
{
	int aligned_tet;
	
	aligned_tet = realign_x(t);
	aligned_tet = (realign_y(aligned_tet));
	return (aligned_tet);
}

//Muuttaa minkä tahansa luvun 4x4 ASCII kuvauksesksi, 
//muuttaen 1 : 'c' -merkiksi ja 0 : 'empty' -merkiksi.
//Rivit erotetaan toisistaan '\n' merkillä.

char**	int_to_tetrimino(int shape, char c, char empty)
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
			if (TestBit(shape,(y * 4 + x))))
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
