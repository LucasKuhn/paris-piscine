/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:00:15 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/15 15:07:10 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int left_number, int right_number)
{
	char	string[5];

	if (!(left_number == 0 && right_number == 1))
		write(1, ", ", 2);
	string[0] = '0' + left_number / 10;
	string[1] = '0' + left_number % 10;
	string[2] = ' ';
	string[3] = '0' + right_number / 10;
	string[4] = '0' + right_number % 10;
	write(1, string, 5);
}

void	ft_print_comb2(void)
{
	int	left_number;
	int	right_number;

	left_number = 0;
	while (left_number <= 99)
	{
		right_number = left_number;
		while (right_number <= 99)
		{
			if (left_number != right_number)
				print_numbers(left_number, right_number);
			right_number++;
		}
		left_number++;
	}
}
