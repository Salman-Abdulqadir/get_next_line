/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulqa <sabdulqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:20:38 by sabdulqa          #+#    #+#             */
/*   Updated: 2023/06/27 18:39:18 by sabdulqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*join(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

char	*read_file(int fd, char *file)
{
	char	*buffer;
	int		read_count;

	if (!file)
		file = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((size_t)(BUFFER_SIZE + 1), sizeof(char));
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
			break ;
		buffer[read_count] = '\0';
		file = join(file, buffer);
	}
	return (file);
}

char	*find_line(char *file)
{
	char	*line;
	int		i;

	if (!file[0])
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	line[i + 1] = '\0';
	if (!line)
		return (NULL);
	line = ft_memcpy(line, file, i + 1);
	return (line);
}

char	*find_remainder(char *file)
{
	char	*remainder;
	int		i;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	remainder = malloc(sizeof(char) * (ft_strlen(file) - i));
	remainder[ft_strlen(file) - i] = '\0';
	if (!remainder)
		return (NULL);
	remainder = ft_memcpy(remainder, file + i + 1, ft_strlen(file) - i);
	free(file);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE > 2147483647)
		return (NULL);
	file = read_file(fd, file);
	if (!file)
		return (NULL);
	line = find_line(file);
	file = find_remainder(file);
	return (line);
}

int	main()
{
	int        fd;
    char    *line;
    char    *line2;
    char    *line3;   
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL){
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	free(line);
	// free(line2);
	// free(line3);
    return (0);
}