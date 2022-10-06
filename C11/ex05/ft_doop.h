/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkuhn <lkuhn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 08:10:47 by lkuhn             #+#    #+#             */
/*   Updated: 2022/10/04 08:11:13 by lkuhn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H
# include <unistd.h>

void	ft_add(int a, int b);
void	ft_subtract(int a, int b);
void	ft_divide(int a, int b);
void	ft_times(int a, int b);
void	ft_module(int a, int b);
int		ft_atoi(const char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

#endif
