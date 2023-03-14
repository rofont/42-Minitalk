/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:11:27 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/02 16:06:17 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FT_TOUPPER converti une lettre minuscule en une lettre majuscule.*/
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
