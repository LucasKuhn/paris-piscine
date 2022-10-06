/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:13:46 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/15 16:48:49 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	original_a;
	int	original_b;

	original_a = *a;
	original_b = *b;
	*a = original_b;
	*b = original_a;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	middle;

	i = 0;
	middle = size / 2;
	while (i < middle)
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
}
