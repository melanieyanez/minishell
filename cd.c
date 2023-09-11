/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:14:29 by myanez-p          #+#    #+#             */
/*   Updated: 2023/09/11 17:41:52 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//chdir change current working directory, causes the named directory to become the current directory
//retourne 0 si c'est tout ok, retourne -1 si problème

//getcwd copies the absolute path name of the current working directory into buf and returns a pointer to it

//only with a relative or an absolute path

void	cd(char **str)
{
	char	current_wd[4096];
	char	target_wd[4096];
	char	*path;

	getcwd(current_wd, sizeof(current_wd));
	target_wd = str[1];
	if (chdir(str[1]) != 0)
	{
		printf("error\n");
	}
	if (getcwd(current_wd, sizeof(current_wd)) != NULL)
	{
		
	}
}
