#include "../headers/philo.h"

static void	geterror(t_philo *p)
{
	pthread_mutex_lock(&p->r->end_m);
	p->r->end = 1;
	pthread_mutex_unlock(&p->r->end_m);
	pthread_mutex_lock(&p->r->mutex_write);
	printf("%s\n%s\n", "Error", "gettimeofday crashed");
	pthread_mutex_unlock(&p->r->mutex_write);
	return ;
}

static void	rest_in_peace(t_philo *p)
{
	if (!p->r->end)
		printf("%llu %d died\n", p->time_laps, p->nb);
}

static void	is_he_alive_c(t_philo *p)
{
	pthread_mutex_lock(&p->r->end_m);
	pthread_mutex_lock(&p->lasteat_m);
	if (!p->r->end && (p->lasteat < p->time_laps)
		&& p->ttd <= p->time_laps - p->lasteat)
	{
		pthread_mutex_lock(&p->r->mutex_write);
		rest_in_peace(p);
		pthread_mutex_unlock(&p->r->mutex_write);
		p->r->end = 1;
	}
	pthread_mutex_unlock(&p->lasteat_m);
	pthread_mutex_unlock(&p->r->end_m);
}

static void	is_he_alive_b(t_philo *p, struct timeval time)
{
	p->time_laps = (time.tv_sec * 1000 + time.tv_usec / 1000)
		- p->r->start_time;
}

void	*is_he_alive(void *arg)
{
	struct timeval	time;
	t_philo			*p;

	p = (t_philo *)arg;
	usleep(p->r->ttd * 1000 + 1);
	pthread_mutex_lock(&p->r->end_m);
	while (!p->r->end)
	{
		pthread_mutex_unlock(&p->r->end_m);
		if (gettimeofday(&time, NULL))
			geterror(p);
		is_he_alive_b(p, time);
		is_he_alive_c(p);
		usleep(5000);
		pthread_mutex_lock(&p->r->end_m);
	}
	pthread_mutex_unlock(&p->r->end_m);
	return (NULL);
}
