/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grim <grim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:35:07 by bbrunet           #+#    #+#             */
/*   Updated: 2020/06/23 18:18:43 by grim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_num(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str[i] == 0)
		return(1);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		// if (str[i] == 0)
		// 	return (count);
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

static int	ft_index(const char *str, char c, int **deb, int **fin)
{
	int i;
	int count;

	if (!(*deb = malloc((ft_num(str, c)) * sizeof(**deb))) ||
			!(*fin = malloc((ft_num(str, c)) * sizeof(**deb))))
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			(*deb)[count] = i;
			while (str[i] != c && str[i])
			{
				i++;
			}
			(*fin)[count] = i - 1;
			count++;
		}
	}
	return (0);
}

static char	*ft_strdub(const char *str, char c, int index)
{
	int		*deb;
	int		*fin;
	char	*ret;
	int		i;

	ft_index(str, c, &deb, &fin);
	if (!(ret = malloc((fin[index] - deb[index] + 2) * sizeof(*ret))))
		return (0);
	i = deb[index];
	while (i <= fin[index])
	{
		ret[i - deb[index]] = str[i];
		i++;
	}
	ret[i - deb[index]] = 0;
	free(deb);
	free(fin);
	return (ret);
}

static void	ft_free(char **ptab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(ptab[i]);
		i++;
	}
}

char		**ft_split(const char *s, char c)
{
	char	**ptab;
	int		num;
	int		i;

	if (s == 0)
		return (NULL);
	num = ft_num(s, c);
	if (!(ptab = malloc((num + 1) * sizeof(*ptab))))
		return (0);
	i = 0;
	while (i < num)
	{
		ptab[i] = ft_strdub(s, c, i);
		if (ptab[i] == NULL)
			ft_free(ptab, i);
		i++;
	}
	ptab[num] = 0;
	return (ptab);
}
// int main()
// {
// 	char **s;

// 	s = ft_split("abc", ' ');
// 	int i = 0;
// 	while (s[i])
// 	{
// 		printf("i: %d\n", i);
// 		printf("str: %s\n", s[i]);
// 		i++;
// 	}
// }