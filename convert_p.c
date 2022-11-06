/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:47:05 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:02:29 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(unsigned long adr)
{
	int	count;

	count = 3;
	while (adr / 16 != 0)
	{
		count++;
		adr /= 16;
	}
	return (count);
}

static char	*get_address(unsigned long adr)
{
	int		length;
	char	*output;

	length = get_length(adr);
	output = (char *) malloc(sizeof(char) * (length + 1));
	if (output == 0)
		return (0);
	output[length] = 0;
	output[0] = '0';
	output[1] = 'x';
	while (adr / 16 > 0)
	{
		output[length - 1] = "0123456789abcdef"[adr % 16];
		length--;
		adr /= 16;
	}
	output[length - 1] = "0123456789abcdef"[adr % 16];
	return (output);
}

int	convert_p(t_flags *flags, va_list args, t_sstring **string)
{
	void			*ptr;
	char			*output;
	unsigned long	adr;

	(void) flags;
	ptr = va_arg(args, void *);
	adr = *((unsigned long *)&ptr);
	if (ptr == 0)
		output = ft_strdup("0x0");
	else
		output = get_address(adr);
	if (output == 0)
		return (-1);
	return (add_to_text(string, output, ft_strlen(output)));
}
