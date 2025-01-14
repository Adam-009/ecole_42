/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:56:04 by asaadi--          #+#    #+#             */
/*   Updated: 2024/10/05 11:21:55 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char nb)
{
	write (1, &nb, 1);
}

void	ft_putnbr(int nb)
{

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 12);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb <= 9)
	{
		nb = nb + '0';
		ft_putchar(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
/*
int main(void)
{
	ft_putnbr(2147483647);
}*/
