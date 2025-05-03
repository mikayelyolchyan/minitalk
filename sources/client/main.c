#include "../../includes/headers/minitalk.h"

#include <stdio.h>

void	print_bits(unsigned char c) {
	for (int i = 7; i >= 0; i--)
	{
		printf("%d", (c >> i) & 1);
	}
}

void	print_utf8_string_bits(const char *str)
{
	while (*str) {
		print_bits((unsigned char)*str);
		printf(" ");
		str++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	print_utf8_string_bits(argv[1]);
	return 0;
}

//int	main(int argc, char **argv)
//{
//	(void)argc;
//	(void)argv;
//		ft_printf("Client\n");
//	return (0);
//}