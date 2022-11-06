/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:10 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 19:59:18 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list			args;
	t_sstring		*string;
	size_t			return_value;

	va_start(args, s);
	string = generate_string(s, args);
	va_end(args);
	if (string == 0)
		return (-1);
	if (string->text == 0 || write(1, string->text, string->length) == -1)
	{
		free_sstring(&string);
		return (-1);
	}
	return_value = string->length;
	free_sstring(&string);
	return (return_value);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	printf("%d\n" ,ft_printf("%p", ""));
	printf("====================\n");
	printf("%d\n", printf("%.10s, %.10s, %.10s, %.10s", NULL, "", "test", 
"joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6"));
}*/
