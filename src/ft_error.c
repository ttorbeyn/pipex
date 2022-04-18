/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttorbeyn <ttorbeyn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:59:20 by ttorbeyn          #+#    #+#             */
/*   Updated: 2022/04/18 15:59:22 by ttorbeyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_exit(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

static int	ft_free2(t_data *data)
{
	int	i;

	if (data->path_div)
	{
		i = 0;
		while (data->path_div[i])
			free(data->path_div[i++]);
		free(data->path_div);
	}
	if (data->cmd1_arg)
	{
		i = 0;
		while (data->cmd1_arg[i])
			free(data->cmd1_arg[i++]);
		free(data->cmd1_arg);
	}
	if (data->cmd2_arg)
	{
		i = 0;
		while (data->cmd2_arg[i])
			free(data->cmd2_arg[i++]);
		free(data->cmd2_arg);
	}
	return (0);
}

int	ft_free(t_data *data)
{
	ft_free2(data);
	if (data->cmd1)
		free(data->cmd1);
	if (data->cmd2)
		free(data->cmd2);
	if (data->path)
		free(data->path);
	if (data->path_trim)
		free(data->path_trim);
	if (data->path_cmd1)
		free(data->path_cmd1);
	if (data->path_cmd2)
		free(data->path_cmd2);
	return (0);
}
