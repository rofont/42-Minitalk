/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:53:09 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/14 09:10:38 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FT_STRCHR recherche la première occurrence du caractère passé (c)
dans la chaîne de caractères spécifique (s).*/
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	if (!s)
		return (0);
	i = 0;
	t = c;
	while (s[i] != t)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)&s[i]);
}
