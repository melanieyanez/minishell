/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:30:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/10/10 17:56:57 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_export(char ***env_var, char **var)
{
	int		i;
	int		n_var;
	char	**result;

	i = 0;
	n_var = 0;
	while ((*env_var)[n_var])
		n_var ++;
	while (var[i])
	{
		n_var ++;
		i ++;
	}
	result = malloc(sizeof(char *) * (n_var + 1));
	while ((*env_var)[i])
	{
		result[i] = strdup((*env_var)[i]);
		i ++;
	}
	while (var[j])
	{
		
	}
}

int	main(void)
{
	
}
