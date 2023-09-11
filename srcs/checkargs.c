#include "../headers/philo.h"

static int	check_int_max(char *to_check)
{
	if (ft_strlen(to_check) < 10)
		return (1);
	if (ft_strlen(to_check) == 10)
		if (to_check[9] <= '7')
			if (to_check[8] <= '4')
				if (to_check[7] <= '6')
					if (to_check[6] <= '3')
						if (to_check[5] <= '8')
							if (to_check[4] <= '4')
								if (to_check[3] <= '7')
									if (to_check[2] <= '4')
										if (to_check[1] <= '1')
											if (to_check[0] <= '2')
												return (1);
	return (0);
}

static int	check_only_ints(char *to_check)
{
	int	x;

	x = 0;
	while (to_check[x])
	{
		if (to_check[x] < '0' || to_check[x] > '9')
			return (0);
		x++;
	}
	return (1);
}

int	check_args(char **argv)
{
	int	x;

	x = 1;
	while (argv[x])
	{
		if (!check_only_ints(argv[x]))
			return (0);
		if (!check_int_max(argv[x]))
			return (0);
		x++;
	}
	return (1);
}
