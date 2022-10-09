#include <stdio.h>

#define	N 4
int	g_check[N][N];
int	g_flag;

int		hantei_tate(char hairetu[N][N], char checker[4*N]);
int		hantei_yoko(char hairetu[N][N], char checker[4*N], int n);
void	ft_putchar(char hairetu[N][N]);
int		fukusuchecker(char hairetu[N][N]);
void	hokomain(char hairetu[N][N], char checker[4*N], int n, int m, int i);

int hoko(char hairetu[N][N], char checker[4*N], int n, int m)
{
	int i;

	if (n == N && hantei_tate(hairetu, checker))
	{
		fukusuchecker(hairetu);
		return (1);
	}
	if (m == N)
	{
		if (hantei_yoko(hairetu, checker, n))
			 hoko(hairetu, checker, n+1, 0);
		return (1);
	}
	i = 0;
	while (i < N)
	{
		hokomain(hairetu, checker, n, m, i);
		i++;
	}
	return (0);
}


void hokomain(char hairetu[N][N], char checker[4*N], int n, int m, int i)
{
	if(g_check[n][i] == 0)
	{
		g_check[n][i] = 1;
		hairetu[n][m] = i + '1';
		hoko(hairetu, checker, n, m+1);
		g_check[n][i] = 0;
	}
}


int main()
{
	char hairetu[N][N] = {};
	char checker[16] = {3, 1, 2, 2, 1, 3, 2, 2, 2, 2, 3, 1, 2, 2, 1, 3};

	hoko(hairetu, checker, 0, 0);
}
