/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:25 by lloison           #+#    #+#             */
/*   Updated: 2022/11/06 19:53:33 by lloison          ###   ########.fr       */
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
	int		minus;
	int		plus;
	int		hashtag;
	int		precision;
	int		blank;
	int		zero;
	size_t	precision_x;
	size_t	precision_y;
	int		flags_length;
}	t_flags;

int			normal_behavior(t_sstring **string, char *s, char *spaces);
int			minus_behavior(t_sstring **string, char *s, char *spaces);
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
t_flags		*get_flags(const char *s);
int			ft_printf(const char *s, ...);
char		*gen_array(char c, int size);

#endif
