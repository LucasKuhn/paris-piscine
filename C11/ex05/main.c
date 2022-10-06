/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:10:50 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/04 15:47:28 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

void	do_operation(int a, int b, char operation)
{
	void	(*operations[5])(int, int);

	operations[0] = &ft_add;
	operations[1] = &ft_subtract;
	operations[2] = &ft_divide;
	operations[3] = &ft_times;
	operations[4] = &ft_module;
	if (operation == '+')
		operations[0](a, b);
	else if (operation == '-')
		operations[1](a, b);
	else if (operation == '/')
		operations[2](a, b);
	else if (operation == '*')
		operations[3](a, b);
	else if (operation == '%')
		operations[4](a, b);
	else
		write(1, "0", 1);
}

int	main(int argc, char *argv[])
{
	int		a;
	int		b;

	if (argc == 4)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		do_operation(a, b, *argv[2]);
		ft_putstr("\n");
	}
}
