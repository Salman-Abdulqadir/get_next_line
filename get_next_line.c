/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulqa <sabdulqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:00:43 by sabdulqa          #+#    #+#             */
/*   Updated: 2023/06/11 12:29:05 by sabdulqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_line(char *text)
{
	int	index;

	index = 0;
	while(text[index])
	{
		if (text[index] != '\n')
		{
			index++;
			continue;
		}
		return index;
	}
	return 0;
}

char	*get_next_line(int fd)
{
	static	char	*buffer;

	read (fd, buffer, BUFFER_SIZE);
	return (buffer);
}

int	main()
{
	printf("buffer size = %d\n\n", BUFFER_SIZE);
	int	fd;
	fd = open("test.txt", O_RDONLY);
	char *str;
	if (fd == -1)
	{
		printf("an error occured!");
		return 1;
	}
	str = get_next_line(fd);
	printf("%s", str);
	return 0;
}