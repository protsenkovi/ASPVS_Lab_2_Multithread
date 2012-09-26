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
		short this_proc = *(short*)(*(int*)((int)arg));
		char  *buf = (char*)(*(int*)((int)arg + 4));
		pthread_barrier_wait(&barrier_start);
		//printf("%s", buf);
		std::cout << "1 " << std::endl;
		pthread_mutex_lock(&mutex_cond_proc);
		while(cur_proc != THREAD_1) {
			pthread_cond_wait(&cond_proc, &mutex_cond_proc);
		}
		strcat(buf, "Thread#1 written down\n");
		cur_proc = this_proc + 1;
		pthread_cond_signal(&cond_proc);
		pthread_mutex_unlock(&mutex_cond_proc);
		return 0;
	}
}
