/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_e.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:23:25 by lloison           #+#    #+#             */
/*   Updated: 2022/11/23 18:58:21 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_E_H
# define LIBFT_E_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include "sstring.h"

int			ft_printf(const char *s, ...);
char		*generate_fstring(const char *s, ...);
char		*get_next_line(int fd);

#endif
