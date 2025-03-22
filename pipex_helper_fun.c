/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:23:37 by mel-atti          #+#    #+#             */
/*   Updated: 2024/03/13 20:23:46 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_option_find(char *argv)
{
	int		flag;
	int		i;
	int		start;
	int		end;
	char	*cmd;

	i = 0;
	flag = 0;
	start = 0;
	end = 0;
	while (argv[i] && end == 0)
	{
		while (argv[i] && argv[i] != '-' && argv[i] != 39)
			i++;
		if (argv[i] == '-')
			start = i;
		if (argv[i] != '-')
			return (NULL);
		end = ft_find_end(argv);
		i++;
	}
	cmd = ft_substr(argv, start, ((end - start) + 1));
	return (cmd);
}

int	ft_find_end(char *argv)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	while (argv[i])
	{
		while (argv[i] && argv[i] != ' ' && argv[i] != '\t' && argv[i] != 39)
			i++;
		end = i;
		if (argv[i] == 39)
		{
			end = i - 1;
		}
		i++;
	}
	return (end);
}

void	*ft_absolute_path_exec(char **cmd, char **env)
{
	if (access(cmd[0], X_OK | F_OK) == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			ft_free_double_p(cmd);
			ft_print_error("execve");
		}
	}
	else
	{
		cmd_error(cmd[0]);
		ft_free_double_p(cmd);
	}
	exit (EXIT_FAILURE);
}

char	**ft_free_double_p(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
