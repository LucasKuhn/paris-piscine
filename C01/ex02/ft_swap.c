/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:12:57 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/14 22:12:58 by lkuhn            ###   ########.fr       */
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
