/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:16:23 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/20 12:29:49 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*dest_end;

	dest_end = dest + ft_strlen(dest);
	i = 0;
	while (src[i] && i < nb)
	{
		dest_end[i] = src[i];
		i++;
	}
	dest_end[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
