#ifndef		CLIENT_H
# define	CLIENT_H

# include   <stdio.h>
# include	<stdlib.h>
# include   <string.h>
# include   <unistd.h>
# include   <time.h>

# include   <sys/types.h>
# include   <sys/socket.h>
# include   <netinet/in.h>
# include   <arpa/inet.h>

# define    BACKG_WHI   "\x1b[48;5;7m"
# define    ASCII_RES   "\x1b[1;0m"
# define    BACK_YELLOW "\x1b[48;5;226m"
# define    BACK_ORANGE "\x1b[48;5;208m"
# define    BACK_RED    "\x1b[48;5;196m"
# define    PORT 		9999

int			print_chart(int *nums, int num);

#endif