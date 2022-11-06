/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:43:49 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 19:52:39 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	are_flags_valid(t_flags *flags)
{
	if (flags->hashtag == 1 || flags->blank == 1)
		return (-1);
	return (0);
}

static char	*generate_to_add(t_flags *flags, char *arg)
{
	char	*tmp;

	if (flags->precision == 0)
	{
		if (arg == 0)
			return (ft_strdup("(null)"));
		return (ft_strdup(arg));
	}
	else
	{
		if (arg == 0)
			tmp = ft_strdup("(null)");
		else
			tmp = ft_strdup(arg);
		if (tmp == 0)
			return (0);
		if (flags->precision_y < ft_strlen(tmp))
		{
			arg = ft_substr(tmp, 0, flags->precision_y);
			free (tmp);
			return (arg);
		}
		return (tmp);
	}
}

int	normal_behavior(t_sstring **string,	char *s, char *spaces)
{
	if (add_to_text(string, spaces, ft_strlen(spaces)) == -1)
	{
		free(s);
		return (-1);
	}
	return (add_to_text(string, s, ft_strlen(s)));
}

int	minus_behavior(t_sstring **string, char *s, char *spaces)
{
	if (add_to_text(string, s, ft_strlen(s)) == -1)
	{
		free(spaces);
		return (-1);
	}
	return (add_to_text(string, spaces, ft_strlen(spaces)));
}

int	convert_s(t_flags *flags, va_list args, t_sstring **string)
{
	char	*s;
	char	*spaces;

	if (are_flags_valid(flags) == -1)
		return (-1);
	s = va_arg(args, char *);
	s = generate_to_add(flags, s);
	if (s == 0)
		return (-1);
	spaces = gen_array(' ', flags->precision_x - ft_strlen(s));
	if (spaces == 0)
	{
		free(s);
		return (-1);
	}
	if (flags->minus == 1)
		return (minus_behavior(string, s, spaces));
	return (normal_behavior(string, s, spaces));
}
