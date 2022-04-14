#include "pipex.h"

int	ft_exit(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
