/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:04:22 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/16 08:41:54 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FT_ISDIGIT permet de tester si un caractère est un chiffre ou non.*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
