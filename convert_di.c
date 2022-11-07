/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:57:33 by lloison           #+#    #+#             */
/*   Updated: 2022/11/07 20:12:05 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	are_flags_valid(t_flags *flags)
{
	if (flags->hashtag == 1)
		return (-1);
	if (flags->precision == 0 && flags->zero == 1)
	{
		flags->precision_y = flags->precision_x;
		flags->precision_x = 0;
	}
	if (flags->plus == 1 && flags->blank == 1)
		flags->blank = 0;
	if (flags->precision == 1 && flags->zero == 1)
		flags->zero = 0;
	return (0);
}

static char	*generate_to_add2(t_flags *flags, char *output, int is_n, int arg)
{
	char	*tmp;

	tmp = 0;
	if (flags->plus == 1 && is_n == 0)
	{
		if ((output[0] == ' ' || output[0] == '0')
			&& (flags->precision == 0 && flags->precision_y > 0)
			&& !(arg == 0 && ft_strlen(output) == 1))
		{
			output[0] = '+';
			return (output);
		}
		tmp = ft_strdup("+");
		if (tmp == 0)
		{
			free(output);
			return (0);
		}
		return (ft_strjoinfree(tmp, output));
	}
	if (tmp)
		free(tmp);
	return (output);
}

static char	*generate_number(t_flags *flags, int arg, int *is_n)
{
	char	*output;
	char	*tmp;

	if (arg == -2147483648)
	{
		*is_n = 1;
		output = ft_strdup("2147483648");
	}
	else if (arg == 0 && flags->precision == 1 && flags->precision_y == 0)
		return (gen_array(' ', flags->blank));
	else if (arg < 0)
	{
		*is_n = 1;
		arg *= -1;
		output = ft_itoa(arg);
	}
	else
	{
		*is_n = 0;
		output = ft_itoa(arg);
	}
	if (output == 0)
		return (0);
	// adding zeros
	if (flags->precision_y > ft_strlen(output))
	{
		int temp;

		temp = 0;
		if (flags->blank == 1 && flags->precision == 0 && arg != 0)
			temp = 1;
		if (arg == 0 && flags->precision == 0 && flags->blank == 1)
			temp++;
		tmp = gen_array('0', flags->precision_y - ft_strlen(output) - temp);
		if (tmp == 0)
		{
			free(output);
			return (0);
		}
		output = ft_strjoinfree(tmp, output);
		if (output == 0)
			return (0);
	}
	// adding blank
	if (flags->blank == 1)
	{
		tmp = ft_strdup(" ");
		if (tmp == 0)
		{
			free(output);
			return (0);
		}
		output = ft_strjoinfree(tmp, output);
		if (output == 0)
			return (0);
	}
	// adding minus
	//char *tmp;

	if (*is_n)
	{
		if ((output[0] == '0' || output[0] == ' ') && (flags->precision == 0 || flags->blank == 1))
			output [0] = '-';
		else
		{
			tmp = ft_strdup("-");
			if (tmp == 0)
			{
				free(output);
				return (0);
			}
			return (ft_strjoinfree(tmp, output));
		}
	}
	return (output);
}

static char	*generate_to_add(t_flags *flags, int arg)
{
	char	*output;
	int		is_n;

	is_n = 0;
	output = generate_number(flags, arg, &is_n);
	if (output == 0)
		return (0);
	return (generate_to_add2(flags, output, is_n, arg));
}

int	convert_di(t_flags *flags, va_list args, t_sstring **string)
{
	int		number;
	char	*to_add;
	char	*spaces;

	if (are_flags_valid(flags) == -1)
		return (-1);
	number = va_arg(args, int);
//	if (number == 0 && flags->precision_x == 0 && flags->precision_y == 0
//			&& flags->precision == 1)
//		return (0);
	to_add = generate_to_add(flags, number);
	if (to_add == 0)
		return (-1);
	spaces = gen_array(' ', flags->precision_x - ft_strlen(to_add));
	if (spaces == 0)
	{
		free(to_add);
		return (-1);
	}
	if (flags->minus == 1)
		return (minus_behavior(string, to_add, spaces));
	return (normal_behavior(string, to_add, spaces));
}
