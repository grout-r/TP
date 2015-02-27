#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define NB_TRAIN  2

typedef struct s_train
{
  int	**train;
  int	i;
  pthread_mutex_t m;
}	       train;

void	print(int *train)
{
  int	i = 0;
  int	y = 0;
  puts("0123456789012345");
  while (i != NB_TRAIN)
    {
      while (y != 16)
	{
	  if (train[i] != y)
	    {
	      if (y > 5 && y < 10)
		printf("-");
	      else if ( y == 5 || y == 10)
		printf("|");
	      else
		printf("=");
	    }
	  else
	    printf("#");
	  y++;
	}
      printf("\n");
      y = 0;
      i++;
    }
  usleep(50000);
}

int	all_pass(int	*train)
{
  int	i = 0;

  while (i != NB_TRAIN)
    {
      if (train[i] != 16)
	return (0);
      i++;
    }
  return (1);
}

int	is_on_bridge(int	*train)
{
  int	i;
  while (i != NB_TRAIN)
    {
      if(train[i] > 5 && train[i] < 10)
	return (i);
      i++;
    }
  return (-1);
}
/*
  void	move(int	*train)
  {
  int	i = 0;
  int	on_bridge;

  on_bridge = is_on_bridge(train);
  if (on_bridge != -1)
  {
  train[on_bridge]++;
  }
  while (i != NB_TRAIN)
  {
  if (train[i] != 16)
  {
  train[i]++;
  return;
  }
  i++;
  }
  }
*/

void	move(train *me)
{
  int	i = 0;
  int	on_bridge;

  on_bridge = is_on_bridge(*(me->train));
  if (on_bridge != -1)
    {
      if (*(me->train)[me->i] + 1 < 5 && *(me->train)[me->i] != 16)
	*(me->train)[me->i]++;
    }
  if (*(me->train)[me->i] != 16)
    {
      *(me->train)[me->i]++;
      return;
    }
  i++;
}

int	main()
{
  int	trains[NB_TRAIN];
  int	i;
  pthread_t	thread1;
  train		train1;
  train		train2;

  train1.train = &trains;
  train1.i = 0;
  train1.PTHREAD_MUTEX_INITIALIZER;

  train2.train = &trains;
  train2.i = 1;
  train2.PTHREAD_MUTEX_INITIALIZER;


  while (i != NB_TRAIN)
    {
      train[i++] = 0;
    }
  while (all_pass(train) != 1)
    {
      system("clear");
      pthread_create(pthread_t * thread1, NULL , move , train1);
      pthread_create(pthread_t * thread2, NULL , move , train2);
      move(train);
      print(train);
    }
  return (0);
}
