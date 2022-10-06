/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:13:08 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/14 22:16:10 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	original_a;
	int	original_b;

	original_a = *a;
	original_b = *b;
	*a = original_a / original_b;
	*b = original_a % original_b;
}
