/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:21 by fsalimba          #+#    #+#             */
/*   Updated: 2023/03/17 13:17:54 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_num_len(long n)
{
	int	num_len;

	num_len = 1;
	if (n < 0)
	{
		n *= -1;
		num_len++;
	}
	while (n > 9)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}

void	ft_int_to_str(long n, char *str, int *i)
{
	if (n <= 9)
		str[(*i)++] = n + '0';
	else
	{
		ft_int_to_str(n / 10, str, i);
		ft_int_to_str(n % 10, str, i);
	}
}

char	*ft_itoa(int n)
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
	if (num < 0)
	{
		str[i++] = '-';
		num *= -1;
	}
	ft_int_to_str(num, str, &i);
	str[i] = '\0';
	return (str);
}
