/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:26:28 by anastruc          #+#    #+#             */
/*   Updated: 2024/03/07 11:06:01 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 4 functions needed, 1 to count the number of worlds separated by c,
one princpale ft split to return the main array of array. A third to crate and
fulfill the sub array. and a last one to free all the array of the the array of
array, and the array itself. */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

int	ft_countwords(char *str, char c)
{
	int	countwords;
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	countwords = 0;
	while (str[i])
	{
		if (str[i] != c && flag == 1)
		{
			countwords++;
			flag = 0;
		}
		else if (str[i] == c)
			flag = 1;
		i++;
	}
	return (countwords);
}

static char	*ft_fulfilltab(char *str, int start, int end, char **dest)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (end - start) + 1);
	if (!tab)
	{
		ft_free(dest);
		exit(0);
	}
	while (start < end)
	{
		tab[i] = str[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		start;
	char	**dest;

	i = 0;
	j = 1;
	if (!str)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_countwords(str, c) + 2));
	if (!dest)
		exit(0);
	while (i < ft_strlen(str))
	{
		if (str[i] && str[i] != c)
		{
			start = i;
			while (str[i] && str[i] != c)
				i++;
			dest[j++] = ft_fulfilltab(str, start, i, dest);
		}
		i++;
	}
	dest[j] = NULL;
	return (dest);
}

// int	main(void)
// {
// 	char	**tab;
// 	char	*str;

// 	str = "Je suis vivant";
// 	tab = ft_split(str, ' ');
// 	printf("%s\n", tab[0]);
// 	printf("%s\n", tab[1]);
// 	printf("%s\n", tab[2]);
// 	printf("%s\n", tab[3]);
// 	printf("%s\n", tab[4]);
// 	printf("%s\n", tab[5]);
// 	printf("%s\n", tab[6]);

// }

/* In the ft_spit function, I add an extra space for an empty tab
And I start j at 1. It's a trick to make the mai function of
the program more convenient. Like this the **dest act like argv and
leave an empty space in	i = 0 for the programme name.*/
