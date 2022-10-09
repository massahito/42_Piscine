/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:39:34 by tkurosaw          #+#    #+#             */
/*   Updated: 2022/03/20 19:33:21 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define	N 4
int		g_check[N][N];
char	g_hairetu[N][N];
int		g_flag;

int		hantei_tate(char checker[4*N]);
int		hantei_yoko(char checker[4*N], int n);
int		hantei_yokom(char checker[4*N], int n);
int		fukusuchecker(char g_hairetu[N][N]);
void	hokomain(char checker[4*N], int n, int m, int i);

int	hoko(char g_hairetu[N][N], char checker[4*N], int n, int m)
{
	int	i;

	if (n == N && hantei_tate(checker))
	{
		fukusuchecker(g_hairetu);
		return (1);
	}
	if (m == N)
	{
		if (hantei_yoko(checker, n) && hantei_yokom(checker, n))
			hoko(g_hairetu, checker, n + 1, 0);
		return (1);
	}
	i = 0;
	while (i < N)
	{
		hokomain(checker, n, m, i);
		i++;
	}
	return (0);
}

void	hokomain(char checker[4*N], int n, int m, int i)
{
	if (g_check[n][i] == 0)
	{
		g_check[n][i] = 1;
		g_hairetu[n][m] = i + '1';
		hoko(g_hairetu, checker, n, m + 1);
		g_check[n][i] = 0;
	}
}

