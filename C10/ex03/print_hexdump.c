/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexdump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:45:37 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 18:08:51 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	write_offset(int number, char *base)
{
	static char	offset[8];
	int			i;

	i = 0;
	while (i < 8)
		offset[i++] = '0';
	i = 7;
	while (number)
	{
		offset[i--] = base[number % 16];
		number /= 16;
	}
	write(1, offset, 8);
}

void	write_in_hex(char *str)
{
	char			*base;
	unsigned char	c;
	int				i;

	base = "0123456789abcdef";
	i = 0;
	c = str[i++];
	while (c)
	{
		write(1, &base[c / 16], 1);
		write(1, &base[c % 16], 1);
		write(1, " ", 1);
		if (i == 8 || i == 16)
			write(1, " ", 1);
		c = str[i++];
	}
	while (i <= 16)
	{
		write(1, "   ", 3);
		if (i == 8 || i == 16)
			write(1, " ", 1);
		i++;
	}
}

void	write_in_p(char *str)
{
	while (*str)
	{
		if (!(*str >= 32 && *str <= 126) && *str != ' ')
			write(1, ".", 1);
		else
			write(1, str, 1);
		str++;
	}
}

void	print_hexdump(int offset, char buffer[16])
{
	write_offset(offset, "0123456789abcdef");
	write(1, "  ", 2);
	write_in_hex(buffer);
	write(1, "|", 1);
	write_in_p(buffer);
	write(1, "|", 1);
	write(1, "\n", 2);
}
