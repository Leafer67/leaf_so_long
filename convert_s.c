/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:43:49 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:02:53 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_s(t_flags *flags, va_list args, t_sstring **string)
{
	char	*s;

	(void) flags;
	s = va_arg(args, char *);
	if (s == 0)
	{
		s = ft_strdup("(null)");
		if (s == 0)
			return (-1);
		return (add_to_text(string, s, ft_strlen(s)));
	}
	s = ft_strdup(s);
	if (s == 0)
		return (-1);
	return (add_to_text(string, s, ft_strlen(s)));
}
