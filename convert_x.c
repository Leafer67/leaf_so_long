/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:50:45 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:03:05 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(unsigned int number)
{
	int	count;

	count = 1;
	while (number / 16 != 0)
	{
		count++;
		number /= 16;
	}
	return (count);
}

static char	*get_hexa(unsigned int number, char *charset)
{
	int		length;
	char	*output;

	length = get_length(number);
	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	output[length] = 0;
	while (number / 16 > 0)
	{
		output[length - 1] = charset[number % 16];
		length--;
		number /= 16;
	}
	output[length - 1] = charset[number % 16];
	return (output);
}

int	convert_x(int is_upper, t_flags *flags, va_list args, t_sstring **string)
{
	unsigned int	number;
	char			*output;

	(void) flags;
	number = va_arg(args, unsigned int);
	if (is_upper == 1)
		output = get_hexa(number, "0123456789ABCDEF");
	else
		output = get_hexa(number, "0123456789abcdef");
	if (output == 0)
		return (-1);
	return (add_to_text(string, output, ft_strlen(output)));
}
