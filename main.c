#include "fillit.h"

int main(int argc, char **argv)
{
	/*
	static int hex_shapes[7][4] =
	{
		{ 0x4640, 0x0E40, 0x4C40, 0x4E00 }, // 'T'
		{ 0x8C40, 0x6C00, 0x8C40, 0x6C00 }, // 'S'
		{ 0x4C80, 0xC600, 0x4C80, 0xC600 }, // 'Z'
		{ 0x4444, 0x0F00, 0x4444, 0x0F00 }, // 'I'
		{ 0x44C0, 0x8E00, 0xC880, 0xE200 }, // 'J'
		{ 0x88C0, 0xE800, 0xC440, 0x2E00 }, // 'L'
		{ 0xCC00, 0xCC00, 0xCC00, 0xCC00 }  // 'O'
	};
	*/
	
	static int shapes[7][4] =
	{
		{ 305, 39, 562, 114 }, // 'T'
		{ 561, 54, 561, 54 }, // 'S'
		{ 306, 99, 306, 99 }, // 'Z'
		{ 4369, 15, 4369, 15 }, // 'I'
		{ 802, 113, 275, 71 }, // 'J'
		{ 785, 23, 547, 116 }, // 'L'
		{ 51, 51, 51, 51 }  // 'O'
	};
	
	int			fd;
	int			ret;
	int			i;
	char		**lines;
	char		*line;
	int			nb;

	nb = 0;
	lines = (char**) malloc(sizeof(char *) * 5);

    if (argc != 2)
        ft_putstr("Wrong number of args.");
    fd = open(argv[1], O_RDONLY);
    ret = 1;
    i = 0;
    while(ret > 0)
    {
		lines[i] = (char *)malloc(5);
        ret = ft_get_next_line(fd, &line);
		if (ret < 1)
            break;
		ft_memcpy(lines[i], line, 4);
		free(line);
		lines[i][4] = '\n';
		i++;
    }
	free(line);
	print_tetrimino(lines);
	int a = (tetrimino_to_bitarray(lines, '#'));
	char **unaligned_tet = int_to_tetrimino(a, '#', '.');
	int b = validate_tetrimino(unaligned_tet, '#', shapes);
	ft_putnbr(a);
	ft_putstr(" is a valid tetrinimo: ");
	ft_putnbr(b);
	ft_putendl("");
	ft_putendl("");
	int c = realign_tetrimino(a);
	char **aligned_tet = int_to_tetrimino(c, '#', '.');
	b = validate_tetrimino(aligned_tet, '#', shapes);
	char**	new_tet = int_to_tetrimino(c, '#', '.');
	print_tetrimino(new_tet);
	ft_putnbr(tetrimino_to_bitarray(new_tet, '#'));
	ft_putstr(" is a valid tetrinimo: ");
	ft_putnbr(b);
	ft_putstr("\n");
	free(lines);
	//printAllShapes(shapes);
    close(fd);
}