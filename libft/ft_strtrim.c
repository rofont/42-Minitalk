/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainfontaine <romainfontaine@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:38:27 by rofontai          #+#    #+#             */
/*   Updated: 2022/11/13 20:54:37 by romainfonta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*FT_STRTRIM alloue de la memoire avec malloc et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés dans ’set’ au début et à
la fin de la chaîne de caractères.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		len_s1;
	char		*dest;

	i = 0;
	len_s1 = ft_strlen(s1);
	if (!len_s1)
		return (ft_strdup(s1));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len_s1 - 1] && ft_strchr(set, s1[len_s1 - 1]) && len_s1 > i)
		len_s1--;
	dest = malloc(sizeof(char) * (len_s1 - i + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, &s1[i], (len_s1 - i) + 1);
	return (dest);
}
