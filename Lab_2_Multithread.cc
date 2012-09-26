#include <std.h>
#include <Lab_2_Multithread.h>
#include <T1.h>
#include <T2.h>

namespace M_thread {
	pthread_barrier_t barrier_start;
	pthread_mutex_t mutex_cond_proc;
	pthread_cond_t cond_proc;
	short cur_proc;
	char * buf;
}
/*printf("Value %i\n", *(short*)(*(int*)((int)arg)));
printf("Value %s\n", (char*)(*(int*)((int)arg + 4)));*/

void handler(int signo) {
	printf("Buffer: %s", M_thread::buf);
}

int main(int argc, char *argv[]) {
	int *arg_1 = (int*)malloc(2*sizeof(int));
	int *arg_2 = (int*)malloc(2*sizeof(int));
	M_thread::buf = (char*)malloc(30*sizeof(char));

	pthread_attr_t attr_T1 = M_thread::thread_T1_init();
	pthread_attr_t attr_T2 = M_thread::thread_T2_init();
	struct sigaction act;
	sigset_t set;

	pthread_barrier_init(&M_thread::barrier_start, NULL, 3);
	pthread_mutex_init(&M_thread::mutex_cond_proc, NULL);
	pthread_cond_init(&M_thread::cond_proc, NULL);
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	act.sa_flags = 0;
	act.sa_mask = set;
	act.sa_handler = &handler;
	sigaction(SIGUSR1, &act, NULL);

	*(int*)((int)arg_1) = (int)&M_thread::THREAD_1;
	*(int*)((int)arg_1 + 4) = (int)M_thread::buf;
	*(int*)((int)arg_2) = (int)&M_thread::THREAD_2;
	*(int*)((int)arg_2 + 4) = (int)M_thread::buf;
	pthread_create(NULL, &attr_T1, &M_thread::thread_T1, (void*)(arg_1));
	pthread_create(NULL, &attr_T2, &M_thread::thread_T2, (void*)(arg_2));

	sprintf(M_thread::buf, "Main started\n");
	M_thread::cur_proc = 1;
	pthread_barrier_wait(&M_thread::barrier_start);
	while(1) {
		pause();
	}
	return EXIT_SUCCESS;
}

