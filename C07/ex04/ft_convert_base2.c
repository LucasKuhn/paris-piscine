/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:52:23 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/28 20:35:55 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	position_in_base(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	base_is_invalid(char *base)
{
	int	i;

	if (!(base[0]) || !(base[1]))
		return (1);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (1);
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (1);
			i++;
		}
		base++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_size;
	int	number;
	int	sign;

	if (base_is_invalid(base))
		return (0);
	number = 0;
	sign = 1;
	base_size = ft_strlen(base);
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (position_in_base(base, *str) != -1)
	{
		number = (number * base_size) + position_in_base(base, *str);
		str++;
	}
	return (number * sign);
}
