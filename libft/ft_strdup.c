/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:50:43 by lloison           #+#    #+#             */
/*   Updated: 2022/11/05 12:18:36 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*output;

	if (s1 == 0)
		return (0);
	size = ft_strlen(s1);
	i = 0;
	output = (char *) malloc((size + 1) * sizeof(char));
	if (output == 0)
		return (0);
	while (i < size)
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
