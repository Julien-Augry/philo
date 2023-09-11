#include "../headers/philo.h"

unsigned long long	ret_now_time(t_rules *rules)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000)
		- rules->start_time);
}

void	get_now_time(t_rules *rules)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	rules->now_time = (time.tv_sec * 1000 + time.tv_usec / 1000)
		- rules->start_time;
}

void	get_now_timeph(t_philo *ph, t_rules *rules)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	ph->now_time = (time.tv_sec * 1000 + time.tv_usec / 1000)
		- rules->start_time;
}
