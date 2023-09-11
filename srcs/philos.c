#include "../headers/philo.h"

int	create_philos_th(t_rules *rules)
{
	int		nbp;

	nbp = rules->nb_philos;
	rules->th_p = malloc(sizeof(pthread_t) * nbp);
	if (!rules->th_p)
	{
		rules->err = MEM;
		return (1);
	}
	return (0);
}

void	create_one_philo(t_rules *r, t_philo *p, int i)
{
	p->r = r;
	p->nb = i + 1;
	p->rounds = r->nb_rounds;
	p->r_fork = NULL;
	p->l_fork = NULL;
	p->r_forkv = i;
	p->r_fork = &r->forks[i];
	if (p->nb == r->nb_philos)
		p->l_forkv = 0;
	else
		p->l_forkv = i + 1;
	if (p->nb == r->nb_philos)
		p->l_fork = &r->forks[0];
	else
		p->l_fork = &r->forks[i + 1];
	p->ttd = r->ttd;
	p->lasteat = 0;
	p->time_laps = 0;
	pthread_mutex_init(&p->lasteat_m, NULL);
}

int	create_philos(t_rules *rules)
{
	int		nbp;
	int		i;

	nbp = rules->nb_philos;
	i = 0;
	rules->philos = malloc(sizeof(t_philo) * nbp);
	if (!rules->philos)
	{
		rules->err = MEM;
		return (1);
	}
	while (nbp)
	{
		create_one_philo(rules, &rules->philos[i], i);
		nbp--;
		i++;
	}
	return (create_philos_th(rules));
}
