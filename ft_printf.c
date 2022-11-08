/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:10 by lloison           #+#    #+#             */
/*   Updated: 2022/11/08 15:34:25 by lloison          ###   ########.fr       */
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

//#include <stdio.h>

//#define TEST ">------------<%4.16d>------------<"
//#define VALUE 0

//void debug(int test_number, char *text, int value)
//{
//	printf("===========TEST %02d==========================\n", test_number);
//	printf("TEXTE : %s | VALEUR %d\n", text, value);
//	printf("  %d\n", ft_printf(text, value));
//	printf("--------------------------------------------------------\n");
//	printf("  %d\n", printf(text, value));
//	printf("===========END OF TEST %02d ==================\n\n\n", test_number);
//}
//int main(int argc, char **argv)
//{
//	(void) argc;
//	(void) argv;
//	debug(1, ">------------<%4.16d>------------<", 0);
//	debug(2, "!%48.2d!", 0);
//	debug(21, "% 47.5d", 0);
//	debug(3, "!%44.18d!", -1247144984);
//	debug(4, "%10.5i", -216);
//	debug(5, "%3.7i", -2375);
//	debug(6, "% 06d", 0);
//	debug(7, "% 06d", -5);
//	debug(8, "%.0i", 0);
//	debug(9, "%.i", 0);
//	debug(10, "% d", 0);
//	debug(11, "%0d", 0);
//	debug(12, "%1.5d", 15);
//	debug(13, "%037d", 0);
//	debug(14, "%07i", -54);
//	debug(15, "%5.0i", 0);
//	debug(16, "\\!/% 32.19d\\!/", -1673416894);
// 	debug(17, "!% 013d!", 1920160384);
//	debug(18, "!%+08d!", 0);
//	debug(19, "42%+56.6d42", 0);
//	debug(20, "%+40.49d", 1352876436);
//	debug(21, "%+020d", 0);
//	debug(22, "%+.d", 0);
//	debug(23, "% d", 0);
//	debug(24, "\\!/%36.18x\\!/", 0);
//}
