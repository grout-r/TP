
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int			handle_client(int client_fd, char const *client_ip)
{
  static const char * const welcome = " Welcome ! \n Your IP is : ";
  if ( write(client_fd, welcome, strlen(welcome)) ==  -1
       || write (client_fd, client_ip, strlen(client_ip)) == -1
       || write (client_fd, "\n", 1) == -1)
    return (-1);
  return (0);
}
 
int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			client_fd;
  char			*client_ip;
  pid_t			pid;

  pe = getprotobyname("TCP");
  
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(7272);
  s_in.sin_addr.s_addr = INADDR_ANY;

  s_in_size = sizeof(s_in_client);

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
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      puts("Error when bindin");
      close (fd);
      return (-1);
    }
  if (listen(fd, 42) == -1)
    {
      close (fd);
      return (-1);
    }
  while (42)
    {
      client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
      if (client_fd == -1)
	{
	  puts("accept failure");
	  return (-1);
	}
      client_ip = inet_ntoa(s_in_client.sin_addr);
      pid = fork ();
      if (pid == 0)
	{
	  write(1, client_ip, strlen(client_ip));
	  handle_client(client_fd, client_ip);
	  while (42);
	  exit (0);
	}
    }
  if (close(fd) == -1)
    {
      puts("Error when closing socket");
    }
  if (close(client_fd) == -1)
    {
      puts("Error when closing socket");
    }
  return (0);
}
