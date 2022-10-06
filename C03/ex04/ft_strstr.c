/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:16:26 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/20 12:32:38 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_equal(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			if (is_equal(str, to_find))
				return (str);
		}
		str++;
	}
	return (0);
}

int	is_equal(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}
