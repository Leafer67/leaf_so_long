/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:57:33 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:02:19 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_di(t_flags *flags, va_list args, t_sstring **string)
{
	char	*output;
	int		number;

	(void) flags;
	number = va_arg(args, int);
	output = ft_itoa(number);
	if (output == 0)
		return (-1);
	return (add_to_text(string, output, ft_strlen(output)));
}
