/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:11:33 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/10 11:55:36 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/* attention à remplacer strdup par ft_strdup */

void	set_env(char ***env_var)
{
	extern char	**environ;
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (environ[count] != NULL)
		count ++;
	*env_var = malloc(sizeof(char *) * (count + 1));
	while (environ[i] != NULL)
	{
		(*env_var)[i] = strdup(environ[i]);
		i ++;
	}
	(*env_var)[i] = NULL;
}

void	ft_env(char ***env_var)
{
	int	i;

	i = 0;
	while ((*env_var)[i] != NULL)
	{
		printf("%s\n", (*env_var)[i]);
		i ++;
	}
}

/*
int	main(void)
{
	char	**env_var;

	set_env(&env_var);
	ft_env(&env_var);
	return (0);
}
*/
