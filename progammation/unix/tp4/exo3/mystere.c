#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void mystere()
{
  int i, j, u, v;

  srandom(getpid());
  puts("DEBUT");

  u= random() % 30;
  for (i= 0; i< u; i++)
    {
      v= random() % 120;
      usleep(random() % 100000);
      for (j= 0; j < v; j++)
	printf("%c", '0'+random()%10);
      puts("");
    }
  puts("FIN");
}

  
