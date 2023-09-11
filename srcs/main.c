#include "../headers/philo.h"

int	main(int argc, char **argv)
{
	t_rules	*rules;

	if (argc == 5 || argc == 6)
	{
		if (!check_args(argv))
			return (ft_error(ARG, NULL));
		rules = ft_parsing(argv);
		if (!rules)
			return (-1);
		if (forks_create(rules))
			return (ft_error(MEM, rules));
		if (lunch(rules))
			return (ft_error(rules->err, rules));
		if (rules->err)
			return (ft_error(rules->err, rules));
		ft_free_all(rules);
		return (0);
	}
	return (ft_error(ARG, NULL));
}
