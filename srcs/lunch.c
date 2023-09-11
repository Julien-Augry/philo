#include "../headers/philo.h"

static void	start_lunch_b(t_rules *rules, int i)
{
	pthread_mutex_lock(&rules->end_m);
	rules->end = 1;
	rules->err = THC;
	rules->nb_philos = i;
	pthread_mutex_unlock(&rules->end_m);
}

static int	start_lunch(t_rules *rules)
{
	int				i;
	char			*ret;
	struct timeval	time;

	i = 0;
	pthread_mutex_lock(&rules->goodtogo);
	while (i < rules->nb_philos)
	{
		if (pthread_create(&rules->th_p[i], NULL,
				philo_routine, &rules->philos[i]))
			start_lunch_b(rules, i);
		i++;
	}
	gettimeofday(&time, NULL);
	rules->start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_unlock(&rules->goodtogo);
	i = 0;
	while (i < rules->nb_philos)
	{
		pthread_join(rules->th_p[i], (void **) &ret);
		i++;
	}
	return (0);
}

int	lunch(t_rules *rules)
{
	if (create_philos(rules))
		return (1);
	if (start_lunch(rules))
		return (1);
	return (0);
}
