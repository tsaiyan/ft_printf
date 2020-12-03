/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:13:44 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 13:13:49 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *argv1, ...)
{
	t_struct *s_box;

	s_box = malloc(sizeof(t_struct));
	s_box->argv1 = argv1;
	va_start(s_box->argument_pointer, argv1);
	ft_pwtype(s_box);
	va_end(s_box->argument_pointer);
	return (0);
}

int	main(void)
{
	char *ar;
	
	printf("%%\n");
	ft_printf("%%\n");
	return (0);
}
