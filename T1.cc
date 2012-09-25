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

	void* thread_T1(void** arg)
	{
		short this_proc = *(short*)arg[0];
		char  *buf = (char*)arg[1];
		pthread_barrier_wait(&barrier_start);
		pthread_mutex_lock(&mutex_cond_proc);
		while(cur_proc != THREAD_1) {
			pthread_cond_wait(&cond_proc, &mutex_cond_proc);
		}
		cur_proc = this_proc + 1;
		pthread_cond_signal(&cond_proc);
		pthread_mutex_unlock(&mutex_cond_proc);
		return 0;
	}
}
