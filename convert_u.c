/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:01:09 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:03:00 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_u(t_flags *flags, va_list args, t_sstring **string)
{
	unsigned int	number;
	char			*output;

	(void) flags;
	number = va_arg(args, unsigned int);
	output = ft_uitoa(number);
	if (output == 0)
		return (-1);
	return (add_to_text(string, output, ft_strlen(output)));
}
