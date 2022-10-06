/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:22:55 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 18:02:37 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_puterror(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	return ;
}

int	print_error(char *str, char *program)
{
	ft_puterror(basename(program));
	ft_puterror(": ");
	ft_puterror(str);
	ft_puterror(": ");
	ft_puterror(strerror(errno));
	ft_puterror("\n");
	return (1);
}
