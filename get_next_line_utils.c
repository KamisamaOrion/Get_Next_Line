/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:06:17 by mhervoch          #+#    #+#             */
/*   Updated: 2023/11/22 19:43:41 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeall(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
	return (NULL);
}

int	ft_no_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (*(s + i) && *(s + i) != '\n')
		i++;
	if (!(*(s + i)))
		return (1);
	return (0);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	int		c;

	c = 0;
	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char) c;
		i++;
	}
	return (s);
}

int	ft_strlen(char *buffer, char c)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i] != c && buffer[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*stk;
	long long unsigned	len;

	len = nmemb * size;
	if ((long long) nmemb == 0 || (long long) size == 0)
		return (malloc(1));
	if ((long long) nmemb < 0 || (long) size < 0 || len > __SIZE_MAX__)
		return (NULL);
	stk = malloc(nmemb * size);
	if (stk == NULL)
		return (NULL);
	stk = ft_bzero(stk, len);
	return (stk);
}
