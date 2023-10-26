/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:14:29 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/26 15:59:29 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//chdir change current working directory, causes the named directory to become the current directory
//retourne 0 si c'est tout ok, retourne -1 si problème

//getcwd copies the absolute path name of the current working directory into buf and returns a pointer to it

//only with a relative or an absolute path

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	result = malloc(sizeof(*s1) * (strlen(s1) + strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j ++;
	}
	result[i + j] = '\0';
	return (result);
}

void	ft_cd(char ***env_var, char **str)
{
	char	old_wd[4096];
	char	target_wd[4096];
	char	**path;

	path = malloc(sizeof(char *) * 4);
	getcwd(old_wd, sizeof(old_wd));
	if (str[1] == NULL)
		return ;
	if (chdir(str[1]) != 0)
	{
		perror("cd");
	}
	else if (getcwd(target_wd, sizeof(target_wd)) != NULL)
	{
		path[0] = strdup("export");
		path[1] = ft_strjoin("PWD=", target_wd);
		path[2] = ft_strjoin("OLDPWD=", old_wd);
		path[3] = NULL;
		ft_export(env_var, path);
	}
}

/*
int	main(void)
{
	char	**env_var;
	char	*argv[] = {"cd", "/Users/myanez-p/cursus_42/Rank02"};

	set_env(&env_var);
	ft_env(&env_var);
	ft_cd(&env_var, argv);
	printf("\n\n\n");
	ft_env(&env_var);
}
*/
