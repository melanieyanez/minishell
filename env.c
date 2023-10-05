/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:11:33 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/05 15:25:27 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_env(char ***env_var)
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
		(*env_var)[i] = environ[i];
		printf("%s\n", (*env_var)[i]);
		i ++;
	}
	(*env_var)[i] = NULL;
}

/*
int	main(void)
{
	char	**env_var;

	ft_env(env_var);
	return (0);
}
*/

// Attention ici je remplis la variable var en même temps que je la print
// Donc ne va pas prendre les modifications
