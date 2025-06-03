/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:19:53 by rodantec          #+#    #+#             */
/*   Updated: 2024/10/25 17:08:13 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
		if (!new)
			return (NULL);
		return (new);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (len-- > 0 && s[start])
		new[i++] = (char)s[start++];
	new[i] = '\0';
	return (new);
}
