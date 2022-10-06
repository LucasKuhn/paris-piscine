/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:02:50 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/28 22:00:58 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * ft_strlen(src) + 1);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	joined_str_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	i;

	total_size = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		total_size += ft_strlen(strs[i]);
		i++;
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined_str;
	int		position;
	int		i;

	if (size == 0)
		return (ft_strdup(""));
	joined_str = malloc(sizeof(char) * (joined_str_size(size, strs, sep) + 1));
	position = 0;
	i = 0;
	while (i < size)
	{
		ft_strncpy(&joined_str[position], strs[i], ft_strlen(strs[i]));
		position += ft_strlen(strs[i]);
		if (i + 1 < size)
		{
			ft_strncpy(&joined_str[position], sep, ft_strlen(sep));
			position += ft_strlen(sep);
		}
		i++;
	}
	joined_str[position] = '\0';
	return (joined_str);
}
