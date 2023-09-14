/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:44:07 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/14 18:30:24 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	g_var;

struct s_env_data
{
	char	*name;
	char	*value;
};

void	env(struct s_env_data *env)
{
	int		i;
	int		n_var;
	char	*var;

	i = 0;
	n_var = 0;
	while (getenv(NULL) != NULL)
		n_var++;
	env = malloc(sizeof(struct s_env_data) * (n_var + 1));
	while (getenv(NULL) != NULL)
	{
		env[i].name = getenv(NULL);
		env[i].value = getenv(env[i].name);
		i ++;
	}
}

void	exit(char **str, char **env)
{
	if (str[1] == NULL) //il y a que exit
	{
		exit();
	}
	else if (is_numeric(str[1]) == 1) // il y a exit et une valeur numérique
	{
		printf("exit\n");
		exit(atoi(str[1]));
	}
	else // il y a exit et une valeur non numérique
	{
		printf("exit\n");
		printf("numeric argument required\n");
		exit(255);
	}
}
