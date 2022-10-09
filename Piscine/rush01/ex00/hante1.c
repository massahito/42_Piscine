/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hante1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:36:00 by marai             #+#    #+#             */
/*   Updated: 2022/03/20 15:28:52 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define	N 4
int		g_check[N][N];
char	g_hairetu[N][N];
int		g_flag;

int		hantei_yoko(char checker[4*N], int n);
int		hantei_yokom(char checker[4*N], int n);
int		fukusuchecker(char g_hairetu[N][N]);
void	cleaner(int kensa[N][N]);

int	hantei_yoko(char checker[4*N], int n)
{
	int	p;
	int	x;
	int	i;

	i = 0;
	p = 0;
	x = 0;
	while (i < N)
	{
		if (x < g_hairetu[n][i] - '0')
		{
			x = g_hairetu[n][i] - '0';
			p++;
		}
		i++;
	}
	if (p == checker[n + 2 * N])
		return (1);
	return (0);
}

int	hantei_yokom(char checker[4*N], int n)
{
	int	q;
	int	y;
	int	i;

	i = 0;
	q = 0;
	y = 0;
	while (i < N)
	{
		if (y < g_hairetu[n][N - i - 1] - '0' )
		{
			y = g_hairetu[n][N - i - 1] - '0';
			q++;
		}
		i++;
	}
	if (q == checker[n + 3 * N])
		return (1);
	return (0);
}

void	ft_putchar(char g_hairetu[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			write(1, &g_hairetu[i][j], 1);
			if (j != N - 1)
				write(1, " ", 1);
			j++;
		}	
		write(1, "\n", 1);
		i++;
	}
}

int	fukusuchecker(char g_hairetu[N][N])
{
	int	i;
	int	j;
	int	kensa[N][N];

	cleaner(kensa);
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (kensa[i][g_hairetu[j][i] - '1'])
				return (0);
			else
				kensa[i][g_hairetu[j][i] - '1'] = 1;
			j++;
		}
		i++;
	}
	if (g_flag == 0)
	{
		ft_putchar(g_hairetu);
		g_flag = 1;
	}
	return (1);
}

void	cleaner(int kensa[N][N])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			kensa[i][j] = 0;
			j++;
		}
		i++;
	}
}
