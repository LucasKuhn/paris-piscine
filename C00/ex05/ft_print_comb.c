/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:00:15 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/14 21:29:11 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_numbers(int i100, int i10, int i1)
{
	char	number[3];

	number[0] = '0' + i100;
	number[1] = '0' + i10;
	number[2] = '0' + i1;
	write(1, number, 3);
	if (i100 == 7 && i10 == 8 && i1 == 9)
		return ;
	write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i1;
	int	i10;
	int	i100;

	i100 = 0;
	while (i100 <= 9)
	{
		i10 = i100 + 1;
		while (i10 <= 9)
		{
			i1 = i10 + 1;
			while (i1 <= 9)
			{
				ft_put_numbers(i100, i10, i1);
				i1++;
			}
			i10++;
		}
		i100++;
	}
}
