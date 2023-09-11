#include "../headers/philo.h"

int	ft_atoi(const char *str)
{
	int	p;
	int	t;

	p = 1;
	t = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p = p * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		t = t * 10 + (*str - 48);
		str++;
	}
	return (t * p);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		lenght;

	lenght = count * size;
	ptr = malloc(lenght);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, lenght);
	return (ptr);
}

void	ft_write_msg(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->r->end_m);
	pthread_mutex_lock(&p->r->mutex_write);
	if (!p->r->end)
	{
		printf("%llu %d %s\n", p->now_time, p->nb, msg);
	}
	pthread_mutex_unlock(&p->r->mutex_write);
	pthread_mutex_unlock(&p->r->end_m);
}
