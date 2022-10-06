/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:03:26 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/04 13:02:05 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arr_size(char **arr)
{
	int	size;

	size = 0;
	while (*arr)
	{
		size++;
		arr++;
	}
	return (size);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	size = arr_size(tab);
	j = 0;
	while (j + 1 < size)
	{
		i = 0;
		while (i + 1 < size)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
