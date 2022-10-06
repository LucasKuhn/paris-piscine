/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:38:18 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/05 16:49:34 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i + 1 < n))
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	digits_in_number(int number)
{
	int	str_len;
	int	base_len;
	int	i;

	if (number == 0)
		return (1);
	base_len = 16;
	str_len = 0;
	if (number < 0)
		str_len++;
	i = number;
	while (i)
	{
		str_len++;
		i = i / base_len;
	}
	return (str_len);
}

void	clear_buffer(char buffer[16])
{
	int	i;

	i = 0;
	while (i < 16)
		buffer[i++] = 0;
}
