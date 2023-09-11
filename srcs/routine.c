#include "../headers/philo.h"

static int	eat_timei(t_philo *p)
{
	pthread_mutex_lock(p->l_fork);
	action(p, "has taken a fork", 0, 0);
	if (p->r_fork == p->l_fork)
	{
		pthread_mutex_unlock(p->l_fork);
		usleep((p->r->ttd + 1) * 1000);
		return (1);
	}
	pthread_mutex_lock(p->r_fork);
	action(p, "has taken a fork", 0, 0);
	action(p, "is eating", 1, p->r->tte);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
	usleep(950);
	return (0);
}

static int	eat_timep(t_philo *p)
{
	pthread_mutex_lock(p->r_fork);
	action(p, "has taken a fork", 0, 0);
	if (p->l_fork == p->r_fork)
	{
		pthread_mutex_unlock(p->r_fork);
		usleep((p->r->ttd + 1) * 1000);
		return (1);
	}
	pthread_mutex_lock(p->l_fork);
	action(p, "has taken a fork", 0, 0);
	action(p, "is eating", 1, p->r->tte);
	pthread_mutex_unlock(p->r_fork);
	pthread_mutex_unlock(p->l_fork);
	return (0);
}

static int	philo_routine_b(t_philo *p)
{
	if (p->nb % 2)
		eat_timei(p);
	else
		eat_timep(p);
	action(p, "is sleeping", 0, p->r->tts);
	action(p, "is thinking", 0, 0);
	return (0);
}

static void	philo_routine_c(t_philo *p)
{
	if (p->rounds > -1)
	{
		if (!p->rounds--)
		{
			pthread_mutex_lock(&p->r->end_m);
			pthread_mutex_lock(&p->r->finish_ph_m);
			if (p->r->finish_philos == p->r->nb_philos - 1)
				p->r->end = 1;
			p->r->finish_philos++;
			pthread_mutex_unlock(&p->r->finish_ph_m);
			pthread_mutex_unlock(&p->r->end_m);
		}
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *) arg;
	pthread_mutex_lock(&p->r->goodtogo);
	pthread_mutex_unlock(&p->r->goodtogo);
	if (p->nb % 2)
		usleep(5000);
	if (pthread_create(&p->is_dead, NULL, is_he_alive, p))
		return (threadcreateerror(p));
	pthread_mutex_lock(&p->r->end_m);
	while (!p->r->end)
	{
		pthread_mutex_unlock(&p->r->end_m);
		philo_routine_b(p);
		philo_routine_c(p);
		pthread_mutex_lock(&p->r->end_m);
	}
	pthread_mutex_unlock(&p->r->end_m);
	ft_return(p);
	return (NULL);
}
