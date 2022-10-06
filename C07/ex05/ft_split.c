/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:09:07 by lkuhn             #+#    #+#             */
/*   Updated: 2022/09/28 21:58:09 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	get_word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (!is_charset(str[len], charset))
		len++;
	return (len);
}

int	count_words(char *str, char *charset)
{
	int	word_count;

	word_count = 0;
	while (*str)
	{
		while (is_charset(*str, charset))
			str++;
		if (*str)
		{
			word_count++;
			while (!is_charset(*str, charset))
				str++;
		}
	}
	return (word_count);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	char	*word;
	int		i;

	arr = malloc(sizeof(char *) * (count_words(str, charset) + 1));
	i = 0;
	while (*str)
	{
		while (is_charset(*str, charset))
			str++;
		if (*str)
		{
			word = malloc(sizeof(char) * (get_word_len(str, charset) + 1));
			if (!word)
				return (NULL);
			arr[i] = word;
			while (*str && !is_charset(*str, charset))
				*word++ = *str++;
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
