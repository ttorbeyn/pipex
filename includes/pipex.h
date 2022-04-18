/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:49 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/04/18 15:59:49 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd_infile;
	int		fd_outfile;
	char	*cmd1;
	char	*cmd2;
	char	**cmd1_arg;
	char	**cmd2_arg;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*path;
	char	*path_trim;
	char	**path_div;
	char	**env;
	int		pipe[2];
	pid_t	pid_child;
	pid_t	pid_parent;
}				t_data;

//ft_error
int		ft_exit(char *error);
int		ft_free(t_data *data);

//libft

//ft_split
char	**ft_split(char const *s, char c);

//ft_strtrim
char	*ft_strtrim(char const *s1, char const *set);

//ft_strlem
size_t	ft_strlen(const char *s);

//ft_strdup
char	*ft_strdup(const char *s1);

//ft_strncmp
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//ft_strjoin
char	*ft_strjoin(char const *s1, char const *s2);

#endif
