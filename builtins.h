/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:00:18 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:46:50 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

//echo.c

void	ft_echo(char **str);

//env.c

void	set_env(char ***env_var);
void	ft_env(char ***env_var);

//exit.c

void	ft_exit(char **str);

//export.c

void	ft_export(char ***env_var, char **var);

//unset.c

void	ft_unset(char ***env_var, char **var);
int		should_unset(char **var, const char *target);

#endif