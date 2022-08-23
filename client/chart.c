# include   "client.h"

void		ft_color_print(
	char*	color,
	char*	str
) {
	printf("%s%s%s", color, str, ASCII_RES);
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


void		ft_shift_array(
	int*	nums,
	int		new)
{
	for (int i = 1; i < 10; i++)
		*(nums + i) = *(nums + i + 1);
	*(nums + 10) = new;
}


void		ft_chart_map(
	int		nums[])
{
	int		grid = 5;
	int		level = 20;

	for (int col = 0; col < 20; col++)
	{
		printf("┃ ");
		for (int row = 1; row < 11; row++)
		{
			if ((nums[row] / 5) >= level)
				ft_color_print(BACKG_WHI, "    ");
			else
				printf("    ");
		}
		printf("\n");
		--level;
	}
	printf("┗");
	for (int col = 0; col < 20; col++)
		printf("━━");
	printf("\n");
	for (int i = 1; i < 11; i++)
		ft_number_print(nums[i]);
	printf("\n");
}


int			print_chart(int *nums)
{
	srand(time(NULL));
	nums[0] = 0;
	nums[11] = 0;
    for (int i = 1; i < 11; i++)
    	nums[i] = ft_get_rand();

	while(1)
	{
		system("clear");
		ft_shift_array(nums, ft_get_rand());
    	ft_chart_map(nums);
		usleep(1000 * 1000);
	}
	return (0);

}