#include <stdio.h>

#define	N 4
int	g_check[N][N];

int hoko(char hairetu[N][N], char checker[4*N], int n, int m);

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
