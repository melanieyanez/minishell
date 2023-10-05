/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:17:53 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/05 17:42:10 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_in_env(char **env_var, const char *var)
{
	int	i;
	int	j;

	i = 0;
	while (env_var[i])
	{
		j = 0;
		while (env_var[i][j] != '=' && env_var[i][j] != '\0')
			j++;
		if (strncmp(env_var[i], var, j) == 0 && var[j] == '\0')
			return (1);
		i ++;
	}
	return (0);
}

void	ft_unset(char ***env_var, char *var)
{
	int	i;
	int	j;
	int	n;
	char	**result;

	n = 0;
	while ((*env_var)[n])
		n ++;
	if (is_in_env(*env_var, var) == 0)
		return ;
	result = malloc(sizeof(char *) * n);
	i = 0;
	j = 0;
	while ((*env_var)[i])
	{
		if (strncmp((*env_var)[i], var, strlen(var)) == 1)
			result[j] = strdup((*env_var)[i]);
		//free ((*env_var)[i]);
		i ++;
		j ++;
	}
	result[j] = NULL;
	//free(*env_var);
	*env_var = result;
}

int	main(void)
{
	char	**env_var;
	int		i;

	ft_env(&env_var);
	//ft_unset(&env_var, "PATH");
	printf("\n\n\n\n\n\n\n\n");
	//printf("%d\n", is_in_env(env_var, "PATH"));
	i = 0;
	while (env_var[i])
	{
		printf("%s\n", env_var[i]);
		i ++;
	}
}
