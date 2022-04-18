/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:39 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/04/18 15:59:40 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	data_set(t_data *data, char **av, char **env)
{
	data->path = NULL;
	data->env = env;
	data->path_cmd1 = NULL;
	data->path_cmd2 = NULL;
	data->cmd1_arg = ft_split(av[2], ' ');
	data->cmd2_arg = ft_split(av[3], ' ');
	data->cmd1 = ft_strjoin("/", data->cmd1_arg[0]);
	data->cmd2 = ft_strjoin("/", data->cmd2_arg[0]);
	data->fd_infile = open(av[1], O_RDONLY);
	data->fd_outfile = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (data->fd_infile < 0)
		ft_exit("Error infile");
	if (data->fd_outfile < 0)
		ft_exit("Error outfile");
	if (pipe(data->pipe) != 0)
		ft_exit("Error pipe");
	return (0);
}

static int	path_set(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			data->path = ft_strdup(env[i]);
		i++;
	}
	if (data->path)
	{
		data->path_trim = ft_strtrim(data->path, "PATH=");
		data->path_div = ft_split(data->path_trim, ':');
	}
	else
		ft_exit("PATH not found");
	return (0);
}

static int	ft_exec_cmd1(t_data *data)
{
	int		i;

	i = 0;
	data->pid_child = fork();
	if (data->pid_child == -1)
		ft_exit("Error fork");
	if (data->pid_child == 0)
	{
		dup2(data->fd_infile, STDIN_FILENO);
		dup2(data->pipe[1], STDOUT_FILENO);
		close(data->pipe[0]);
		while (data->path_div[i])
		{
			execve(data->path_cmd1, data->cmd1_arg, data->env);
			data->path_cmd1 = ft_strjoin(data->path_div[i], data->cmd1);
			i++;
		}
		ft_exit("Command not found");
	}
	waitpid(data->pid_child, NULL, 0);
	close(data->fd_infile);
	close(data->pipe[1]);
	return (0);
}

static int	ft_exec_cmd2(t_data *data)
{
	int		i;

	i = 0;
	data->pid_child = fork();
	if (data->pid_child == -1)
		ft_exit("Error fork");
	if (data->pid_child == 0)
	{
		dup2(data->pipe[0], STDIN_FILENO);
		dup2(data->fd_outfile, STDOUT_FILENO);
		close(data->pipe[1]);
		while (data->path_div[i])
		{
			execve(data->path_cmd2, data->cmd2_arg, data->env);
			data->path_cmd2 = ft_strjoin(data->path_div[i], data->cmd2);
			i++;
		}
		ft_exit("Command not found");
	}
	waitpid(data->pid_child, NULL, 0);
	close(data->fd_outfile);
	close(data->pipe[0]);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
		ft_exit("Not the right number of arguments");
	data_set(&data, av, env);
	path_set(&data, env);
	ft_exec_cmd1(&data);
	ft_exec_cmd2(&data);
	ft_free(&data);
	return (0);
}
