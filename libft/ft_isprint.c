/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:56:12 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/14 08:34:47 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FT_ISPRINT permet de tester si un caractère est imprimable ou non.*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
