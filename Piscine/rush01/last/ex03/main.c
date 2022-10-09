/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:46:31 by marai             #+#    #+#             */
/*   Updated: 2022/03/20 19:33:51 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define N 4
int		g_check[N][N];
int		g_flag;
char	g_hairetu[N][N];

int	hoko(char g_hairetu[N][N], char checker[4*N], int n, int m);

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	hairetu[4 * N];

	i = 0;
	j = 0;
	while (j < 8 * N)
	{
		if (j % 2 == 0)
		{
			hairetu[i] = argv[1][j];
			i++;
		}
		j++;
	}
	hoko(g_hairetu, hairetu, 0, 0);
	if (g_flag == 0)
		write(1, "Error\n", 6);
	return (0);
}
