#include <stdio.h>

#define	N 4
int		g_check[N][N];
char	g_hairetu[N][N];
int		g_flag;

int		hantei_tate(char checker[4*N]);
int		hantei_yoko(char checker[4*N], int n);
void	ft_putchar(char g_hairetu[N][N]);
int		fukusuchecker(char g_hairetu[N][N]);
void	hokomain(char checker[4*N], int n, int m, int i);


int	hantei_yoko(char checker[4*N], int n)
{
	int	p;
	int x;
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
	int y;
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
		if (p != checker[i] && q != checker[i + N])
			return (0);
		i++;
	}
	return (1);
}


int hoko(char g_hairetu[N][N], char checker[4*N], int n, int m)
{
	int i;

	if (n == N && hantei_tate(checker))
	{
		fukusuchecker(g_hairetu);
		return (1);
	}
	if (m == N)
	{
		if (hantei_yoko(checker, n)&&hantei_yokom(checker, n))
			 hoko(g_hairetu, checker, n+1, 0);
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


void hokomain(char checker[4*N], int n, int m, int i)
{
	if(g_check[n][i] == 0)
	{
		g_check[n][i] = 1;
		g_hairetu[n][m] = i + '1';
		hoko(g_hairetu, checker, n, m+1);
		g_check[n][i] = 0;
	}
}


void ft_putchar(char g_hairetu[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j=0; j < N; j++)
		{
			printf("%c ", g_hairetu[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int fukusuchecker(char g_hairetu[N][N])
{
	int i;
	int j;
	int kensa[N][N] = {};

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if(kensa[i][g_hairetu[j][i] - '1'])
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

int main()
{
	char checker[16] = {3, 1, 2, 2, 1, 3, 2, 2, 2, 2, 3, 1, 2, 2, 1, 3};

	hoko(g_hairetu, checker, 0, 0);
}
