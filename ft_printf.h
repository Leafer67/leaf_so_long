/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:25 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 14:20:57 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include "sstring.h"

typedef struct s_flags
{
	int	minus;
	int	plus;
	int	hashtag;
	int	precision;
	int	blank;
	int	zero;
	int	precision_x;
	int	precision_y;
}	t_flags;

int			convert_c(t_flags *flags, va_list args, t_sstring **string);
int			convert_p(t_flags *flags, va_list args, t_sstring **string);
int			convert_s(t_flags *flags, va_list args, t_sstring **string);
int			convert_di(t_flags *flags, va_list args, t_sstring **string);
int			convert_u(t_flags *flags, va_list args, t_sstring **string);
int			convert_doublepercent(t_flags *flags,
				va_list args, t_sstring **string);
int			convert_x(int is_upper, t_flags *flags,
				va_list args, t_sstring **string);
int			convert_percent(const char *s, va_list args, t_sstring **string);
t_sstring	*generate_string(const char *s, va_list args);
int			ft_printf(const char *s, ...);

#endif
