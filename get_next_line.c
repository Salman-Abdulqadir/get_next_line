/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulqa <sabdulqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:00:43 by sabdulqa          #+#    #+#             */
/*   Updated: 2023/03/04 16:30:32 by sabdulqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;

	read (fd, buffer, 5);
	
	return (buffer);
}
int	main()
{
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
	free(str);
	return 0;
}