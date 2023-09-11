
NAME =			philo
CC =			cc
FLAGS =			-Wall -Wextra -Werror -g -pthread
# FLAGS +=		-fsanitize=thread
RM =			rm -rf
DIR_SRCS =		./srcs/
SRC =	main.c \
		errors.c \
		parsing.c \
		utils.c \
		forks.c \
		lunch.c \
		time.c \
		philos.c \
		checkargs.c \
		routine.c \
		routinefts.c \
		alive.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
OBJS =			$(SRCS:.c=.o)
COMPIL = $(FLAGS) $(OBJS)

all:			$(NAME)
				@echo "Compiled "$(NAME)" successfully!"

$(NAME) :		$(OBJS)
				@$(CC) $(COMPIL) -o $(NAME)

%.o: %.c
				@$(CC) $(FLAGS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

clean:
	$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
