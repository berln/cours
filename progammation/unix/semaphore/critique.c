#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

void P(int sid, int num){
	struct sembuf op;
	op.sem_num=num;
	op.sem_op=+1;
	op.sem_flg=0;
	assert(semop(sid, &op,1)==0);
}
void V(int sid, int num){
	struct sembuf op;
	op.sem_num=num;
	op.sem_op=-1;
	op.sem_flg=0;
	assert(semop(sid, &op,1)==0);
}


int main(int argc, char const *argv[])
{
	printf("pid du programme %d\n",getpid() );
	printf("id du sema %d\n",atoi(argv[1]) );
	P(atoi(argv[1]),0);
	P(atoi(argv[1]),0);
	/*printf("pid %d \n",semop(argv[1],sempid,1));*/
	printf("pid du programme %d\n",getpid() );
	return 0;
}