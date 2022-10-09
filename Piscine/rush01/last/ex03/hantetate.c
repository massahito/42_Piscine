/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hantetate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:35:56 by marai             #+#    #+#             */
/*   Updated: 2022/03/20 19:28:44 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define N 4
char	g_hairetu[N][N];
int		g_flag;

int		hantei_tateu(char checker[4*N], int m);
int		hantei_tates(char checker[4*N], int m);

int	hantei_tate(char checker[4*N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (0 == hantei_tateu(checker, i) || 0 == hantei_tates(checker, i))
			return (0);
		i++;
	}
	return (1);
}

int	hantei_tateu(char checker[4*N], int m)
{
	int	p;
	int	x;
	int	i;

	i = 0;
	p = 0;
	x = 0;
	while (i < N)
	{
		if (x < g_hairetu[i][m] - '0')
		{
			x = g_hairetu[i][m] - '0';
			p++;
		}
		i++;
	}
	if (p == checker[m] - '0')
		return (1);
	return (0);
}

int	hantei_tates(char checker[4*N], int m)
{
	int	q;
	int	y;
	int	i;

	i = 0;
	q = 0;
	y = 0;
	while (i < N)
	{
		if (y < g_hairetu[N - i - 1][m] - '0')
		{
			y = g_hairetu[N - i - 1][m] - '0';
			q++;
		}
		i++;
	}
	if (q == checker[m + N] - '0')
		return (1);
	return (0);
}
