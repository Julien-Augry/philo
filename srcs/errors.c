#include "../headers/philo.h"

void	ft_free_all(t_rules *r)
{
	if (r)
	{
		if (r->forks)
			free(r->forks);
		if (r->th_p)
			free(r->th_p);
		if (r->philos)
			free(r->philos);
		free(r);
	}
}

int	ft_error(int msg, t_rules *rules)
{
	ft_free_all(rules);
	if (msg == UND)
		printf("%s\n%s\n", "Error", "Error undefined" );
	if (msg == ARG)
		printf("%s\n%s\n", "Error", "Incorrect arguments");
	if (msg == MEM)
		printf("%s\n%s\n", "Error", "Bad memory allocations");
	if (msg == GTD)
		printf("%s\n%s\n", "Error", "gettimeofday crashed" );
	if (msg == MUT)
		printf("%s\n%s\n", "Error", "Mutex crashed" );
	if (msg == THC)
		printf("%s\n%s\n", "Error", "Thread create fail" );
	return (-1);
}
