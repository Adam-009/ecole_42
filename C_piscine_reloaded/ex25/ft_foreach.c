/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:08:18 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/08 14:10:16 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>

void    ft_putchar(char c)
{
        write (1, &c, 1);
}

void    ft_putnbr(int nb)
{
        if (nb == -2147483648)
        {
                write(1, "-2147483648", 11);
                return ;
        }
        if (nb < 0)
        {
                nb = nb * -1;
                ft_putchar('-');
        }
        if (nb <= 9 && nb >= 0)
        {
                nb = nb + '0';
                ft_putchar(nb);
        }
        else
        {
                ft_putnbr (nb / 10);
                ft_putnbr (nb % 10);
        }
}
*/
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (tab[i] && i < length)
		f(tab[i++]);
}
/*
int	main(void)
{
	int	tab[5] = {1, 2, 3, 10, 1190};
	ft_foreach(tab, 1337, &ft_putnbr);
}*/
