/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:47 by fsalimba          #+#    #+#             */
/*   Updated: 2023/11/20 11:01:50 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*out;
	size_t	i;

	out = malloc(sizeof(char) * (n + 1));
	if (!out)
		return (0);
	i = 0;
	while (i < n)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
