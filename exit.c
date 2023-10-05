/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:44:07 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/05 13:11:57 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i ++;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(char **str)
{
	if (str[1] == NULL) //il y a que exit
	{
		printf("exit\n");
		exit(0); // success
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
		exit(255); // interpretation error of the exit status convention
	}
}

int	main(void)
{
	char	*str[2];

	str[0] = "exit";
	str[1] = "12";
	ft_exit(str);
}

// to print the last exit status 'echo $?'  