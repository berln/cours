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
