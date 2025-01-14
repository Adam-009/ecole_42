/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:24:39 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/05 12:18:52 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(int a, int b, int c, int d)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, " ", 1);
	write (1, &c, 1);
	write (1, &d, 1);
	if (a != 9 || b != 8 || c != 9 || d !=9)
		write (1, ", ", 2);

}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = '0';
	b = '0';
	c = '0';
	d = '0';
	
	while (c <= '9')
	{
		while (d <= '9')
		{
			while (a <= '9')
			{
				while (b <= '9')
				{
					ft_putchar(a, b, c, d);
					b++
				}
				a++;
				b = a + 1;
			}


		}
		c++;
		d = c + 1;
	}
}

int	main(void)
{
	ft_print_comb2();
}
