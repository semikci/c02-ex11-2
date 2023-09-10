/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekmekci <sekmekci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 03:49:06 by sekmekci          #+#    #+#             */
/*   Updated: 2023/09/10 19:17:29 by sekmekci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		k;
	char	c;
	char	*a;

	a = "0123456789abcdef";
	i = 0;
	while (str[i] || str[i + 1])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			k = str[i];
			write(1, "\\", 1);
			c = a[k / 16];
			write(1, &c, 1);
			c = a[k % 16];
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char	*str =  "Coucou\0tu\t vas bien ?"; 

	ft_putstr_non_printable2(str);
}
