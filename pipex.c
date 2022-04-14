#include "pipex.h"

int	data_set(t_data *data, char **av)
{
	data->path = NULL;
	data->cmd1 = av[3];
	data->cmd2 = av[4];
	data->fd_infile = open(av[1], O_RDONLY);
	if (data->fd_infile < 0)
		ft_exit("Error file1");
	data->fd_outfile = open(av[4], O_WRONLY | O_CREAT, 0777);
	if (data->fd_outfile < 0)
		ft_exit("Error file2");
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

int	main(int ac, char **av, char **env)
{
	t_data data;

	if (ac != 5)
		ft_exit("Too few arguments");
	data_set(&data, av);
	path_set(&data, env);
	return (0);
}
