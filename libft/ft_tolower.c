/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:19:07 by romainfonta       #+#    #+#             */
/*   Updated: 2022/11/02 16:05:29 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*FT_TOLOWER converti une lettre majuscule à une lettre minuscule.*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
