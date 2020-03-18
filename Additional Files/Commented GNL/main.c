/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:35:55 by mschempe          #+#    #+#             */
/*   Updated: 2018/07/02 12:59:47 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
// Include <fcntl.h> library for the filesystem functions *open* && *read*

int		main(int argc, char **argv)
{
	int		fd; //Variable to store the opened file
	char	*line; //Variable to store each read line from *get_next_line* function
	
	if (argc > 1) //Condition to check if a file or argument has been passed into the program
	{
		fd = open(argv[1], O_RDONLY); //Open the file passed into the argument and passes it into the *fd* variable

		//Loop to run *get_next_line* function while it returns 
		//a success of [(1) - Success] and not [(0) - Empty] or [(-1) - Error]
		while (get_next_line(fd, &line) > 0) //GNL Takes in the *fd* (FileDescriptor) & an address to *line* to store the line
		{
			ft_putendl(line); //Prints the *line* read from GNL
			free(line); //Free's the *line* that was printed to be ready for the next line to be read into it
		}
	}
	return (0);
}

