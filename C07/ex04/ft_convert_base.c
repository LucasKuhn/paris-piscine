/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:52:18 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/28 21:55:24 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
int		base_is_invalid(char *base);

int	digits_in_number(int number, char *base_to)
{
	int	str_len;
	int	base_to_len;
	int	i;

	if (number == 0)
		return (1);
	base_to_len = ft_strlen(base_to);
	str_len = 0;
	if (number < 0)
		str_len++;
	i = number;
	while (i)
	{
		str_len++;
		i = i / base_to_len;
	}
	return (str_len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	int			str_len;
	long int	number;

	if (base_is_invalid(base_from) || base_is_invalid(base_to))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	str_len = digits_in_number(number, base_to);
	str = malloc(sizeof(char) * str_len + 1);
	str[str_len--] = '\0';
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	if (number == 0)
		str[str_len] = base_to[0];
	while (number)
	{
		str[str_len] = base_to[number % ft_strlen(base_to)];
		str_len--;
		number /= ft_strlen(base_to);
	}
	return (str);
}
