/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:52:55 by mel-atti          #+#    #+#             */
/*   Updated: 2024/03/13 16:28:16 by mel-atti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

int		ft_check_coma(char *argv);

int		ft_find_end(char *argv);

char	**fill_cmd(char **cmd, char *argv, int flag);

char	**ft_parse(char *argv);

char	*ft_cmd_find(char *argv);

char	*ft_str_find(char *argv);

char	*ft_option_find(char *argv);

char	**ft_free_double_p(char **s);

void	ft_child_proc(int *pipe_fd, char **av, char **env);

void	ft_parent_proc(int *pipe_fd, char **av, char **env, int pid);

int		ft_excute_cmd(char *argv, char **env);

char	*ft_cmd_path_search(char *cmd, char **env);

char	*find_shell_name(char **env);

void	file_error(char *file);

void	cmd_error(char *cmd);

int		ft_print_error(char *str);

void	*ft_absolute_path_exec(char **cmd, char **env);

#endif
