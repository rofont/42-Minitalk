/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:45 by rofontai          #+#    #+#             */
/*   Updated: 2022/11/14 09:06:51 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*FT_MEMCMP permet de comparer le contenu des deux blocs (s1 et s2).
n permet de spécifier le nombre d'octets sur lequel comparer les deux blocs.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!s1 || !s2)
		return (0);
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((temp1[i] > temp2[i]) || (temp1[i] < temp2[i]))
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
