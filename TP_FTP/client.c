
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  char			*ip;
  
  if (ac != 2)
    {
      puts("usage : ./binary ip");
      return (-1);
    }
  pe = getprotobyname("TCP");
  ip = av[1];
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(7272);
  s_in.sin_addr.s_addr = inet_addr(ip);

  if (!pe)
    {
      puts("Error when getting protocol by name");
      return (-1);
    }
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    {
      puts("Error when creating socket");
      return (-1);
    }
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      puts("connect failure");
      close (fd);
      return (-1);
    }
  //write(fd, "Hello ! \n", strlen("Hello ! \n"));
  char buf[42];
  read(fd, buf, 25);
  printf("%s\n", buf);
  if (close(fd) == -1)
    {
      puts("Error when closing socket");
    }
  return (0);
}
