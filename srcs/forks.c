#include "../headers/philo.h"

int	forks_create(t_rules *rules)
{
	int	i;

	i = 0;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philos);
	if (!rules->forks)
		return (1);
	while (i < rules->nb_philos)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	return (0);
}
