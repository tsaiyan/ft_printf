/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:08:39 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 16:08:41 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned res;

	if (n < 0)
	{
		write(1, "-", 1);
		res = n * -1;
	}
	else
		res = (unsigned)n;
	if (res >= 10)
		ft_putnbr(res / 10);
	ft_putchar(res % 10 + 48);
}

static int ft_rank_count(int n)
{
	int i;

	i = 0;
	while ( n % 16 != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_putnbr_x(int n)
{
	unsigned res;
	char *array;
	char result_array[ft_rank_count(n) + 1];
	int len;

	len = ft_rank_count(n);
	array = "0123456789abcdef";
	res = (unsigned)n;
	result_array[len--] = '\0';
	while (n != 0)
	{
		result_array[len--] = array[n % 16];
		n /= 16;
	}
	ft_putstr(result_array);
}

void	ft_putnbr_bx(int n)
{
	unsigned res;
	char *array;
	char result_array[ft_rank_count(n) + 1];
	int len;

	len = ft_rank_count(n);
	array = "0123456789ABCDEF";
	res = (unsigned)n;
	result_array[len--] = '\0';
	while (n != 0)
	{
		result_array[len--] = array[n % 16];
		n /= 16;
	}
	ft_putstr(result_array);
}

void	ft_putnbr_p(int n)
{
	unsigned res;
	char *array;
	
	array = "0123456789ABCDEF";
	//write(1, "0x", 2);
	//n/=100;
		res = (unsigned)n;
	if (res > 16)
		ft_putnbr(res / 16);
	if (res == 16)
		write (1, "10", 2);
	else ft_putnbr_p(array[res]);
}
