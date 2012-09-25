#include <std.h>
#include <T2.h>
#include <Lab_2_Multithread.h>

namespace M_thread {
	pthread_attr_t thread_T2_init()
	{
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
		return attr;
	}

	void* thread_T2(void* arg)
	{
		pthread_barrier_wait(&barrier_start);
		return 0;
	}
}
