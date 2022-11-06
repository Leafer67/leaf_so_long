/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:59:17 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:02:39 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_doublepercent(t_flags *flags, va_list args, t_sstring **string)
{
	char	*tmp;

	(void) args;
	(void) flags;
	tmp = ft_strdup("%");
	if (tmp == 0)
		return (-1);
	return (add_to_text(string, tmp, ft_strlen(tmp)));
}
