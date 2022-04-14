#include "pipex.h"

int	data_set(t_data *data, char **av)
{
	data->path = NULL;
	data->cmd1 = ft_strjoin("/", av[2]);
	data->cmd2 = ft_strjoin("/", av[3]);
	data->path_cmd1 = NULL;
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile < 0)
		ft_exit("Error infile");
	data->fd_outfile = open(av[4], O_WRONLY | O_CREAT, 0777);
	if (data->fd_outfile < 0)
		ft_exit("Error outfile");
	return (0);
}

int path_set(t_data *data, char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			data->path = ft_strdup(env[i]);
		i++;
	}
	if (data->path)
	{
		data->path = ft_strtrim(data->path, "PATH=");
		data->path_div = ft_split(data->path, ':');
	}
	else
		ft_exit("PATH not found");
	return (0);
}

int	ft_exec(t_data *data)
{
	int	i;

	i = 0;
	while (execve(data->path_cmd1, NULL, NULL) == -1)
	{
		data->path_cmd1 = ft_strjoin(data->path_div[i], data->cmd1);
		printf("%s\n", data->path_cmd1);
		i++;
	}
	ft_exit("Command not found");
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data data;


	if (ac != 5)
		ft_exit("Not the right number of arguments");
	data_set(&data, av);
	path_set(&data, env);
	ft_exec(&data);
	return (0);
}
