#include "../headers/philo.h"

static int	ft_parsing_c(t_rules *ret)
{
	if (pthread_mutex_init(&ret->mutex_write, NULL)
		|| pthread_mutex_init(&ret->gettime, NULL)
		|| pthread_mutex_init(&ret->goodtogo, NULL)
		|| pthread_mutex_init(&ret->finish_ph_m, NULL)
		|| pthread_mutex_init(&ret->end_m, NULL))
		return (ft_error(MUT, ret));
	return (0);
}

static int	ft_parsing_b(t_rules *ret)
{
	ret->philo_nb = 0;
	ret->forks = NULL;
	ret->th_p = NULL;
	ret->philos = NULL;
	ret->start_time = 0;
	ret->end = 0;
	ret->finish_philos = 0;
	return (ft_parsing_c(ret));
}

t_rules	*ft_parsing(char **argv)
{
	t_rules	*ret;

	ret = malloc(sizeof(t_rules) * 1);
	if (!ret)
	{
		ft_error(MEM, ret);
		return (NULL);
	}
	ret->err = 0;
	ret->nb_philos = ft_atoi(argv[1]);
	ret->ttd = ft_atoi(argv[2]);
	ret->tte = ft_atoi(argv[3]);
	ret->tts = ft_atoi(argv[4]);
	if (argv[5])
		ret->nb_rounds = ft_atoi(argv[5]);
	else
		ret->nb_rounds = -1;
	if (ft_parsing_b(ret))
		return (NULL);
	return (ret);
}
