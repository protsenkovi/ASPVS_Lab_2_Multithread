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

int main(int argc, char *argv[]) {
	std::cout << "Welcome to the QNX Momentics IDE!\n" << std::endl;
	M_thread::cur_proc = 0;
	int **arg = (int**)malloc(2*sizeof(int));
	char *buf = "Hello friend!";//(char*)malloc(30*sizeof(char));

	pthread_attr_t attr_T1 = M_thread::thread_T1_init();
	pthread_attr_t attr_T2 = M_thread::thread_T2_init();

	pthread_barrier_init(&M_thread::barrier_start, NULL, 3);
	pthread_mutex_init(&M_thread::mutex_cond_proc, NULL);
	pthread_cond_init(&M_thread::cond_proc, NULL);

	*(int**)((int)arg) = (int*)&M_thread::THREAD_1;
	*(int**)((int)arg + 4) = (int*)&M_thread::THREAD_2;

	printf("Value M_thread::THREAD_1): %i\n", M_thread::THREAD_1);
	printf("Value *&M_thread::THREAD_1): %i\n", *&M_thread::THREAD_1);
	printf("Value (int**)&M_thread::THREAD_1): %i\n", (int**)&M_thread::THREAD_1);
	printf("Value *(short*)&M_thread::THREAD_1): %i\n", *(short*)&M_thread::THREAD_1);
	printf("Value *(short*)(int**)&M_thread::THREAD_1: %i\n", *(short*)(int**)&M_thread::THREAD_1);

	printf("Value %i\n", (int**)&M_thread::THREAD_2);

	short v = 1, c = 2;
	int **m = (int**)malloc(2*sizeof(int));
	*(int**)((int)m) = (int*)&v;
	*(int**)((int)m + 4) = (int*)&c;
	printf("a[0]: %i, a[1]: %i\n", *(short*)(*(int**)((int)m)), *(short*)(*(int**)((int)m + 4)));

	int a;
	for(a = 0; a < 8; a++)
		std::cout << *(bool*)((int)arg + a) << " ";
	std::cout << std::endl;
	for(a = 0; a < 8; a+=4)
		std::cout << *(int**)((int)arg + a) << " ";
	std::cout << std::endl;
	printf("sizeof(arg): %i sizeof(*arg): %i sizeof(**arg): %i\n", sizeof(arg), sizeof(*arg),sizeof(**arg));
	printf("Value %i\n", *(short*)(*(int**)((int)arg))); //Example.
	printf("Value %i\n", *(short*)(*(int**)((int)arg + 4)));
	printf("Value %s\n", *(char*)(*(int*)(arg + 4)));
	std::cout << "Welcome to the QNX Momentics IDE!\n" << std::endl;
	//arg[1] = (int*)(buf);
	//pthread_create(NULL, &attr_T1, &M_thread::thread_T1, (void*)(arg));
	//arg[0] = (int*)2;
	//arg[1] = (int*)(buf);
	//pthread_create(NULL, &attr_T2, &M_thread::thread_T2, (void*)(arg));


	pthread_barrier_wait(&M_thread::barrier_start);

	//pthread_mutex_lock(&M_thread::cond_proc_mutex);

	return EXIT_SUCCESS;
}

