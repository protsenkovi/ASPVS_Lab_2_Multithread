#include <std.h>
#include <Lab_2_Multithread.h>
#include <T1.h>
#include <T2.h>

namespace M_thread {
	pthread_barrier_t barrier_start;

	int main(int argc, char *argv[]) {
		std::cout << "Welcome to the QNX Momentics IDE!" << std::endl;
		pthread_attr_t attr_T1 = thread_T1_init();
		pthread_attr_t attr_T2 = thread_T2_init();

		pthread_barrier_init(&barrier_start, NULL, 3);

		pthread_create(NULL, &attr_T1, &thread_T1, NULL);
		pthread_create(NULL, &attr_T2, &thread_T2, NULL);

		pthread_barrier_wait(&barrier_start);
		return EXIT_SUCCESS;
	}
}
