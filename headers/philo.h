#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define UND 0
# define ARG 1
# define MEM 2
# define GTD 3
# define MUT 4
# define THC 5

typedef struct s_philo
{
	struct s_rules		*r;
	int					nb;
	int					rounds;
	int					r_forkv;
	int					l_forkv;
	pthread_t			is_dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		lasteat_m;
	unsigned long long	ttd;
	unsigned long long	lasteat;
	unsigned long long	now_time;
	unsigned long long	time_laps;
}				t_philo;

typedef struct s_rules
{
	int					nb_philos;
	int					err;
	int					end;
	int					ttd;
	int					tte;
	int					tts;
	int					nb_rounds;
	int					philo_nb;
	int					finish_philos;
	int					time;
	unsigned long long	start_time;
	unsigned long long	now_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex_write;
	pthread_mutex_t		gettime;
	pthread_mutex_t		goodtogo;
	pthread_mutex_t		finish_ph_m;
	pthread_mutex_t		end_m;
	pthread_t			*th_p;
	t_philo				*philos;
}				t_rules;

/* alive.c */
void				*is_he_alive(void *arg);

/* checkargs.c */
int					check_args(char **argv);

/* errors.c */
void				ft_free_all(t_rules *r);
int					ft_error(int msg, t_rules *rules);

/* forks.c */
int					forks_create(t_rules *rules);

/* lunch.c */
int					lunch(t_rules *rules);

/* parsing.c */
t_rules				*ft_parsing(char **argv);

/* philos.c */
int					create_philos_th(t_rules *rules);
int					create_philos(t_rules *rules);

/* routine.c */
void				*philo_routine(void *arg);

/* routinefts.c */
int					action(t_philo *p, char *m, int opt, unsigned long long t);
void				ft_usleep(unsigned long long t, t_philo *p);
void				*threadcreateerror(t_philo *p);
void				ft_return(t_philo *p);

/* time.c */
unsigned long long	ret_now_time(t_rules *rules);
void				get_now_time(t_rules *rules);
void				get_now_timeph(t_philo *ph, t_rules *rules);

/* utils.c */
int					ft_atoi(const char *str);
int					ft_strlen(char *to_check);
void				*ft_calloc(size_t count, size_t size);
void				ft_write_msg(t_philo *p, char *msg);

#endif
