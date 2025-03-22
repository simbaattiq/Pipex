/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:19:42 by mel-atti          #+#    #+#             */
/*   Updated: 2024/03/13 20:29:58 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_coma(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == 39)
			return (1);
		else if (argv[i] == '-')
			return (0);
		else
			i++;
	}
	return (0);
}

char	**ft_parse(char *argv)
{
	char	**cmd;
	int		i;
	int		flag;

	cmd = NULL;
	i = 0;
	flag = 0;
	while (argv[i] && flag != 1)
	{
		if (argv[i] == 39)
			break ;
		if (argv[i] == '-')
			flag = 1;
		i++;
	}
	return (fill_cmd(cmd, argv, flag));
}

char	**fill_cmd(char **cmd, char *argv, int flag)
{
	if (flag == 1)
	{
		cmd = (char **)malloc (4 * sizeof(char *));
		if (!cmd)
			return (NULL);
		cmd[0] = ft_cmd_find(argv);
		cmd[1] = ft_option_find(argv);
		cmd[2] = ft_str_find(argv);
		cmd[3] = NULL;
	}
	else if (flag == 0)
	{
		cmd = malloc (3 * sizeof (char *));
		if (!cmd)
			return (NULL);
		cmd[0] = ft_cmd_find(argv);
		cmd[1] = ft_str_find(argv);
		cmd[2] = NULL;
	}
	return (cmd);
}

char	*ft_cmd_find(char *argv)
{
	char	*cmd;
	int		i;
	int		start;
	int		end;
	int		flag;

	i = 0;
	start = 0;
	end = 0;
	flag = 0;
	start = i;
	while (argv[i] && flag != 1)
	{
		while (argv[i] && argv[i] != ' ' && argv[i] != '\t' && argv[i] != 39)
		{
			end = i;
			i++;
		}
		if (argv[i] == 39)
			flag = 1;
		i++;
	}
	cmd = ft_substr(argv, start, ((end - start) + 1));
	return (cmd);
}

char	*ft_str_find(char *argv)
{
	char	*cmd;
	int		i;
	int		start;
	int		flag;

	i = 0;
	start = 0;
	flag = 0;
	while (argv[i] && flag == 0)
	{
		while (argv[i] && argv[i] != 39)
			i++;
		while (argv[i] && argv[i] != ' ' && argv[i] != '\t' && argv[i] != 39)
			i++;
		if (argv[i] == 39)
		{
			start = i + 1;
			flag = 1;
		}
		i++;
	}
	if (argv[(ft_strlen(argv)) - 1] == 39)
		i = ft_strlen(argv) - 2;
	cmd = ft_substr(argv, start, ((i - start) + 1));
	return (cmd);
}
