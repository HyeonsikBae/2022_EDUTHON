# include	"client.h"

void		ft_color_print(int num, char* str)
{
	if (num < 25)
		printf("%s%s%s", BACKG_WHI, str, ASCII_RES);
	else if (num < 50)
		printf("%s%s%s", BACK_YELLOW, str, ASCII_RES);
	else if (num < 75)
		printf("%s%s%s", BACK_ORANGE, str, ASCII_RES);
	else
		printf("%s%s%s", BACK_RED, str, ASCII_RES);
}

void 		ft_number_print(int num)
{
	if (num == 100)
		printf(" %d", num);
	else if (num > 9)
		printf("  %d", num);
	else
		printf("   %d", num);
}

void		ft_shift_array(int* nums, int new)
{
	for (int i = 1; i < 10; i++)
		*(nums + i) = *(nums + i + 1);
	*(nums + 10) = new;
}
