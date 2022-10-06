/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:16:29 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/21 23:20:40 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] && (dest_len + 1) < size)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (ft_strlen(src) + dest_len - i);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
