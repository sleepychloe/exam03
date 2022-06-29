/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:21:47 by yhwang            #+#    #+#             */
/*   Updated: 2022/02/18 14:39:16 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}

int	ft_puthexa(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_puthexa(nb / 16);
	if (nb % 16 < 10)
		len += ft_putchar((nb % 16) + 48);
	else
		len += ft_putchar((nb % 16) + 87);
	return (len);
}

void	ft_print_arg(char c, va_list ap, int *i)
{
	if (c == 's')
		*i += ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		*i += ft_putnbr(va_arg(ap, int));
	else if (c == 'x')
		*i += ft_puthexa(va_arg(ap, unsigned int));
	else
		*i += ft_putchar(c);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list	ap;

	i = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (i);
			ft_print_arg(*format, ap, &i);
		}
		else
		{
			ft_putchar(*format);
			i++;
		}
		format++;
	}
	va_end(ap);
	return (i);
}

/*
int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}
*/
