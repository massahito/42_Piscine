#include <stdio.h>

#define	N 4
int	g_check[N][N];
char g_hairetu[N][N];
int	g_flag;

int hantei_tate(char checker[4*N])
{
	int i = 0;
	int p, q, x, y, j;

	while (i < N)
	{
		j = 0;
		p = 0;
		q = 0;
		x = 0;
		y = 0;
		while (j < N)
		{
			if (x < g_hairetu[i][j] - '0')
			{
				x = g_hairetu[i][j] - '0';
				p++;
			}
			if (y < g_hairetu[N - i - 1][j] - '0' )
			{
				y = g_hairetu[N - i - 1][j] - '0';
				q++;
			}
			j++;
		}
		if (p != checker[i] && q != checker[i + 4])
			return (0);
		i++;
	}
	return (1);
}
