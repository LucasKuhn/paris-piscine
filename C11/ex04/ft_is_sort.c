/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:10:26 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/04 19:52:21 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	is_ascending;

	if (length == 0 || length == 1 || length == 2)
		return (1);
	tab++;
	length--;
	while (--length && f(*(tab - 1), *tab) == 0)
		tab++;
	if (f(*(tab - 1), *tab) < 0)
		is_ascending = 1;
	else
		is_ascending = 0;
	while (length--)
	{
		tab++;
		if (is_ascending && f(*(tab - 1), *tab) > 0)
			return (0);
		else if (!is_ascending && f(*(tab - 1), *tab) < 0)
			return (0);
	}
	return (1);
}
