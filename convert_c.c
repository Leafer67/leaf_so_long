/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:40:02 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:01:53 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_c(t_flags *flags, va_list args, t_sstring **string)
{
	char	tmp[2];
	char	*tmp2;

	(void) flags;
	tmp[0] = (char)va_arg(args, int);
	tmp[1] = 0;
	tmp2 = ft_strdup(tmp);
	if (tmp2 == 0)
		return (-1);
	return (add_to_text(string, tmp2, 1));
}
