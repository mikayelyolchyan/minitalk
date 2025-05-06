# ifndef MINITALK_H
# define MINITALK_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"

# include "signal.h"
# include "unistd.h"
# include <sys/types.h>

typedef struct s_state
{
	pid_t	client_pid;
	char	current_char;
	int		bit_count;
}	t_state;

#endif