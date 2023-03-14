/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainfontaine <romainfontaine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:26:10 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/13 20:47:14 by romainfonta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*FT_MEMSET permet de remplir de remplir b de len c*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*temp;

	if (!b)
		return (0);
	temp = b;
	i = 0;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}
