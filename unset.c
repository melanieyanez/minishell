/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:17:53 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/17 15:26:39 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/* attention à remplacer strncmp strlen et strdup */
/* modifier pour prendre qu'à partir du deuxième token */

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

int	should_unset(char **var, const char *target)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (strncmp(target, var[i], strlen(var[i])) == 0
			&& target[strlen(var[i])] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	new_size(char ***env_var, char **var)
{
	int	i;
	int	n_var;

	i = 0;
	n_var = 0;
	while ((*env_var)[n_var])
		n_var ++;
	while (var[i])
	{
		if (is_in_env(*env_var, var[i]) == 1)
			n_var --;
		i ++;
	}
	return (n_var);
}

void	ft_unset(char ***env_var, char **var)
{
	int		i;
	int		j;
	int		n_var;
	char	**result;

	n_var = new_size(env_var, var);
	result = malloc(sizeof(char *) * (n_var + 1));
	if (!result)
		return ;
	i = 0;
	j = 0;
	while ((*env_var)[i])
	{
		if (should_unset(var, (*env_var)[i]) == 0)
			result[j++] = strdup((*env_var)[i]);
		free((*env_var)[i]);
		i ++;
	}
	result[j] = NULL;
	free(*env_var);
	*env_var = result;
}

/*
int	main(void)
{
	char	**env_var;
	int		i;
	char	*argv[] = {"PATH", "LOGNAME", NULL};

	set_env(&env_var);
	ft_env(&env_var);
	ft_unset(&env_var, argv);
	printf("\n\n\n\n\n\n\n\n");
	ft_env(&env_var);
}
*/
