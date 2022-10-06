/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:38:56 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/22 14:50:43 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_argv(char **argv, int argc);
void	ft_print_argv(char **argv, int argc);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char *argv[])
{
	ft_sort_argv(argv, argc);
	ft_print_argv(argv, argc);
	return (0);
}

void	ft_sort_argv(char **argv, int argc)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j + 1 < argc)
	{
		i = 0;
		while (i + 1 < argc)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_print_argv(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			argv[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
}
