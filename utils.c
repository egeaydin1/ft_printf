
#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return(1);
}
void	ft_putnbr_base_fd(int n, int fd, int base, char flag)
{
	int	num;
	char *digitsx;
	char *digitsX;

	digitsx = ft_strdup("0123456789abcdef");
	digitsX = ft_strdup("0123456789ABCDEF");
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = n * (-1);
	}
	else
		num = n;
	if (num >= base)
		ft_putnbr_base_fd(num / base, fd,base,flag);
	if (flag == 'X')
		ft_putchar_fd(digitsX[(num % base)],fd);
	else
		ft_putchar_fd(digitsx[(num % base)],fd);
}
size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*strptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!strptr)
		return (NULL);
	while (s[i])
	{
		strptr[i] = s[i];
		i++;
	}
	strptr[i] = '\0';
	return (strptr);
}
