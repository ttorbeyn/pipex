#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_data
{
	int		fd_infile;
	int		fd_outfile;
	char	*path;
	char	**path_div;
}				t_data;

//ft_error
int		ft_exit(char *error);


//libft

//ft_split
char	**ft_split(char const *s, char c);

//ft_strtrim
char	*ft_strtrim(char const *s1, char const *set);


//ft_strlem
size_t	ft_strlen(const char *s);

#endif
