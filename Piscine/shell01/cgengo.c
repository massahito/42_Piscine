#include <stdio.h>

#define N 4
int check[N][N];

void ft_putchar(char hairetu[N][N]);

int hantei_yoko(char hairetu[N][N], char checker[4*N], int n)
{
	int p = 0, q = 0;
	int i = 0, x = 0, y = 0;

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
	if (p == checker[n] && q == checker[n+4])
		return 1;
	return 0;
}

int hake(char hairetu[N][N], char checker[4*N], int n, int m)
{
	int i;
	int j;

	if (n == N && m == N)
	{
		ft_putchar(hairetu);
		return 1;
	}
	if (m == N)
	{
		if (hantei_yoko(hairetu, checker, n))
			 hake(hairetu, checker, n+1, 0);
		return 0;
	}
	i = 0;
	while (i < N)
	{
		if(check[n][i] == 0)
		{
			check[n][i] = 1;
			hairetu[n][m] = i + '1';
			j = hake(hairetu, checker, n, m+1);
			check[n][i] = 0;
		}
		i++;
	}
	return 0;
}

void ft_putchar(char hairetu[N][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j=0; j < N; j++)
		{
			printf("%c ", hairetu[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
}
int main()
{
	char hairetu[N][N] = {};
	char checker[16] = {4,3,2,1,1,2,2,2};

	hake(hairetu, checker, 0, 0);
}