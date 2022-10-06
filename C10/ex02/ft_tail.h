/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:01:32 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/06 21:00:48 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>  // errno
# include <fcntl.h>  // open
# include <string.h> // strerror
# include <unistd.h> // write read close

int		ft_atoi(const char *str);
void	ft_tail(int argc, char *argv[], int bytes, int filecount);
void	ft_putstr(char *str);
void	ft_puterror(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_str_is_numeric(char *str);
int		is_stdin(char *str);

#endif
