#include <std.h>
#include <Lab_2_Multithread.h>
#include <T1.h>
#include <T2.h>

namespace M_thread {
	pthread_barrier_t barrier_start;
	pthread_mutex_t mutex_cond_proc;
	pthread_cond_t cond_proc;
	short cur_proc;
}
/*printf("Value %i\n", *(short*)(*(int*)((int)arg)));
printf("Value %s\n", (char*)(*(int*)((int)arg + 4)));*/
int main(int argc, char *argv[]) {
	std::cout << "Welcome to the QNX Momentics IDE!\n" << std::endl;
	int *arg_1 = (int*)malloc(2*sizeof(int));
	int *arg_2 = (int*)malloc(2*sizeof(int));
	char *buf = (char*)malloc(30*sizeof(char));

	pthread_attr_t attr_T1 = M_thread::thread_T1_init();
	pthread_attr_t attr_T2 = M_thread::thread_T2_init();

	pthread_barrier_init(&M_thread::barrier_start, NULL, 3);
	pthread_mutex_init(&M_thread::mutex_cond_proc, NULL);
	pthread_cond_init(&M_thread::cond_proc, NULL);

	*(int*)((int)arg_1) = (int)&M_thread::THREAD_1;
	*(int*)((int)arg_1 + 4) = (int)buf;
	*(int*)((int)arg_2) = (int)&M_thread::THREAD_2;
	*(int*)((int)arg_2 + 4) = (int)buf;
	pthread_create(NULL, &attr_T1, &M_thread::thread_T1, (void*)(arg_1));
	pthread_create(NULL, &attr_T2, &M_thread::thread_T2, (void*)(arg_2));

	sprintf(buf, "Main started\n");
	M_thread::cur_proc = 1;
	pthread_barrier_wait(&M_thread::barrier_start);
	std::cout << "main " << std::endl;
	printf("Buffer: %s", buf);
	std::cout << "Welcome to the QNX Momentics IDE!\n" << std::endl;
	return EXIT_SUCCESS;
}

