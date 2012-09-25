#include <std.h>
#include <T1.h>
#include <Lab_2_Multithread.h>

namespace M_thread {
	pthread_attr_t thread_T1_init()
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		return attr;
	}

	void* thread_T1(void* arg)
	{
		pthread_barrier_wait(&barrier_start);
		return 0;
	}
}
