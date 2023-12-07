/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:28:59 by fsalimba          #+#    #+#             */
/*   Updated: 2023/04/29 11:31:46 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	int		num_digits;
	int		i;
	long	num;
	char	*str;

	num = n;
	num_digits = ft_num_len(num);
	str = (char *) malloc(sizeof(char) * (num_digits + 1));
	if (!str)
		return (NULL);
	i = 0;
	ft_int_to_str(num, str, &i);
	str[i] = '\0';
	return (str);
}
