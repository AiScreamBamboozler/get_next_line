/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschempe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 17:30:06 by mschempe          #+#    #+#             */
/*   Updated: 2018/07/02 12:59:50 by mschempe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

//Returns a static int of *bytes* so that it holds the number of bytes read on each run of the function
static int	ft_getline(int fd, char **part) //Takes in the FileDescriptor and however much of the text you have already read
{
	char	*buff; // To store the line we are going to read
	char	*hold; // To hold the joined *part* and the line we are going to read 
	int		bytes; // Counter of the number of bytes we are reading with each *buff*
	
	// Allocates memory to the *buff* variable to store the line we are about to read(ln:25)
	if (!(buff = ft_strnew(sizeof(char) * BUFF_SIZE + 1))) // Also protection against a faulty malloc
		return (-1); // Return (-1) in the event of an error
	bytes = read(fd, buff, BUFF_SIZE); // Reads the FileDescriptor into the *buff* and returns the number of *bytes* read
	if (bytes > 0) // Condition to check whether any bytes were read from the file
	{
		buff[bytes] = '\0'; // Adds a NullTerminator to the end of the new string to close it off so we can work with it
		hold = ft_strjoin(*part, buff); // Combines the *part* we already have to the *buff* we have just read
		if (!hold) // Protection against if the *ft_strjoin* fucks out
			return (-1); // Returns (-1) in the event of the condition being true meaing the *ft_strjoin* fucked its shit
		free(*part); // Frees the *part* you had so you can replace it with your newly joined string (ln:33)
		*part = hold; // Replaces the *part* you took in as a parameter with the joined (ln:29) version of *part* and *buff*
	}
	free(buff); // Frees the variable *buff* that you first read into
	return (bytes); // Returns the number of bytes read so that you know which position you had stopped at
}

int			get_next_line(const int fd, char **line) //Takes in the FileDescriptor and a space to store the read line into
{
	static char	*str; // Static variable to store the read line into and keep whatever data was previously stored
	char		*endline; // Variable to keep postion of where the *getline* function has last stopped reading
	int			gl; // Variable to keep the number bytes read returned from the *getline* function

	// Mallocs space to the variable *str* 
	if ((!str && (str = ft_strnew(sizeof(*str))) == NULL) || !line) //Protects against a failed malloc and an empty *line* var
		return (-1); //Returns (-1) in the event of bad variable (space not allocated all proper)
	while (!(endline = ft_strchr(str, '\n'))) //Condition to make sure you aren't already at the end of line
	{
		if ((gl = ft_getline(fd, &str)) == 0) //Passes the FileDescriptor and the Malloc'd *str* var to the *getline* function
		{
			if (ft_strlen(str) == 0) //Checks if any data has been read into the *str* var
				return (0);			 //Returns (0) meaing nothing was in the file to be read
			str = ft_strjoin(str, "\n"); // Attachs a NewLine onto the read string
		}
		if (gl < 0) //Checks if the number of bytes read is less than 0
			return (-1); // Returns (-1) if no bytes were read
		else
			endline = ft_strchr(str, '\n'); //Moves the *endline* var to where the NewLine is found if some bytes were read
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(endline)); //Subtracts any rubbish data in the string after the NewLine
	endline = ft_strdup(endline + 1); //Moves the *endline* variable to the end of the last string
	free(str); //Frees the *str* variable
	str = endline; //Sets the free'd *str* variable to the position of the *endline*
	return (1); //Returns positive
}
