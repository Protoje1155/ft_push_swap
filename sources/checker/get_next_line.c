/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:29:07 by mkoster           #+#    #+#             */
/*   Updated: 2024/03/26 16:29:08 by mkoster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_remaining_heap(char *heap)
{
	int		i;
	int		j;
	char	*new_heap;

	i = 0;
	if (ft_remaining_heap_extension(heap, &i) == 0)
	{
		free(heap);
		return (NULL);
	}
	j = i;
	while (heap[i])
		i++;
	new_heap = malloc(sizeof(char) * (i - j + 1));
	if (new_heap == NULL)
		return (NULL);
	i = 0;
	while (heap[j])
		new_heap[i++] = heap[j++];
	new_heap[i] = '\0';
	free(heap);
	return (new_heap);
}

char	*ft_get_line(char *heap)
{
	char	*line;
	int		i;
	int		nl_found;

	nl_found = 0;
	i = 0;
	while (heap[i] && heap[i] != '\n')
		i++;
	if (heap[i] == '\n')
		nl_found = 1;
	line = malloc(sizeof(char) * (i + 1 + nl_found));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (heap[i] && heap[i] != '\n')
	{
		line[i] = heap[i];
		i++;
	}
	if (nl_found)
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*add_to_stash(char *heap, char *buf, int *read_bytes)
{
	int		i;
	int		j;
	char	*new_heap;

	j = 0;
	i = 0;
	if (!buf)
		return (NULL);
	while (heap && heap[i])
		i++;
	new_heap = malloc(sizeof(char) * (*read_bytes + i + 1));
	if (new_heap == NULL)
		return (NULL);
	i = 0;
	while (heap && heap[i])
	{
		new_heap[i] = heap[i];
		i++;
	}
	while (buf[j] && j < *read_bytes)
		new_heap[i++] = buf[j++];
	new_heap[i] = '\0';
	free(heap);
	return (new_heap);
}

char	*read_and_stash(int fd, char *heap, int *read_bytes)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (!(ft_find_char(heap)))
	{
		*read_bytes = read(fd, buf, BUFFER_SIZE);
		if (*read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		if (*read_bytes == 0)
			break ;
		buf[*read_bytes] = '\0';
		heap = add_to_stash(heap, buf, read_bytes);
	}
	free(buf);
	return (heap);
}

char	*get_next_line(int fd)
{
	static char	*heap;
	int			read_bytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_bytes = 1;
	heap = read_and_stash(fd, heap, &read_bytes);
	if (heap == NULL)
		return (NULL);
	line = ft_get_line(heap);
	heap = ft_remaining_heap(heap);
	return (line);
}
