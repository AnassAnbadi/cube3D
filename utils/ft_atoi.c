/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:53:32 by aanbadi           #+#    #+#             */
/*   Updated: 2025/09/06 20:42:51 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_atoi(const char *str)
{
	unsigned long	num;
	int				s;

	num = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			s *= -1;
	while (*str >= '0' && *str <= '9')
	{
		if (num * 10 + *str - '0' > LONG_MAX)
		{
			return (-(s + 1) / 2);
		}
		num = num * 10 + *str++ - '0';
	}
	return ((int )num * s);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	ptr1;
	unsigned char	ptr2;

	if (!n)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		ptr1 = (unsigned char)s1[i];
		ptr2 = (unsigned char)s2[i];
		if (ptr1 != ptr2)
			return ((int)(ptr1 - ptr2));
		i++;
	}
	return (0);
}
int ft_sum(int *arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}