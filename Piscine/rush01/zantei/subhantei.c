#include <stdio.h>

#define	N 4
int	g_check[N][N];
int	g_flag;

void ft_putchar(char hairetu[N][N]);

int	hantei_yoko(char hairetu[N][N], char checker[4*N], int n)
{
	int	p = 0, q = 0;
	int	i = 0, x = 0, y = 0;

	while (i < N)
	{
		if (x < hairetu[n][i] - '0')
		{
			x = hairetu[n][i] - '0';
			p++;
		}
		if (y < hairetu[n][N - i - 1] - '0' )
		{
			y = hairetu[n][N - i - 1] - '0';
			q++;
		}
		i++;
	}
	if (p == checker[n + 2 * N] && q == checker[n + 3 * N])
		return (1);
	return (0);
}

int hantei_tate(char hairetu[N][N], char checker[4*N])
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
			if (x < hairetu[i][j] - '0')
			{
				x = hairetu[i][j] - '0';
				p++;
			}
			if (y < hairetu[N - i - 1][j] - '0' )
			{
				y = hairetu[N - i - 1][j] - '0';
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

int fukusuchecker(char hairetu[N][N])
{
	int i;
	int j;
	int kensa[N][N];

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if(kensa[i][hairetu[j][i] - '1'])
				return (0);
			else
				kensa[i][hairetu[j][i] - '1'] = 1;
			j++;
		}
		i++;
	}
	ft_putchar(hairetu);
	return (1);
}

void ft_putchar(char hairetu[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
			printf("%c ", hairetu[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
}
