/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainfontaine <romainfontaine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:00:09 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/13 20:50:16 by romainfonta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*FT_STRDUP alloue une nouvelle zone de mémoire via la fonction malloc
afin d'y copier la chaîne de caractères initiale (s1)*/
char	*ft_strdup(const char *s1)
{
	size_t		len_s;
	char		*dest;

	if (!s1)
		return (0);
	len_s = ft_strlen(s1) + 1;
	dest = (char *)malloc(len_s);
	if (dest == 0)
		return (0);
	return (ft_memcpy(dest, s1, len_s));
}
