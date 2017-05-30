#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#include <alchemy/task.h>
#include <alchemy/timer.h>
#include <trank/rtdk.h>

void fonction_periodique (void * arg)
{
	int err;
	unsigned long depassements=0;
	int i;

	rt_task_set_periodic(rt_task_self(), TM_NOW,  500000000); /*tache de periode 0,5 sec*/
	rt_printf("[%lld] Timer programmé...\n", rt_timer_read());
	i = 0;
	while (1) {
		rt_task_wait_period(& depassements);
		rt_printf("[%lld]", rt_timer_read());
		if (depassements != 0)
			rt_printf(" Depassements : %lu", depassements);
		rt_printf("\n");
		i ++;
		i = i % 4;
		if (i == 0)
			rt_timer_spin(1000000000); /*durée de la tache supérieures à 1 sec*/
	}
	fprintf(stderr, "rt_task_wait_period(): %s\n",
				strerror(-err));
	exit(EXIT_FAILURE);
}



int main()
{
	RT_TASK task;

	mlockall(MCL_CURRENT|MCL_FUTURE);
	rt_print_auto_init(1);

	if (rt_task_spawn(& task, NULL, 0, 99,
	        T_JOINABLE, fonction_periodique, NULL) != 0) {
		fprintf(stderr, "Impossible de creer la tache\n");
		exit(EXIT_FAILURE);
	}

	rt_task_join(& task);
	return 0;
}


