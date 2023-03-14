/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainfontaine <romainfontaine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:19:36 by rofontai          #+#    #+#             */
/*   Updated: 2022/11/13 20:38:35 by romainfonta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*FT_MEMCHR Recherche la première occurence de c dans s.
Nous devons aussi spécifier à la fonction la taille du bloc de mémoire
dans lequel réaliser la recherche.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*temp;

	if (!s)
		return (0);
	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == (char)c)
			return (&temp[i]);
		i++;
	}
	return (0);
}
