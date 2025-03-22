/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_excute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:22:14 by mel-atti          #+#    #+#             */
/*   Updated: 2024/03/13 20:22:28 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_excute_cmd(char *argv, char **env)
{
	char	*path;
	char	**cmd;

	cmd = NULL;
	if (argv[0] == '\0' || !argv)
	{
		ft_putstr_fd("Error: permission denied: \n", 2);
		exit (126);
	}
	if ((ft_check_coma(argv)) == 0)
		cmd = ft_split(argv, ' ');
	else if ((ft_check_coma(argv)) == 1)
		cmd = ft_parse(argv);
	path = ft_cmd_path_search(cmd[0], env);
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
		ft_absolute_path_exec(cmd, env);
	if (!path || execve(path, cmd, env) == -1)
	{
		cmd_error(cmd[0]);
		ft_free_double_p(cmd);
		exit (127);
	}
	exit(EXIT_FAILURE);
}

char	*ft_cmd_path_search(char *cmd, char **env)
{
	int		i;
	char	*full_path;
	char	**sub_paths;

	i = 0;
	full_path = NULL;
	while (env[i] != NULL)
		if ((ft_strncmp(env[i++], "PATH=", 5)) == 0)
			full_path = ft_strdup(env[i - 1] + 5);
	if (full_path == NULL)
		return (NULL);
	sub_paths = ft_split(full_path, ':');
	free(full_path);
	i = 0;
	while (sub_paths[i] != NULL)
	{
		full_path = ft_strjoin2(sub_paths[i], "/");
		full_path = ft_strjoin2(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return ((char *)ft_free_double_p(sub_paths));
}

int	ft_print_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	file_error(char *file)
{
	ft_putstr_fd("Error: ", 2);
	perror(file);
}

void	cmd_error(char *cmd)
{
	ft_putstr_fd("Error: command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
}
