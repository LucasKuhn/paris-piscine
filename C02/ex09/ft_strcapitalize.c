/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:34:25 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/19 20:57:38 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str);
int		is_spacing(char c);
int		is_letter(char c);
int		is_number(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	i = 0;
	while (str[i])
	{
		if (is_spacing(str[i]) && is_letter(str[i + 1]))
			str[i + 1] = str[i + 1] - 32;
		i++;
	}
	return (str);
}

int	is_spacing(char c)
{
	if (is_letter(c) || (c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

int	is_letter(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	if ((str[0] >= 'a' && str[0] <= 'z'))
		str[0] = str[0] - 32;
	return (str);
}
