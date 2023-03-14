/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:05:36 by rofontai          #+#    #+#             */
/*   Updated: 2022/12/06 10:34:53 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*FT_LSTMAP itère sur la liste ’lst’ et applique la fonction ’f’au contenu
de chaque élément. Crée une nouvelle liste résultant des applications
successives de ’f’. La fonction ’del’ est là pour détruire
le contenu d’un élément si nécessaire.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*cont;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cont = ((*f)(lst->content));
		temp = ft_lstnew((cont));
		if (!temp)
		{
			ft_lstclear(&new, del);
			free(cont);
			return (new);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
