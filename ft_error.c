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

#include "pipex.h"

int	ft_exit(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->path_div[i])
		free(data->path_div[i++]);
	free(data->path_div);
	i = 0;
	while (data->cmd1_arg[i])
		free(data->cmd1_arg[i++]);
	free(data->cmd1_arg);
	i = 0;
	while (data->cmd2_arg[i])
		free(data->cmd2_arg[i++]);
	free(data->cmd2_arg);
	free(data->cmd1);
	free(data->cmd2);
	free(data->path);
	free(data->path_trim);
	free(data->path_cmd1);
	free(data->path_cmd2);
	return (0);
}
