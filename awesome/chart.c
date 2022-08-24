# include   "client.h"

void		ft_color_print(int num) {
	if (num < 25)
		printf("%s%s%s", BACKG_WHI, "    ", ASCII_RES);
	else if (num < 50)
		printf("%s%s%s", BACK_YELLOW, "    ", ASCII_RES);
	else if (num < 75)
		printf("%s%s%s", BACK_ORANGE, "    ", ASCII_RES);
	else
		printf("%s%s%s", BACK_RED, "    ", ASCII_RES);
	
}

void 		ft_number_print(
	int		num)
{
  if (num == 100)
    printf(" %d", num);
  else if (num > 9)
    printf("  %d", num);
  else
    printf("   %d", num);
}

int			ft_get_rand()
{
	return (rand() % 101);
}


void		ft_clear_screen()
{
  const	char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


void		ft_shift_array(int* nums, int new)
{
	for (int i = 1; i < 10; i++)
		*(nums + i) = *(nums + i + 1);
	*(nums + 10) = new;
}


void		ft_chart_map(int nums[])
{
	int		grid = 5;
	int		level = 20;

	for (int col = 0; col < 20; col++)
	{
		printf("┃ ");
		for (int row = 1; row < 11; row++)
		{
			if ((nums[row] / 5) >= level){
				ft_color_print(nums[row]);
			}
			else
				printf("    ");
		}
		printf("\n");
		--level;
	}
	printf("┗");
	for (int col = 0; col < 20; col++)
		printf("━━");
	printf("\n ");
	for (int i = 1; i < 11; i++)
		ft_number_print(nums[i]);
	printf("\n");
}


int			print_chart(int *nums, int num)
{
	system("clear");
	ft_shift_array(nums, num);
  ft_chart_map(nums);
	return (0);
}