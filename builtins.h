/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:00:18 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/05 15:26:17 by myanez-p         ###   ########.fr       */
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

void	ft_env(char ***env_var);

//exit.c

void	ft_exit(char **str);

//unset.c

void	ft_unset(char ***env_var, char *var);

#endif