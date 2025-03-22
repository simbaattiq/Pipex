/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:30:08 by mel-atti          #+#    #+#             */
/*   Updated: 2024/03/13 20:17:03 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(pipe_fd) == -1)
			ft_print_error("pipe");
		pid = fork();
		if (pid < 0)
			ft_print_error("fork");
		if (pid == 0)
			ft_child_proc(pipe_fd, av, env);
		else if (pid > 0)
			ft_parent_proc(pipe_fd, av, env, pid);
	}
	else
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		ft_putstr_fd("./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit (EXIT_FAILURE);
	}
	return (0);
}

void	ft_child_proc(int *pipe_fd, char **av, char **env)
{
	int		in_fd;

	close(pipe_fd[0]);
	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
	{
		file_error(av[1]);
		exit (EXIT_FAILURE);
	}
	dup2(in_fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(in_fd);
	close(pipe_fd[1]);
	ft_excute_cmd(av[2], env);
}

void	ft_parent_proc(int *pipe_fd, char **av, char **env, int pid)
{
	int		out_fd;
	pid_t	result;
	int		status;

	result = waitpid(pid, &status, WNOHANG);
	if (result == -1)
	{
		ft_print_error("waitpid");
		exit(EXIT_FAILURE);
	}
	out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
	{
		file_error(av[4]);
		exit (EXIT_FAILURE);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(out_fd);
	ft_excute_cmd(av[3], env);
}
