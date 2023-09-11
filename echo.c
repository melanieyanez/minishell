/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:04:33 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:06:23 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	echo(char **str)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (str[i] == NULL)
	{
		printf("\n");
		return ;
	}
	if (strncmp(str[i], "-n", 2) == 0)
	{
		i++;
		flag = 1;
	}
	if (str[i] != NULL)
	{
		printf("%s", str[i++]);
		while (str[i])
			printf(" %s", str[i++]);
	}
	if (flag == 0)
		printf("\n");
}

/*
int	main(void)
{
	char	*argv[] = {"echo", "Hello World", NULL};
	char	*argvn[] = {"echo", "-n", "Hello World", NULL};
	char	*argv_justecho[] = {"echo", NULL};
	char	*argv_test[] = {"echo", "Hello World", "-n", NULL};

	//echo(argv);
	//echo(argvn);
	//echo(argv_justecho);
	echo(argv_test);
	return (0);
}
*/