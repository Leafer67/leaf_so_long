/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:16:31 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:42:24 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	call_corresponding_convert_function(const char *s, va_list args,
	t_sstring **string, t_flags **flags)
{
	int	return_value;

	(void)flags;
	return_value = 0;
	if (*s == 'c')
		return_value = convert_c(0, args, string);
	else if (*s == 's')
		return_value = convert_s(0, args, string);
	else if (*s == 'p')
		return_value = convert_p(0, args, string);
	else if (*s == 'd' || *s == 'i')
		return_value = convert_di(0, args, string);
	else if (*s == 'u')
		return_value = convert_u(0, args, string);
	else if (*s == 'x')
		return_value = convert_x(0, 0, args, string);
	else if (*s == 'X')
		return_value = convert_x(1, 0, args, string);
	else if (*s == '%')
		return_value = convert_doublepercent(0, args, string);
	return (return_value);
}

//return how long the percent format thing is
int	convert_percent(const char *s, va_list args, t_sstring **string)
{
	int		return_value;
	t_flags	*flags;

	s++;
	flags = (t_flags *) malloc(sizeof(t_flags));
	if (flags == 0)
		return (-1);
	return_value = call_corresponding_convert_function(s, args, string, &flags);
	free(flags);
	if (return_value == -1)
		return (-1);
	return (2);
}

static int	add_no_format(char *substr, t_sstring **string, unsigned int size)
{
	if (substr == 0)
		return (-1);
	return (add_to_text(string, substr, size));
}

t_sstring	*generate_string(const char *s, va_list args)
{
	unsigned int	i;
	t_sstring		*string;
	int				tmp;

	i = -1;
	string = init_sstring();
	if (string == 0)
		return (0);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			if (add_no_format(ft_substr(s, 0, i), &string, i) == -1)
				return (free_sstring(&string));
			s += i;
			tmp = convert_percent(s, args, &string);
			if (tmp == -1)
				return (free_sstring(&string));
			s += tmp;
			i = -1;
		}
	}
	if (add_no_format(ft_substr(s, 0, i), &string, i) == -1)
		return (free_sstring(&string));
	return (string);
}
