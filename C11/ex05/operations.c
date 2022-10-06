/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:10:55 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/04 15:45:34 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

void	ft_add(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_subtract(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_divide(int a, int b)
{
	if (b == 0)
		return (ft_putstr("Stop : division by zero"));
	ft_putnbr(a / b);
}

void	ft_times(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_module(int a, int b)
{
	if (b == 0)
		return (ft_putstr("Stop : modulo by zero"));
	ft_putnbr(a % b);
}
